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

add_test(SimpleDemo test_SimpleDemo COMMAND test_SimpleDemo)

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