set(TARGET_NAME "cmdproc")

add_library(${TARGET_NAME}
    src/CommandParser.cxx
)

target_include_directories(${TARGET_NAME} PUBLIC include )

add_subdirectory(test_gt)

#add_subdirectory(test_cxg)

#add_subdirectory(test_bst)