#ifndef DB_H
#define DB_H

#include "sqlite3.h"
namespace ira
{
    class DB
    {
    private:
        sqlite3 *inner_db;

    public:
        DB(const char *path);
        ~DB();
    };

}
#endif // DB_H