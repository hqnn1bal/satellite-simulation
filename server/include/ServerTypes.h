#include <string>
#include "Types.h"

struct DecayInfo {
	bool crossed = false;
	std::string time_utc = "";
	double time_from_start_s = 0.0;
	double uncertainty_s = 0.0;

	DecayInfo() = default;
};

struct Decay {
	double threshold_km = 0;
	DecayInfo tle_forward;

	Decay() = default;
};

struct Meta {
	int points_returned = 0;
	int points_generated = 0;
	int skipped_frames = 0;
	std::string tle_epoche_utc = "";
	bool out_of_tle_epoch_window = false;

	Meta() = default;
};

struct Frame {
	double t_rel_s = 0;
	Coords coords{};
	MagneticVector mag_vec{};

	Frame() = default;
	Frame(double t, Coords coords, MagneticVector mag_vec) : t_rel_s(t), coords(coords), mag_vec(mag_vec) {}
};