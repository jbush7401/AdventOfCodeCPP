cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the project name
project(AOC2021 VERSION 1.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# add the executable
add_executable(AOC2021 main.cpp
Day1/day1.cpp
Day2/day2.cpp
Day3/day3.cpp
Day4/day4.cpp
Day5/day5.cpp
Day6/day6.cpp
Day7/day7.cpp
Day8/day8.cpp
Day9/day9.cpp
Day10/day10.cpp
Day11/day11.cpp)




