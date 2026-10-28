#pragma once

#include <string>
#include <vector>

class MissionStateMachine {
public:
    enum class Phase {
        IDLE,
        PREPARING,
        EN_ROUTE,
        PICKUP,
        RETURN_HOME,
        DELIVERED,
        SAFE_HOLD
    };

    MissionStateMachine();

    void advance();
    Phase current() const;
    std::vector<std::string> actionsForCurrentPhase() const;

private:
    Phase phase_;
};
