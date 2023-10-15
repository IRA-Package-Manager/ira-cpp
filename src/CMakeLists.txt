add_library(ira_db SHARED db/db.cpp)
target_include_directories(ira_db PUBLIC db)
target_link_libraries(ira_db sqlite3)