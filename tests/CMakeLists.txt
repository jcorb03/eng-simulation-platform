file(GLOB TEST_SOURCES CONFIGURE_DEPENDS
    "*.cc"
)

add_executable(simulation_tests
    ${TEST_SOURCES}
)

target_link_libraries(simulation_tests
    PRIVATE
        simulation
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(simulation_tests)