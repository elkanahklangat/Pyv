#include "flight_controller.hpp"
#include "mission_state_machine.hpp"
#include "safety_monitor.hpp"

#include <iostream>

int main() {
    const FlightController controller("http://localhost:8000/mission/planning");
    MissionStateMachine state_machine;
    SafetyMonitor safety_monitor;

    const MissionTelemetry telemetry{
        42.0f,
        7.8f,
        72.0f,
        18.0f,
        620.0f,
        "Local Tea House"
    };

    const MissionDecision decision = controller.evaluateMission(telemetry);

    std::cout << "Route: " << decision.route << "\n";
    std::cout << "Mode: " << decision.mode << "\n";
    std::cout << "Confidence: " << decision.confidence << "\n";
    std::cout << "Wake window: " << decision.wake_window << "\n";

    for (const auto& action : decision.actions) {
        std::cout << "- " << action << "\n";
    }

    std::cout << "Current phase: " << static_cast<int>(state_machine.current()) << "\n";
    std::cout << "Safety state: "
              << static_cast<int>(safety_monitor.evaluate(telemetry.battery_pct, telemetry.wind_kph,
                                                       telemetry.altitude_m, telemetry.target_distance_m))
              << "\n";

    controller.publishTelemetry(telemetry);
    return 0;
}
