cmake_minimum_required(VERSION 3.14)
project(satellite-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(satellite-test test.cpp)
target_link_libraries(satellite-test PRIVATE satellite gtest_main)

include(GoogleTest)
gtest_discover_tests(satellite-test)