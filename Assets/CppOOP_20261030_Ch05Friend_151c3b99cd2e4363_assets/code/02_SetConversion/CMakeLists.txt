cmake_minimum_required(VERSION 3.16)
project(02_SetConversion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(example Friends.cpp IntSet.cpp RealSet.cpp main.cpp)
