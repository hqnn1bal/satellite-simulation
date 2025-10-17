cmake_minimum_required(VERSION 3.14)
project(earth)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(earth STATIC
  ./src/WMMModel.cpp
  ./src/EarthMagneticModel.cpp
)

file(COPY ${CMAKE_SOURCE_DIR}/data/magnetic/wmm2025.wmm
     DESTINATION ${CMAKE_BINARY_DIR}/earth)

file(COPY ${CMAKE_SOURCE_DIR}/data/magnetic/wmm2025.wmm.cof
     DESTINATION ${CMAKE_BINARY_DIR}/earth)

target_include_directories(earth PUBLIC include)
target_link_libraries(earth PUBLIC GeographicLib)

add_executable(earth_main main.cpp)
target_link_libraries(earth_main PRIVATE earth)
