#include "ira_db.h"

using namespace ira;
DB::DB(const char *path)
{
    this->path = path;
    std::filesystem::path base = this->path.parent_path();
    if (!std::filesystem::exists(base))
    {
        std::filesystem::create_directories(base);
    }
    int code = sqlite3_open(path, &inner_db);
    if (code != SQLITE_OK)
    {
        throw code;
    }
}

DB::DB() : DB(DB_DESTINATION.c_str()) {}

DB::~DB()
{
    sqlite3_close(inner_db);
}