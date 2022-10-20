cmake_minimum_required(VERSION 3.2)
project(factories)

include_directories(include)

add_executable(motivation src/motivation.cpp)
add_executable(factory_method src/factory_method.cpp)
add_executable(factory src/factory.cpp)
add_executable(factory_inner src/factory_inner.cpp)
add_executable(factory_abstract src/factory_abstract.cpp)
add_executable(exercise src/exercise.cpp)