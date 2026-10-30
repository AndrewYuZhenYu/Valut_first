cmake_minimum_required(VERSION 3.16)
project(01_PointDistance LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(example Point.cpp main.cpp)
