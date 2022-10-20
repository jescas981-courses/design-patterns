cmake_minimum_required(VERSION 3.11)
project(bridge)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)

add_executable(exercise src/exercise.cpp)
add_executable(bridge src/bridge.cpp)