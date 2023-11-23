#include "../../include/ira_remotes.hpp"
#include "remote.h"

using namespace ira;
RemoteServer::RemoteServer(std::string host, int port)
{
    this->host = host;
    this->port = port;
}
RemoteServer::~RemoteServer() {}

int RemoteServer::Serve(std::filesystem::path dir)
{
    auto result = RemoteServe(const_cast<char *>(host.c_str()), port, const_cast<char *>(dir.c_str()));
    return result.r0;
}