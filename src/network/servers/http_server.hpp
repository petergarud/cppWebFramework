#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

#include "simple_server.hpp"
#include <string>
#include <fstream>
#include <unordered_map>

namespace pweb {

class Api;

class HttpServer : public SimpleServer {
private:
    // connection between client and server
    int conn_;
    char buffer[30000];
    std::string response_;
    std::fstream file_;
    std::unordered_map<std::string, std::string> files_;
    std::unordered_map<std::string, Api*> routes_;

    void acceptor() override;
    void handler() override;
    void responder() override;
public:
    HttpServer();
    HttpServer(int port, unsigned long ip_address, int bklg);
    void launch() override;
    void addApi(std::string route, Api* api);
};

} // end namespace pweb

#endif
