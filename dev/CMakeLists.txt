cmake_minimum_required(VERSION 3.10)
project(tdd LANGUAGES CXX)

enable_testing()

include_directories(../prefix/include)

add_subdirectory(SimpleTest)
# tests_gt contains examples using gtest/gmock library
add_subdirectory(tests_gt)