#ifndef BASE_API
#define BASE_API

#include <string>
#include <unordered_map>

namespace pweb {

class HttpServer;

class Api {
private:
    using FuncPtr = std::string (Api::*)(std::string);
    std::string base_route_;
    HttpServer* server_;
    std::unordered_map<std::string, FuncPtr> get_routes_;
    std::unordered_map<std::string, FuncPtr> post_routes_;

public:
    Api();
    Api(std::string base_route, HttpServer& server);
    virtual ~Api() = default;
    virtual std::string processRequest(std::string method, std::string path, std::string request_body);
    virtual std::string basic(std::string request_body) {
        return "/Users/petergarud/Documents/Personal/Development/Projects/cppWebFramework/src/html/index.html";
    }
    virtual std::string error() {
        return "/Users/petergarud/Documents/Personal/Development/Projects/cppWebFramework/src/html/error.html";
    }
};

} // end namespace pweb

#endif
