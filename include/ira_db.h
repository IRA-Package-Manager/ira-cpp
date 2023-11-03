#ifndef DB_H
#define DB_H

#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

#include "sqlite3.h"

namespace ira
{
    class DB
    {
    public:
        DB(const char *path);
        ~DB();

    protected:
        sqlite3 *innerDB;
        std::filesystem::path path;
    };

    class UserDB : public DB
    {
    public:
        static inline const std::string DESTINATION{static_cast<std::string>(getenv("HOME")) + "/.local/ira/db.sqlite3"};
        UserDB();

    private:
        UserDB(const char *path);
    };
    class SystemDB : public DB
    {
    public:
        static inline const std::string DESTINATION{"/etc/ira/db.sqlite3"};
        static inline const std::string PKGLIST{"/usr/share/ira-pkgs.list"};
        SystemDB();

    private:
        SystemDB(const char *path);
        
    };

};
#endif // DB_H