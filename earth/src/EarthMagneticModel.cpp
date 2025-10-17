#include "EarthMagneticModel.h"

EarthMagneticModel::EarthMagneticModel(std::unique_ptr<IEarthModel> model) : model_(std::move(model)) {};

MagneticVector EarthMagneticModel::getField(const Coords& coords, int year) const {
	return this->model_->calculate(coords, year);
}