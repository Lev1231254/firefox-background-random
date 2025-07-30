cmake_minimum_required(VERSION 3.10.0)
project(background-randomizer-firefox VERSION 0.1.0 LANGUAGES C CXX)


add_executable(background-randomizer-firefox src/main.cpp src/editCSSFile.cpp src/randomPicName.cpp)

target_include_directories(background-randomizer-firefox PRIVATE include)