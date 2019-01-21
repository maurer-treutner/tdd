#
# tests using boost.test
#
set(TEST_NAME "test_${TARGET_NAME}_boost")

add_executable(${TEST_NAME}
    test_romannumber.cxx
)

target_link_libraries(${TEST_NAME}
    ${Boost_LIBRARIES}
    SimpleDemo
)

add_test(NAME ${TEST_NAME} COMMAND test_SimpleDemo_boost --report_level=detailed)