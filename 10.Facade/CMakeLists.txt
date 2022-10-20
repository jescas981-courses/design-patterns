cmake_minimum_required(VERSION 3.13)
project(facade)

add_library(base INTERFACE)
target_compile_options(base INTERFACE -Wall)
target_compile_features(base INTERFACE cxx_std_14)

add_executable(handmade-flyweight src/handmade-flyweight.cpp)
target_link_libraries(handmade-flyweight PRIVATE base)

add_executable(boost-flyweight src/boost-flyweight.cpp)
target_link_libraries(boost-flyweight PRIVATE base)