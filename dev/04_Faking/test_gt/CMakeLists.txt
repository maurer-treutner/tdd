#
# tests using google test
#
set(TEST_NAME "test_${TARGET_NAME}_gtest")

add_executable(${TEST_NAME}
    test_LoginService.cxx
)

target_link_libraries(${TEST_NAME}
    ${TARGET_NAME}
    Threads::Threads
    ${GTEST_BOTH_LIBRARIES}
)

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} ${GTEST_FLAGS})
