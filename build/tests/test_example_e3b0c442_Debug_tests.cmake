add_test([=[ExampleTest.BasicTest]=]  [==[C:/Users/Joel/Documents/Visual Studio 2022/Projects/simulation-platform/build/tests/Debug/test_example.exe]==] [==[--gtest_filter=ExampleTest.BasicTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ExampleTest.BasicTest]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\Joel\Documents\Visual Studio 2022\Projects\simulation-platform\tests\test_example.cpp:3]==]
    WORKING_DIRECTORY [==[C:/Users/Joel/Documents/Visual Studio 2022/Projects/simulation-platform/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(test_example_TESTS [==[ExampleTest.BasicTest]==])
