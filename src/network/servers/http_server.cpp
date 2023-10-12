#include "http_server.hpp"
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

namespace pweb {

HttpServer::HttpServer() : HttpServer(8080, INADDR_ANY, 10) { }

HttpServer::HttpServer(int port, unsigned long ip_address, int bklg)
    : SimpleServer(AF_INET, SOCK_STREAM, 0, port, ip_address, bklg) {
        files_["index.html"]  = "/Users/petergarud/Documents/Personal/Development/Projects/cppWebFramework/src/html/index.html";
}

void HttpServer::launch() {
    std::cout << "===========Started server===========\n";
    while (true) {
        std::cout << "===========Waiting for request============\n";
        acceptor();
        std::cout << "===========Handling request============\n";
        handler();
        responder();
        std::cout << "===========Closing connection============\n";
    }
}

void HttpServer::acceptor() {
    sockaddr_in address = sock_->get_address();
    int addrlen = sizeof(address);

    // accept looks at socket that was set up for network and retrieves the
    // first incoming connection in queue if it exists
    // address parameter gets filled with some information about the client
    conn_ = accept(sock_->get_sock(), (sockaddr*)&address, (socklen_t*)&addrlen);
    test_connection(conn_);
    
    // read the incoming request into the buffer with a size of 30000
    read(conn_, buffer, 30000);
}

void HttpServer::handler() {
    // do stuff with buffer
    std::cout << buffer << '\n';
    response_ = "HTTP/1.1 200 OK\nContent-Type: text/html\n\r\n\n";
    file_.open(files_["index.html"], std::ios::in);

}

void HttpServer::responder() {
    char ch;
    while (true) {
        file_ >> std::noskipws >> ch;
        if (file_.eof()) break;
        response_ += ch;
    }
    write(conn_, response_.c_str(), strlen(response_.c_str()));
    close(conn_);
}

void HttpServer::addApi(std::string route, Api* api) {
    routes_[route] = api;
}

} // end namespace pweb
