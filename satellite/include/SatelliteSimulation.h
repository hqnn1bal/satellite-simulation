#pragma once
#include<string>
#include<vector>

struct Point {
	double lat_deg;
	double long_deg;
	double height_km;
	double t_rel_s;
};

class SatelliteSimulator {
private:
	std::string name_ = "";
	std::string line1_ = "";
	std::string line2_ = "";
public:
	SatelliteSimulator(const std::string& line1, const std::string& line2) :
		line1_(line1), line2_(line2) {};
	std::vector<Point> simulate(std::string& date,double start_epoch_ms, double duration_s, double step_s) const;
};