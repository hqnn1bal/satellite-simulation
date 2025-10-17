#pragma once
#include "EarthMagneticModel.h"

class WMMModel : public IEarthModel {
public:
	MagneticVector calculate(const Coords& coords, int year) const override;
};