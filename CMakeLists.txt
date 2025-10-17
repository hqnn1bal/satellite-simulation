cmake_minimum_required(VERSION 3.14)
project(sat_sim)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(./external/GeographicLib)
add_subdirectory(./satellite)
add_subdirectory(./earth)