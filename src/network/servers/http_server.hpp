#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

#include "simple_server.hpp"
#include <string>
#include <fstream>
#include <unordered_map>
#include "../apis/pweb_lib_apis.hpp"

namespace pweb {

class HttpServer : public SimpleServer {
private:
    // connection between client and server
    int conn_;
    std::string request_;
    std::string response_;
    std::fstream file_;
    std::unordered_map<std::string, Api*> routes_;
    Api default_api_;

    void acceptor() override;
    void handler() override;
    void responder() override;
    std::string retrieveMethod();
    std::string retrievePath();
    std::string retrieveBody();
    Api* getApi(std::string path);
    std::string getBasePath(std::string path);
public:
    HttpServer();
    HttpServer(int port, unsigned long ip_address, int bklg);
    void launch() override;
    void addApi(std::string route, Api* api);
};

} // end namespace pweb

#endif
