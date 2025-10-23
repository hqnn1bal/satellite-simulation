#pragma once
#include <cmath>

struct Coords {
	double lat_deg = 0.0;
	double long_deg = 0.0;
	double height_km = 0.0;

	Coords() = default;
	Coords(double lat, double long_d, double height) : lat_deg(lat), long_deg(long_d), height_km(height) {};
};

struct MagneticVector {
	double x_nT = 0.0;
	double y_nT = 0.0;
	double z_nT = 0.0;
	double F_nT = 0.0;

	MagneticVector() = default;
	MagneticVector(double x, double y, double z) : x_nT(x), y_nT(y), z_nT(z), F_nT(std::sqrt(x* x + y * y + z * z)) {};
};