#include <gtest/gtest.h>
#include <string>
#include <filesystem>
#include "sqlite3.h"

#include "ira_db.h"

void backup()
{
    std::filesystem::copy(ira::DB_DESTINATION, ira::DB_DESTINATION + "_backup");
    std::filesystem::remove(ira::DB_DESTINATION);
}

void restore()
{
    if (std::filesystem::exists(ira::DB_DESTINATION))
    {
        std::filesystem::remove(ira::DB_DESTINATION);
    }
    std::string backup_file = ira::DB_DESTINATION + "_backup";
    std::filesystem::copy(backup_file, ira::DB_DESTINATION);
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

TEST(TestIraDB, TestMakeUserDependantDB)
{
    // Making backup
    bool has_backup = false;
    if (std::filesystem::exists(ira::DB_DESTINATION))
    {
        backup();
    }
    ira::DB db;
    std::string homedir = getenv("HOME");
    EXPECT_TRUE(std::filesystem::exists(homedir + "/.local/ira/db.sqlite3"));

    if (has_backup)
    {
        restore();
    }
}