cmake_minimum_required(VERSION 3.15)
project(Project4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project4
        main.cpp
        MyAVLTree.hpp
        proj4.cpp
        proj4.hpp
        runtimeexcept.hpp)
