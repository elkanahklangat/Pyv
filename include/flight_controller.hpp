#pragma once

#include <string>
#include <vector>

struct MissionTelemetry {
    float altitude_m;
    float velocity_mps;
    float battery_pct;
    float wind_kph;
    float target_distance_m;
    std::string destination;
};

struct MissionDecision {
    std::string route;
    float confidence;
    std::string mode;
    std::vector<std::string> actions;
    std::string wake_window;
};

class FlightController {
public:
    explicit FlightController(std::string intelligence_api_url);

    MissionDecision evaluateMission(const MissionTelemetry& telemetry) const;
    void publishTelemetry(const MissionTelemetry& telemetry) const;

private:
    std::string intelligence_api_url_;
    float estimateRisk(const MissionTelemetry& telemetry) const;
};
