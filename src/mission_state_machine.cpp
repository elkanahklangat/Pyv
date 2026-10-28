#include "mission_state_machine.hpp"

#include <map>
#include <vector>

MissionStateMachine::MissionStateMachine() : phase_(Phase::IDLE) {}

void MissionStateMachine::advance() {
    switch (phase_) {
        case Phase::IDLE: phase_ = Phase::PREPARING; break;
        case Phase::PREPARING: phase_ = Phase::EN_ROUTE; break;
        case Phase::EN_ROUTE: phase_ = Phase::PICKUP; break;
        case Phase::PICKUP: phase_ = Phase::RETURN_HOME; break;
        case Phase::RETURN_HOME: phase_ = Phase::DELIVERED; break;
        case Phase::DELIVERED: phase_ = Phase::SAFE_HOLD; break;
        case Phase::SAFE_HOLD: phase_ = Phase::SAFE_HOLD; break;
    }
}

MissionStateMachine::Phase MissionStateMachine::current() const {
    return phase_;
}

std::vector<std::string> MissionStateMachine::actionsForCurrentPhase() const {
    static const std::map<Phase, std::vector<std::string>> action_map = {
        {Phase::IDLE, {"wait for mission trigger"}},
        {Phase::PREPARING, {"arm vehicle", "check sensors", "verify route"}},
        {Phase::EN_ROUTE, {"navigate to restaurant", "monitor wind and obstacle risk"}},
        {Phase::PICKUP, {"confirm tea and food pickup", "land with safety margin"}},
        {Phase::RETURN_HOME, {"return home", "watch battery reserve"}},
        {Phase::DELIVERED, {"wake user", "deliver tea"}},
        {Phase::SAFE_HOLD, {"hold position", "evaluate failure state"}},
    };

    auto it = action_map.find(phase_);
    if (it == action_map.end()) {
        return {"default safe state"};
    }
    return it->second;
}
