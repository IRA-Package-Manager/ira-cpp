file(GLOB db_source ./db/*.cpp)
add_library(ira_db SHARED ${db_source})

find_package(SQLite3 REQUIRED)
include(CMakePrintHelpers)
include_directories(ira_db PUBLIC ${SQLite3_INCLUDE_DIRS})
target_link_libraries(ira_db LINK_PUBLIC ${SQLite3_LIBRARIES})

file(GLOB remote_source ./remote/*.cpp)
add_library(ira_remote SHARED ${remote_source})

find_package(CURL REQUIRED)
include_directories(ira_remote PUBLIC ${CURL_INCLUDE_DIRS})
target_link_libraries(ira_remote ${CURL_LIBRARIES} goremote pthread)