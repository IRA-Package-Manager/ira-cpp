file(GLOB test_db_src db/*.cpp)
add_executable(test_ira_db ${test_db_src})

find_package(SQLite3 REQUIRED)
target_include_directories(test_ira_db PUBLIC ${SQLITE3_INCLUDE_DIRS})
target_link_libraries(test_ira_db ira_db GTest::gtest_main ${SQLITE3_LIBRARIES})


file(GLOB test_remote_src remote/*.cpp)
add_executable(test_ira_remote ${test_remote_src})
find_package(CURL REQUIRED)
target_include_directories(test_ira_remote PUBLIC ${CURL_INCLUDE_DIRS})
target_link_libraries(test_ira_remote ira_remote GTest::gtest_main ${CURL_LIBRARIES})

include(GoogleTest)
gtest_discover_tests(test_ira_db)
gtest_discover_tests(test_ira_remote)