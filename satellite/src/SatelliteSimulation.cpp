#include "SatelliteSimulation.h"
#include "libsgp4/SGP4.h"
#include "libsgp4/Tle.h"
#include "libsgp4/CoordGeodetic.h"
#include "libsgp4/Eci.h"

constexpr double PI = 3.1415926535897932384626;

std::vector<Point> SatelliteSimulator::simulate(std::string& date, double start_epoch_ms, double duration_s, double step_s) const
{
	std::vector<Point> result{};

	libsgp4::Tle tle(this->name_, this->line1_, this->line2_);
	libsgp4::SGP4 sgp4(tle);

	date = tle.Epoch().ToString();

	for (double t = 0; t <= duration_s; t += step_s) {
		libsgp4::Eci eci = sgp4.FindPosition(t / 60.0);
		libsgp4::CoordGeodetic geo = eci.ToGeodetic();

		Point p;
		p.lat_deg = geo.latitude * 180.0 / PI;
		p.long_deg = geo.longitude * 180.0 / PI;
		p.height_km = geo.altitude / 1000.0;
		p.t_rel_s = t;
		result.push_back(p);
	}

	return result;
}
