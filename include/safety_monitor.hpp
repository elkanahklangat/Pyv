#pragma once

#include <string>

class SafetyMonitor {
public:
    enum class SafetyState {
        SAFE,
        CAUTION,
        CRITICAL
    };

    explicit SafetyMonitor(float battery_floor = 25.0f, float wind_floor = 20.0f);

    SafetyState evaluate(float battery_pct, float wind_kph, float altitude_m, float target_distance_m) const;
    std::string describe() const;

private:
    float battery_floor_;
    float wind_floor_;
};
