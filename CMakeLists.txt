cmake_minimum_required(VERSION 3.14)
project(sat_sim)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ASIO_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/asio/asio/include")
include_directories(${ASIO_INCLUDE_DIR})

set(CROW_USE_BOOST OFF)
set(CROW_BUILD_TESTS OFF)
set(CROW_BUILD_EXAMPLES OFF)

set(CROW_USE_ASIO_STANDALONE ON)

add_subdirectory(./external/crow)
add_subdirectory(./external/sgp4)
add_subdirectory(./external/googletest)
add_subdirectory(./external/GeographicLib)
add_subdirectory(./satellite)
add_subdirectory(./earth)
add_subdirectory(./server)