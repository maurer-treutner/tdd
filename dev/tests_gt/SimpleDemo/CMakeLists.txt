add_library(SimpleDemo
    src/romannumber.cxx
)

target_include_directories(SimpleDemo PUBLIC include )

add_executable(test_SimpleDemo
    test/test_romannumber.cxx
)

target_link_libraries(test_SimpleDemo
    SimpleDemo
    Threads::Threads
    ${GTEST_BOTH_LIBRARIES}
)

add_test(SimpleDemo test_SimpleDemo COMMAND test_SimpleDemo)