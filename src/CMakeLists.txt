file(GLOB db_source ./db/*.cpp)
add_library(ira_db SHARED ${db_source})
target_link_libraries(ira_db PUBLIC sqlite3)

file(GLOB remote_source ./remote/*.cpp)
add_library(ira_remote SHARED ${remote_source})