# Autonomous Flying Vehicle Platform

Pyv is the physical and operational layer of the same autonomous mission architecture. It encapsulates the vehicle, control loops, trajectory behavior, and edge execution needed to fly, learn, and deliver in a dynamic environment.

## Mission and System Role

Pyv is designed around a specific human-centered mission: it leaves before the user wakes, navigates to a local restaurant or food point, gathers tea and prepared food, returns home, and wakes the user with the tea ready at the right time.

This is not a toy flight concept. It is a research-grade autonomous aerial delivery stack that blends low-level hardware control, mission planning, and adaptive behavior.

## Integrated Stack

The vehicle combines:

- Arduino for low-level interface control and sensor handling
- Raspberry Pi for local coordination and edge orchestration
- Jetson Nano for heavier compute workloads, vision processing, and model inference
- reinforcement-inspired learning loops for mission refinement
- TensorFlow and computer vision support from the connected aimodels intelligence layer

## System Architecture

```text
Vehicle / Control Layer
  ├─ propulsion and stabilization
  ├─ motor and power bus
  ├─ telemetry and safety monitors
  └─ flight state estimation
          │
          v
Sensor and Edge Layer
  ├─ IMU and environmental sensors
  ├─ camera and perception hardware
  ├─ route and target detection
  └─ local compute and signal processing
          │
          v
Intelligence Layer
  ├─ mission planning
  ├─ reinforcement and adaptive logic
  ├─ route optimization
  └─ mission decisioning
          │
          v
Operational Layer
  ├─ pickup target recognition
  ├─ return-to-home logic
  ├─ delivery timing
  └─ user wake sequence
```

## Software Design

The Pyv platform includes both embedded-style control logic and a higher-level mission runtime. It is intended to collaborate with the aimodels repository as a combined stack:

- aimodels = perception, learning, and planning
- Pyv = physical execution and flight behavior

## C++ Control Runtime

The vehicle platform includes a C++ control component that models mission state, safety constraints, and route decisions. This is the execution side of the autonomous mission stack.

The repository includes:

- `include/flight_controller.hpp`
- `src/flight_controller.cpp`
- `src/main.cpp`
- `CMakeLists.txt`

These files provide a structured starting point for implementing an autonomous flight controller that can communicate with the mission intelligence service.

## Example Mission Flow

1. begin pre-dawn mission sequence
2. read local route and target definitions
3. query mission intelligence for route confidence and risk state
4. stabilize and navigate toward restaurant / pickup zone
5. confirm landing or pickup conditions via vision and sensors
6. return to home base
7. deliver order and trigger wake-up sequence

## Learning and Adaptation

Pyv does not rely on perfect assumptions. It continuously learns from:

- route success and failure
- local wind and environmental variation
- landing-zone confidence
- target recognition reliability
- energy and battery constraints

This helps it adapt over time, becoming more reliable with repeated practice and reinforcement-style correction.

## Relationship with aimodels

The connected mission architecture is:

- Pyv commands the flight platform and hardware behavior
- aimodels evaluates the environment and makes strategy-aware decisions
- both participate in a feedback loop that improves performance over time

## Future Capability

The same architecture can later be expanded toward a more ambitious mission profile: autonomous system deployment in remote or hazardous locations, including material collection and long-duration autonomous operations beyond local delivery.

## Project Structure

```text
Pyv/
├── CMakeLists.txt
├── include/
│   └── flight_controller.hpp
├── src/
│   ├── flight_controller.cpp
│   └── main.cpp
├── README.md
└── sample.py
```

## Summary

Pyv is the embodied execution system behind the autonomous tea-delivery mission. It carries the intelligence, stabilizes the vehicle, interprets the environment, responds to uncertainty, and becomes increasingly capable through continuous operational learning.
