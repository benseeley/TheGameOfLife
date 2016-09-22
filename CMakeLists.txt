cmake_minimum_required(VERSION 3.6)
project(benjaminseeley_assignment2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CellGrid.cpp CellGrid.h MapFileReader.cpp MapFileReader.h GameOfLife.cpp GameOfLife.h CellSimulation.cpp CellSimulation.h)
add_executable(benjaminseeley_assignment2 ${SOURCE_FILES})