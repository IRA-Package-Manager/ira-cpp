#include <gtest/gtest.h>
#include <string>
#include <filesystem>
#include "sqlite3.h"

#include "ira_db.h"

TEST(TestIraDB, TestMakeIndependantDB)
{
    // ---------------------------------------------
    //               INITIALISING
    // ---------------------------------------------
    std::filesystem::path test_destination{std::filesystem::current_path()};
    test_destination += "db.sqlite3";
    ira::DB db(test_destination.c_str());
    sqlite3 *temporary{};
    int code = sqlite3_open(test_destination.c_str(), &temporary);
    // --------------------------------------------
    //                 TESTING
    // --------------------------------------------
    ASSERT_FALSE(std::filesystem::exists(test_destination));
    EXPECT_EQ(code, 0);
    // --------------------------------------------
    //                CLEANING UP
    // --------------------------------------------
    sqlite3_close(temporary);
    std::filesystem::remove(test_destination);
}