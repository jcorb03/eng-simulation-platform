add_executable(
    test_example
    test_example.cpp
)

target_link_libraries(
    test_example
    PRIVATE
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(test_example)