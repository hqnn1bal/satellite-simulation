#pragma once
#include "Types.h"
#include <memory>

class IEarthModel {
public:
	virtual ~IEarthModel() = default;
	virtual MagneticVector calculate(const Coords& coords, int year) const = 0;
};

class EarthMagneticModel {
private:
	std::unique_ptr<IEarthModel> model_;
public:
	explicit EarthMagneticModel(std::unique_ptr<IEarthModel> model);
	MagneticVector getField(const Coords& coords, int year) const;
};