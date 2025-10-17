#pragma once
#include <cmath>

struct Coords {
	double lat_deg;
	double long_deg;
	double height_km;
};

struct MagneticVector {
	double x_nT;
	double y_nT;
	double z_nT;
	double F_nT;

	MagneticVector(double x, double y, double z) : x_nT(x), y_nT(y), z_nT(z), F_nT(std::sqrt(x* x + y * y + z * z)) {};
};