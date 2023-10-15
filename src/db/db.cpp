#include <iostream>
#include <fstream>
#include "ira_db.h"

using namespace ira;
DB::DB(const char *path)
{
    this->path = path;
    int code = sqlite3_open(path, &inner_db);
    if (code != SQLITE_OK)
    {
        throw code;
    }
}
DB::~DB()
{
    // TODO: implement ~DB
}