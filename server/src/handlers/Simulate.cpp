#include "handlers/Simulate.h"
#include "SatelliteSimulation.h"
#include "WMMModel.h"
#include <chrono>
#include <sstream>

SimulationResults Simulator::simulate(const std::string& line1, const std::string& line2, double start_epoch_ms, double duration, double step, double h_fail_km) {
	SimulationResults res{};
	crow::json::wvalue::list frames;
	SatelliteSimulator sat(line1, line2);
	EarthMagneticModel earth{ std::make_unique<WMMModel>() };

	bool decay_crossed = false;
	double decay_time = 0.0;
	std::string simulate_date = "";

	auto sat_res = sat.simulate(simulate_date, start_epoch_ms, duration, step);
	std::tm tm = {};
	std::istringstream ss(simulate_date);
	ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
	std::time_t time = std::mktime(&tm);
	std::cerr << time;
	for (const auto& v : sat_res) {
		time += step;
		Coords coords{ v.lat_deg, v.long_deg, v.height_km };
		std::string year(simulate_date.begin(), simulate_date.begin() + 4);
		MagneticVector mag_vec = earth.getField(coords, std::stoi(year));

		res.frames.emplace_back(v.t_rel_s, coords, mag_vec);
		
		Decay decay{};
		decay.threshold_km = h_fail_km;
		res.decay = decay;
		if (!decay_crossed && coords.height_km < h_fail_km) {
			decay_crossed = true;
			decay.tle_forward.crossed = true;
			std::tm* newTm = std::localtime(&time);
			std::ostringstream result;
			result << std::put_time(newTm, "%Y-%m-%d %H:%M:%S");
			decay.tle_forward.time_utc = result.str();
			decay.tle_forward.time_from_start_s = v.t_rel_s;
			decay.tle_forward.uncertainty_s = step;
			res.decay = decay;
		}
	}

	res.meta.points_generated = res.frames.size();
	res.meta.points_returned = res.meta.points_generated;
	res.meta.skipped_frames = res.meta.points_generated - res.meta.points_returned;
	res.meta.tle_epoche_utc = simulate_date;
	res.meta.out_of_tle_epoch_window = sat_res[sat_res.size() - 1].t_rel_s >= 2592000 ? true : false;

	return res;
}

crow::json::wvalue Simulator::to_json(const SimulationResults& simres) {
	crow::json::wvalue root;

	crow::json::wvalue::list frames_list;
	for (const auto& f : simres.frames) {
		crow::json::wvalue frame;
		frame["t_rel_s"] = f.t_rel_s;
		frame["geo"]["lat_deg"] = f.coords.lat_deg;
		frame["geo"]["lon_deg"] = f.coords.long_deg;
		frame["geo"]["alt_km"] = f.coords.height_km;
		frame["mag"]["x_nT"] = f.mag_vec.x_nT;
		frame["mag"]["y_nT"] = f.mag_vec.y_nT;
		frame["mag"]["z_nT"] = f.mag_vec.z_nT;
		frame["mag"]["f_nT"] = f.mag_vec.F_nT;
		frames_list.push_back(std::move(frame));
	}

	root["frames"] = std::move(frames_list);

	root["decay"]["threshold_km"] = simres.decay.threshold_km;
	root["decay"]["tle_forward"]["crossed"] = simres.decay.tle_forward.crossed;
	root["decay"]["tle_forward"]["time_utc"] = simres.decay.tle_forward.time_utc;
	root["decay"]["tle_forward"]["time_from_start_s"] = simres.decay.tle_forward.time_from_start_s;
	root["decay"]["tle_forward"]["uncertainty_s"] = simres.decay.tle_forward.uncertainty_s;

	root["meta"]["points_returned"] = simres.meta.points_returned;
	root["meta"]["points_generated"] = simres.meta.points_generated;
	root["meta"]["skipped_frames"] = simres.meta.skipped_frames;
	root["meta"]["tle_epoch_utc"] = simres.meta.tle_epoche_utc;
	root["meta"]["out_of_tle_epoch_window"] = simres.meta.out_of_tle_epoch_window;

	return root;
}