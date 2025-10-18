#include "SatelliteSimulation.h"
#include <iostream>

int main() {
    SatelliteSimulator sim(
        "1 25544U 98067A   20344.52782528  .00001264  00000-0  29621-4 0  9992",
        "2 25544  51.6461  21.4681 0001764  87.4306  41.4052 15.49369324256464"
    );

    auto points = sim.simulate(0, 600, 60);
    for (auto& p : points) {
        std::cout << p.t_rel_s << "s: lat=" << p.lat_deg << ", lon=" << p.long_deg
            << ", alt=" << p.height_km << "km\n";
    }
}