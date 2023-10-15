#include <gtest/gtest.h>
#include <string>
#include <filesystem>
#include "sqlite3.h"

#include "ira_db.h"

TEST(TestIraDB, TestMakeIndependantDB)
{
    std::filesystem::path test_destination{std::filesystem::current_path()};
    test_destination += "/db.sqlite3";
    ira::DB db(test_destination.c_str());

    ASSERT_TRUE(std::filesystem::exists(test_destination));

    std::filesystem::remove(test_destination);
}