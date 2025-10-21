cmake_minimum_required(VERSION 3.14)

project(satellite)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(satellite STATIC
	./src/SatelliteSimulation.cpp
)

target_include_directories(satellite
    PUBLIC
        include
        ${CMAKE_SOURCE_DIR}/external/sgp4
)

target_link_libraries(satellite PUBLIC sgp4)

add_executable(satellite-main main.cpp)
target_link_libraries(satellite-main PRIVATE satellite)

add_subdirectory(test)