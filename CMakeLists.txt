cmake_minimum_required(VERSION 3.24)
project(Dice)

set(CMAKE_CXX_STANDARD 23)

add_executable(Dice main.cpp DiceTable.cpp DiceTable.h)
