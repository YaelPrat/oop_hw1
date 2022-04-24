cmake_minimum_required(VERSION 3.21)
project(oop_hw1)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop_hw1 main.cpp SARS_COV_2.cpp SARS_COV_2.h omicron.cpp omicron.h Alpha.cpp Alpha.h Delta.cpp Delta.h Simulation.cpp Simulation.h)
