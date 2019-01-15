include(ExternalProject)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

ExternalProject_Add(CxxTest
    DOWNLOAD_DIR ${INSTALL_PATH}
    GIT_REPOSITORY https://github.com/CxxTest/cxxtest
    GIT_TAG 4.4
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

add_subdirectory(SimpleDemo)