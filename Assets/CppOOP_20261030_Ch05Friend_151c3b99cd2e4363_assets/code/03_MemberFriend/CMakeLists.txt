cmake_minimum_required(VERSION 3.16)
project(03_MemberFriend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(example One.cpp Two.cpp main.cpp)
