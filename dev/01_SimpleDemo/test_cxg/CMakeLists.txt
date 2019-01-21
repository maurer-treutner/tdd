#
# tests using CxxTest
#
set(TEST_NAME "test_${TARGET_NAME}_cxg")

cxx_test(${TEST_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/testsuite_romannumber.h
)

#target_include_directories(testsuite_romannumber PRIVATE include
#)

target_link_libraries(${TEST_NAME}
    SimpleDemo
)