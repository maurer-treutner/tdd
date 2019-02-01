#
# tests using google test
#
set(TEST_NAME "test_${TARGET_NAME}_gtest")

add_executable(${TEST_NAME}
    test_CommandParser.cxx
)

target_link_libraries(${TEST_NAME}
    ${TARGET_NAME}
    Threads::Threads
    ${GMOCK_LIBRARIES}
    ${GTEST_BOTH_LIBRARIES}
)

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} ${GTEST_FLAGS})
