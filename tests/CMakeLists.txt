file(GLOB test_db_src db/*.cpp)
add_executable(test_ira_db ${test_db_src})
target_link_libraries(test_ira_db ira_db GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_ira_db)