#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

#include "simple_server.hpp"
#include <string>

namespace pweb {

class HttpServer : public SimpleServer {
private:
    // connection between client and server
    int conn_;
    char buffer[30000];
    std::string response_;

    void acceptor() override;
    void handler() override;
    void responder() override;
public:
    HttpServer();
    HttpServer(int port, unsigned long ip_address, int bklg);
    void launch() override;
};

} // end namespace pweb

#endif
