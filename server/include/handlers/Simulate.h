#pragma once
#include "crow.h"
#include "ServerTypes.h"
#include <vector>

struct SimulationResults {
	std::vector<Frame> frames{};
	Decay decay{};
	Meta meta{};
};

class Simulator {
	
public:
	SimulationResults simulate(const std::string& line1, const std::string& line2, double start_epoch_ms, double duration, double step, double h_fail_km);
	crow::json::wvalue to_json(const SimulationResults& simres);
};