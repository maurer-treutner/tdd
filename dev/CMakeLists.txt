cmake_minimum_required(VERSION 3.7)
project(tdd LANGUAGES CXX)

#
# The following lines are required for GTest
#
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

#
# The following lines are required for GMock 
#
# since there is no find_package for GMock, we get the libname from GTEST info
get_filename_component(GTEST_LIB_DIR ${GTEST_LIBRARIES} DIRECTORY)
find_library(GMOCK_LIBRARIES gmock PATHS ${GTEST_LIB_DIR})


#
# The following lines are required for CxxTest
#
set(CXXTEST_PATH "${CMAKE_PREFIX_PATH}/CxxTest/")
set(CXXTEST_CMAKE "${CXXTEST_PATH}/build_tools/cmake/CxxTest.cmake")
include ("${CXXTEST_CMAKE}")
set(GTEST_FLAGS "--gtest_output=xml:${CTEST_REPORT_PATH}/")

#
# The following lines are required for boost.test
#
# Please note: boost is not installed as an external project in this repository
#   It has to be installed on the build system. Unter Debian/Ubuntu please type
#       > sudo apt-get install libboost-test-dev
#   Under Windows...
#
set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

enable_testing()

include_directories(${CMAKE_PREFIX_PATH}/include)
include_directories(${CXXTEST_PATH})

add_subdirectory(01_SimpleDemo)
add_subdirectory(02_Fixtures)
add_subdirectory(03_Stubs)
add_subdirectory(04_Faking)
add_subdirectory(05_Mocking)
# add_subdirectory(06_Exercise)