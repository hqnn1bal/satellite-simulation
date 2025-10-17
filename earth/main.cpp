#include "WMMModel.h"
#include <iostream>

int main() {
	try {
		Coords coords{ 51.6, 13.2, 500 };
		int year = 2025;
		EarthMagneticModel model{ std::make_unique<WMMModel>() };
		MagneticVector vec = model.getField(coords, year);
		std::cout << vec.x_nT << " " << vec.y_nT << " " << vec.z_nT << " " << vec.F_nT;
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
}