cmake_minimum_required(VERSION 3.14)
project(server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(server STATIC
    ./src/Server.cpp
    ./src/handlers/Simulate.cpp
)

target_include_directories(server PUBLIC 
        include
        ${CMAKE_SOURCE_DIR}/external/crow/include
)
target_link_libraries(server PRIVATE satellite)
target_link_libraries(server PRIVATE earth)

add_executable(server-main main.cpp)
target_link_libraries(server-main PRIVATE server)