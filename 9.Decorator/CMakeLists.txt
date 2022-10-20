cmake_minimum_required(VERSION 3.13)
project(decorator)

add_library(base INTERFACE)
target_compile_options(base INTERFACE -Wall)
target_compile_features(base INTERFACE cxx_std_14)

add_executable(dynamic_decorator src/dynamic_decorator.cpp)
target_link_libraries(dynamic_decorator base)

add_executable(static_decorator src/static_decorator.cpp)
target_link_libraries(static_decorator base)

add_executable(functional_decorator src/functional_decorator.cpp)
target_link_libraries(functional_decorator base)

add_executable(exercise src/exercise.cpp )
target_link_libraries(exercise base)
