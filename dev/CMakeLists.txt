cmake_minimum_required(VERSION 3.10)
project(tdd LANGUAGES CXX)


set(CXXTEST_PATH "${CMAKE_PREFIX_PATH}/CxxTest/")
set(CXXTEST_CMAKE "${CXXTEST_PATH}/build_tools/cmake/CxxTest.cmake")

include ("${CXXTEST_CMAKE}")

enable_testing()

include_directories(${CMAKE_PREFIX_PATH}/include)
include_directories(${CXXTEST_PATH})

add_subdirectory(SimpleTest)
# tests_gt contains examples using gtest/gmock library
add_subdirectory(tests_gt)