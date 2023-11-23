#include <iostream>
#include <string>

#include "../../include/ira_db.hpp"
#include "../../include/ira_remotes.hpp"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "Not enough arguments" << std::endl;
        return -1;
    }
    std::string command = argv[1];
    if (command == "create_db")
    {
        if (argc == 2)
        {
            std::cerr << "Not enough arguments" << std::endl;
            return -1;
        }
        ira::DB db(argv[2]);
    }
    if (command == "run_server")
    {
        if (argc == 2)
        {
            std::cerr << "Not enough arguments" << std::endl;
            return -1;
        }
        int port = 3000;
        char *dir = argv[2];
        if (argc == 4)
        {
            port = atoi(argv[3]);
        }
        auto srv = ira::RemoteServer("", port);
        std::cout << srv.Serve(dir);
    }
}
