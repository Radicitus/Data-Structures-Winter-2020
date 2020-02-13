cmake_minimum_required(VERSION 3.15)
project(Project3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project3
        main.cpp
        proj3.cpp
        proj3.hpp
        Wordset.cpp
        Wordset.hpp)
