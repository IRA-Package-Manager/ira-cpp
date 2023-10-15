#ifndef DB_H
#define DB_H

#include <filesystem>

#include "sqlite3.h"

namespace ira
{
    const std::string DB_DESTINATION{static_cast<std::string>(getenv("HOME")) + "/.local/ira/db.sqlite3"};
    class DB
    {
    public:
        DB(const char *path);
        DB();
        ~DB();

    private:
        sqlite3 *inner_db;
        std::filesystem::path path;
    };

}
#endif // DB_H