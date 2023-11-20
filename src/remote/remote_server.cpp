#include "../../include/ira_remotes.hpp"

using namespace ira;
RemoteServer::RemoteServer(std::string host, int port)
{
    this->host = host;
    this->port = port;
}
RemoteServer::~RemoteServer() {}