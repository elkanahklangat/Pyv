#include "safety_monitor.hpp"

#include <string>

SafetyMonitor::SafetyMonitor(float battery_floor, float wind_floor)
    : battery_floor_(battery_floor), wind_floor_(wind_floor) {}

SafetyMonitor::SafetyState SafetyMonitor::evaluate(float battery_pct,
                                                  float wind_kph,
                                                  float altitude_m,
                                                  float target_distance_m) const {
    if (battery_pct < battery_floor_ || wind_kph > wind_floor_ || altitude_m < 5.0f || target_distance_m < 20.0f) {
        return SafetyState::CRITICAL;
    }
    if (battery_pct < battery_floor_ + 10.0f || wind_kph > wind_floor_ - 5.0f) {
        return SafetyState::CAUTION;
    }
    return SafetyState::SAFE;
}

std::string SafetyMonitor::describe() const {
    return "monitoring flight envelope and mission safety";
}
