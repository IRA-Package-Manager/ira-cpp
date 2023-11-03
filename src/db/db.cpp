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
    int code = sqlite3_open(path, &innerDB);
    if (code != SQLITE_OK)
    {
        throw code;
    }
}

UserDB::UserDB() : DB::DB(UserDB::DESTINATION.c_str())
{
}

SystemDB::SystemDB() : DB::DB(SystemDB::DESTINATION.c_str())
{
    std::filesystem::path base = static_cast<std::filesystem::path>(PKGLIST).parent_path();
    if (!std::filesystem::exists(base))
    {
        std::filesystem::create_directories(base);
    }
    std::ofstream pkgList;
    pkgList.close();
    int err = chmod(PKGLIST.c_str(), 0777);
    if (err != 0)
    {
        throw err;
    }
}

DB::~DB()
{
    sqlite3_close(innerDB);
}