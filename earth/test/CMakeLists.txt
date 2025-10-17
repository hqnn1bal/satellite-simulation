cmake_minimum_required(VERSION 3.14)
project(earth-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(earth-test test.cpp)
target_link_libraries(earth-test PRIVATE earth gtest_main)

include(GoogleTest)
gtest_discover_tests(earth-test)

add_custom_command(TARGET earth-test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/data/magnetic/wmm2025.wmm
        $<TARGET_FILE_DIR:earth-test>/wmm2025.wmm)
add_custom_command(TARGET earth-test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/data/magnetic/wmm2025.wmm.cof
        $<TARGET_FILE_DIR:earth-test>/wmm2025.wmm.cof)

