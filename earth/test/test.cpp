#include <gtest/gtest.h>
#include "WMMModel.h"

/*
testing data getted from https://geomag.bgs.ac.uk/data_service/models_compass/wmm_calc.html
*/

TEST(WMMModelTest, BasicCheck) {
    EarthMagneticModel model{ std::make_unique<WMMModel>() };
    auto vec = model.getField({ 0.0, 0.0, 0.0 }, 2025);

    EXPECT_NEAR(std::abs(vec.x_nT), 1928, 100.0);
    EXPECT_NEAR(std::abs(vec.y_nT), 27521, 100.0);
    EXPECT_NEAR(std::abs(vec.z_nT), 16011, 100.0);
    EXPECT_NEAR(vec.F_nT, 31840, 100.0);
}


