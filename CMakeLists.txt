cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra -Wpedantic --pedantic-errors -s")

include_directories(doctest/doctest benchmark/include)

project(q)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

project(bench)

add_executable(bench bench.cpp)

target_link_libraries(bench benchmark)
