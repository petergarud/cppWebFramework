#include "http_server.hpp"
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include "../apis/pweb_lib_apis.hpp"

namespace pweb {

HttpServer::HttpServer() : HttpServer(8080, INADDR_ANY, 10) { }

HttpServer::HttpServer(int port, unsigned long ip_address, int bklg)
    : SimpleServer(AF_INET, SOCK_STREAM, 0, port, ip_address, bklg) {
}

void HttpServer::launch() {
    std::cout << "===========Started server===========\n";
    while (true) {
        std::cout << "===========Waiting for request============\n";
        acceptor();
        std::cout << "===========Handling request============\n";
        handler();
        std::cout << "===========Sending response============\n";
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
    char buffer[30000];
    read(conn_, buffer, 30000);
    request_ = buffer; // very slow?
}

void HttpServer::handler() {
    // do stuff with request
    std::cout << request_ << '\n';
    response_ = "HTTP/1.1 200 OK\nContent-Type: text/html\n\r\n\n";
    std::string method = retrieveMethod();
    std::string path = retrievePath();
    std::string base_path = getBasePath(path);
    std::string body = retrieveBody();
    std::cout << "body: " << body << '\n';
    Api* api = getApi(base_path);
    std::string rel_path = path.substr(base_path.length(), path.length() - base_path.length());
    std::string file_path = api->processRequest(method, rel_path, body);
    file_.open(file_path, std::ios::in);

}

void HttpServer::responder() {
    char ch;
    while (true) { // very slow?
        file_ >> std::noskipws >> ch;
        if (file_.eof()) break;
        response_ += ch;
    }
    file_.close();
    std::cout << response_ << '\n';
    write(conn_, response_.c_str(), strlen(response_.c_str()));
    close(conn_);
}

void HttpServer::addApi(std::string route, Api* api) {
    routes_[route] = api;
}

std::string HttpServer::retrieveMethod() {
    int ws = request_.find(" ");
    return request_.substr(0, ws);
}

std::string HttpServer::retrievePath() {
    int ws = request_.find(" ");
    std::string temp = request_.substr(ws + 1, request_.length() - 1);
    ws = temp.find(" ");
    return temp.substr(0, ws);
}

std::string HttpServer::retrieveBody() {
    int body_size = request_.find("Content-Length: ");
    if (body_size == -1) return "";
    std::string temp = request_.substr(body_size + 16, request_.length() - body_size - 16);
    int i = 0;
    while (isspace(temp[i]) == 0) {
        i++;
    }
    int data_size = stoi(temp.substr(0, i));
    return temp.substr(i+4, data_size);
}

Api* HttpServer::getApi(std::string path) {
    if (routes_.find(path) != routes_.end()) {
        return routes_[path];
    }
    return &default_api_;
}

std::string HttpServer::getBasePath(std::string path) {
    while (path.length() > 1) {
        if (routes_.find(path) != routes_.end()) {
            break;
        }
        // find last forward slash
        int index = path.find_last_of('/');
        if (index == 0) index = 1;
        path = path.substr(0, index);
    }
    return path;
}

} // end namespace pweb
