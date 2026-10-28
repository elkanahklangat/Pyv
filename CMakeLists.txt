cmake_minimum_required(VERSION 3.16)
project(PyvFlightController LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pyv_flight
    src/main.cpp
    src/flight_controller.cpp
)

target_include_directories(pyv_flight PRIVATE ${CMAKE_SOURCE_DIR}/include)
