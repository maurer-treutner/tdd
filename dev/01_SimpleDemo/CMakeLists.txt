set(TARGET_NAME "SimpleDemo")

add_library(${TARGET_NAME}
    src/romannumber.cxx
)

target_include_directories(${TARGET_NAME} PUBLIC include )

add_subdirectory(test_gt)

add_subdirectory(test_cxg)

add_subdirectory(test_bst)