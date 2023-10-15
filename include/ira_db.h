#ifndef DB_H
#define DB_H

#include <filesystem>

#include "sqlite3.h"

namespace ira
{
    class DB
    {
    private:
        sqlite3 *inner_db;
        std::filesystem::path path;

    public:
        DB(const char *path);
        ~DB();
    };

}
#endif // DB_H