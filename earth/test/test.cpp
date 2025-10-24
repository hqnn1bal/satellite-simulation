#include <gtest/gtest.h>
#include "WMMModel.h"

/*
testing data getted from https://geomag.bgs.ac.uk/data_service/models_compass/wmm_calc.html
*/

TEST(WMMModelTest, BasicCheck1) {
    EarthMagneticModel model{ std::make_unique<WMMModel>() };
    auto vec = model.getField({ 0.0, 0.0, 0.0 }, 2025);

    EXPECT_NEAR(std::abs(vec.x_nT), 1928, 1000.0);
    EXPECT_NEAR(std::abs(vec.y_nT), 27521, 1000.0);
    EXPECT_NEAR(std::abs(vec.z_nT), 16011, 1000.0);
    EXPECT_NEAR(vec.F_nT, 31840, 1000.0);
}

TEST(WMMModelTest, BasicCheck2) {
    EarthMagneticModel model{ std::make_unique<WMMModel>() };
    auto vec = model.getField({ 13.0, 65.0, 500.0 }, 2025);

    EXPECT_NEAR(std::abs(vec.x_nT), 465, 1000.0);
    EXPECT_NEAR(std::abs(vec.y_nT), 37979, 1000.0);
    EXPECT_NEAR(std::abs(vec.z_nT), 10284, 1000.0);
    EXPECT_NEAR(vec.F_nT, 39347, 1000.0);
}

TEST(WMMModelTest, BasicCheck3) {
    EarthMagneticModel model{ std::make_unique<WMMModel>() };
    auto vec = model.getField({43.6, 23.2, 33.3}, 2025);

    EXPECT_NEAR(std::abs(vec.x_nT), 2275, 1000.0);
    EXPECT_NEAR(std::abs(vec.y_nT), 23065, 1000.0);
    EXPECT_NEAR(std::abs(vec.z_nT), 41593, 1000.0);
    EXPECT_NEAR(vec.F_nT, 47561, 1000.0);
}

TEST(WMMModelTest, BasicCheck4) {
    EarthMagneticModel model{ std::make_unique<WMMModel>() };
    auto vec = model.getField({ 66.6, 66.6, 66.6 }, 2025);

    EXPECT_NEAR(std::abs(vec.x_nT), 3758, 1000.0);
    EXPECT_NEAR(std::abs(vec.y_nT), 9495, 1000.0);
    EXPECT_NEAR(std::abs(vec.z_nT), 57138, 1000.0);
    EXPECT_NEAR(vec.F_nT, 57936, 1000.0);
}

TEST(WMMModelTest, BasicCheck5) {
    EarthMagneticModel model{ std::make_unique<WMMModel>() };
    auto vec = model.getField({ 12.9, 88.8, 22.0 }, 2025);

    EXPECT_NEAR(std::abs(vec.x_nT), 693, 1000.0);
    EXPECT_NEAR(std::abs(vec.y_nT), 40814, 1000.0);
    EXPECT_NEAR(std::abs(vec.z_nT), 10166, 1000.0);
    EXPECT_NEAR(vec.F_nT, 42061, 1000.0);
}