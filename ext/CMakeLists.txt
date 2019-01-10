cmake_minimum_required(VERSION 3.10)
include(ExternalProject)

ExternalProject_Add(GoogleTest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.8.0
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${INSTALL_PATH} -G ${CMAKE_GENERATOR}
)