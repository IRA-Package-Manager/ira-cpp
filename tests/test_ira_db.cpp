#include "sqlite3.h"
#include <filesystem>
#include <gtest/gtest.h>
#include <string>

#include "ira_db.h"

void backup()
{
    std::filesystem::copy(ira::UserDB::DESTINATION,
                          ira::UserDB::DESTINATION + "_backup");
    std::filesystem::remove(ira::UserDB::DESTINATION);
}

void restore()
{
    if (std::filesystem::exists(ira::UserDB::DESTINATION))
    {
        std::filesystem::remove(ira::UserDB::DESTINATION);
    }
    std::string backup_file = ira::UserDB::DESTINATION + "_backup";
    std::filesystem::copy(backup_file, ira::UserDB::DESTINATION);
    std::filesystem::remove(backup_file);
}

TEST(TestIraDB, TestMakeIndependantDB)
{
    std::filesystem::path test_destination{std::filesystem::current_path()};
    test_destination += "/db.sqlite3";
    ira::DB db(test_destination.c_str());

    ASSERT_TRUE(std::filesystem::exists(test_destination));

    std::filesystem::remove(test_destination);
}

TEST(TestIraDB, TestMakeUserDB)
{
    // Making backup
    bool has_backup = false;
    if (std::filesystem::exists(ira::UserDB::DESTINATION))
    {
        backup();
        has_backup = true;
    }
    ira::UserDB db;
    EXPECT_TRUE(std::filesystem::exists(db.DESTINATION));
    if (has_backup)
    {
        restore();
    }
}