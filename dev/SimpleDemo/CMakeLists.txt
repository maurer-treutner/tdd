add_library(SimpleDemo
    src/romannumber.cxx
)

target_include_directories(SimpleDemo PUBLIC include )

#
# tests using google test
#

add_executable(test_SimpleDemo
    test_gt/test_romannumber.cxx
)

target_link_libraries(test_SimpleDemo
    SimpleDemo
    Threads::Threads
    ${GTEST_BOTH_LIBRARIES}
)

add_test(NAME test_SimpleDemo COMMAND test_SimpleDemo)


#
# tests using CxxTest
#

cxx_test(testsuite_romannumber 
    ${CMAKE_CURRENT_SOURCE_DIR}/test_cxg/testsuite_romannumber.h
)

target_include_directories(testsuite_romannumber PRIVATE include
)

target_link_libraries(testsuite_romannumber
    SimpleDemo
)

#
# tests using boost.test
#
add_executable(test_SimpleDemo_boost
    test_bst/test_romannumber.cxx
)

target_include_directories(test_SimpleDemo_boost
    PRIVATE include
)

target_link_libraries(test_SimpleDemo_boost
    ${Boost_LIBRARIES}
    SimpleDemo
)

add_test(NAME test_SimpleDemo_boost COMMAND test_SimpleDemo_boost --report_level=detailed)