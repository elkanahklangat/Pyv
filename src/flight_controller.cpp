#include "flight_controller.hpp"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

FlightController::FlightController(std::string intelligence_api_url)
    : intelligence_api_url_(std::move(intelligence_api_url)) {}

float FlightController::estimateRisk(const MissionTelemetry& telemetry) const {
    float risk = 0.0f;
    if (telemetry.wind_kph > 20.0f) risk += 0.22f;
    if (telemetry.battery_pct < 25.0f) risk += 0.20f;
    if (telemetry.target_distance_m > 1500.0f) risk += 0.10f;
    if (telemetry.velocity_mps > 9.0f) risk += 0.12f;
    return std::min(risk, 0.90f);
}

MissionDecision FlightController::evaluateMission(const MissionTelemetry& telemetry) const {
    const float risk = estimateRisk(telemetry);

    MissionDecision decision;
    decision.route = (risk < 0.35f) ? "direct-route" : "safe-corridor";
    decision.confidence = (risk < 0.35f) ? 0.89f : 0.77f;
    decision.mode = (risk < 0.35f) ? "adaptive" : "conservative";
    decision.wake_window = "05:30 - 06:10";

    decision.actions.push_back("verify landing zone");
    decision.actions.push_back("confirm target acquisition");
    decision.actions.push_back("maintain safe battery reserve");

    if (risk > 0.35f) {
        decision.actions.push_back("increase altitude buffer");
        decision.actions.push_back("delay low-altitude approach");
    }

    return decision;
}

void FlightController::publishTelemetry(const MissionTelemetry& telemetry) const {
    std::ostringstream payload;
    payload << "{"
            << "\"altitude_m\":" << telemetry.altitude_m << ","
            << "\"velocity_mps\":" << telemetry.velocity_mps << ","
            << "\"battery_pct\":" << telemetry.battery_pct << ","
            << "\"wind_kph\":" << telemetry.wind_kph << ","
            << "\"target_distance_m\":" << telemetry.target_distance_m << ","
            << "\"destination\":\"" << telemetry.destination << "\""
            << "}";

    const std::string command =
        "curl -s -X POST '" + intelligence_api_url_ + "' "
        "-H 'Content-Type: application/json' "
        "-d '" + payload.str() + "' > /dev/null 2>&1";

    std::cout << "Publishing telemetry to intelligence service...\n";
    std::system(command.c_str());
}
