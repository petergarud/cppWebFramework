#ifndef BASE_API
#define BASE_API

#include <string>
#include <unordered_map>

namespace pweb {

class HttpServer;

class Api {
private:
    std::string base_route_;
    HttpServer* server_;
    std::unordered_map<std::string, void (*)(std::string)> get_routes_;

public:
    Api();
    Api(std::string base_route, HttpServer& server);
    virtual ~Api() = default;
    virtual std::string processRequest(std::string method, std::string path, std::string request_body);
};

} // end namespace pweb

#endif
