cmake_minimum_required(VERSION 3.20)

# Project name
project(advent_day01)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable
add_executable(advent_day01 main.cpp rotation_data.hpp)
