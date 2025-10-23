#pragma once
#include "Server.h"
#include "handlers/Simulate.h"

void Server::run(int port) {
	crow::SimpleApp app;

	CROW_ROUTE(app, "/health")
	([] {
		return "OK";
	});

	CROW_ROUTE(app, "/simulate").methods("POST"_method)
	([](const crow::request& req) -> crow::response {
		auto json = crow::json::load(req.body);
		if (!json) return crow::response(400, "INVALID JSON");

		auto line1 = json["tle"]["line1"].s();
		auto line2 = json["tle"]["line2"].s();

		double duration = json["duration_s"].d();
		double step = json["step_s"].d();
		double start_epoch_ms = json["start_epoch_ms"].d();
		double h_fail_km = json["h_fail_km"].d();

		Simulator simulator;

		auto simres = simulator.simulate(line1, line2, start_epoch_ms, duration, step, h_fail_km);

		auto res = simulator.to_json(simres);

		return crow::response(res);
	});

	app.port(port).multithreaded().run();
}
