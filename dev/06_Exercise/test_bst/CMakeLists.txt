#
# tests using boost.test
#
set(TEST_NAME "test_${TARGET_NAME}_boost")

add_executable(${TEST_NAME}
    test_Fraction.cxx
)

target_link_libraries(${TEST_NAME}
    ${Boost_LIBRARIES}
    frac
)

add_test(NAME ${TEST_NAME} COMMAND test_${TARGET_NAME}_boost --report_level=detailed)