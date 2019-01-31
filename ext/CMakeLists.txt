cmake_minimum_required(VERSION 3.7)
include(ExternalProject)

ExternalProject_Add(GoogleTest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.8.0
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${INSTALL_PATH} -G ${CMAKE_GENERATOR}
)

ExternalProject_Add(CxxTest
    GIT_REPOSITORY https://github.com/CxxTest/cxxtest
    GIT_TAG 4.4
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND cp -rf "../CxxTest" "${INSTALL_PATH}/CxxTest" 
)              