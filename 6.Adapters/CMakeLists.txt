cmake_minimum_required(VERSION 3.11)
project(adapters VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()


find_package(Qt5 REQUIRED COMPONENTS Core Widgets )

add_executable(adapters src/main.cpp src/mainwindow.cpp include/mainwindow.h)
target_link_libraries(adapters Qt5::Widgets)
target_include_directories(adapters PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_features(adapters PRIVATE cxx_std_11)