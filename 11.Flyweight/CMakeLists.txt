cmake_minimum_required(VERSION 3.24)
project(flyweight)

add_library(base INTERFACE)
target_compile_options(base INTERFACE -Wall -pedantic)
target_compile_features(base INTERFACE cxx_std_11)

add_executable(handmade-flyweight src/handmade-flyweight.cpp)
target_link_libraries(handmade-flyweight PRIVATE base)

add_executable(boost-flyweight src/boost-flyweight.cpp)
target_link_libraries(boost-flyweight PRIVATE base)

add_executable(text-formatting src/text-formatting.cpp)
target_link_libraries(text-formatting PRIVATE base)

add_executable(exercise src/exercise.cpp)
target_link_libraries(exercise PRIVATE base)