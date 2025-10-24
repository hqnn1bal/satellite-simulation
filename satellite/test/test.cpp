#include <gtest/gtest.h>
#include "SatelliteSimulation.h"

constexpr double PI = 3.1415926535897932384626;
constexpr double R = 6371.0;

struct Position {
    double lat;  
    double lon;  
    double alt;
    Position(double lat, double lon, double alt) : lat(lat), lon(lon), alt(alt) {};
};

double d(const Position& p1, const Position& p2) {
    double phi1 = p1.lat * PI / 180.0;
    double phi2 = p2.lat * PI / 180.0;
    double lambda1 = p1.lon * PI / 180.0;
    double lambda2 = p2.lon * PI / 180.0;

    double cos_c = sin(phi1) * sin(phi2) + cos(phi1) * cos(phi2) * cos(lambda2 - lambda1);
    if (cos_c > 1.0) cos_c = 1.0;
    if (cos_c < -1.0) cos_c = -1.0;

    double c = acos(cos_c);
    double r_avg = (R + p1.alt + R + p2.alt) / 2.0;
    return r_avg * c;  
}

TEST(SatelliteSimulatorTest, BasicCheck1) {
    SatelliteSimulator simulator(
        "1 25544U 98067A   20344.52782528  .00001264  00000-0  29621-4 0  9992",
        "2 25544  51.6461  21.4681 0001764  87.4306  41.4052 15.49369324256464"
    );

    std::string date = "";
    int dt = 60;
    auto res = simulator.simulate(date, 0, 600, 60);
    for (int i = 1; i < res.size(); ++i) {
        Position p1{ res[i].lat_deg, res[i].long_deg, res[i].height_km };
        Position p2{ res[i - 1].lat_deg, res[i - 1].long_deg, res[i - 1].height_km };
        EXPECT_NEAR(d(p1, p2) / dt , 7.5, 1.0);
    }
}