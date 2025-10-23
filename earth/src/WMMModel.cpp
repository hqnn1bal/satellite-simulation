#include "WMMModel.h"
#include <iostream>
#include "GeographicLib/MagneticModel.hpp"
#include <filesystem>

MagneticVector WMMModel::calculate(const Coords& coords, int year) const {
	//std::string wmm_path = std::filesystem::absolute("../../data/magnetic").string();
	GeographicLib::MagneticModel model("wmm2025");
	double Bx, By, Bz;
	model(year, coords.lat_deg, coords.long_deg, coords.height_km, Bx, By, Bz);

	return MagneticVector{ Bx, By, Bz };
}