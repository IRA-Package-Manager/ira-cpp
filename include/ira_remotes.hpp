#ifndef IRA_REMOTE_H
#define IRA_REMOTE_H

#include <string>
#include <filesystem>

namespace ira
{
    class RemoteServer
    {
    public:
        RemoteServer(std::string host, int port);
        ~RemoteServer();
        int Serve(std::filesystem::path dir);

    private:
        std::string host;
        int port;
    };

    class Remote
    {
    public:
        Remote(std::string name, std::string origin);
        ~Remote();

    private:
        std::string name;
    };
} // namespace ira

#endif