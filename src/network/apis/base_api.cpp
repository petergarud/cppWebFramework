#include "base_api.hpp"
#include "../servers/pweb_lib_servers.hpp"

namespace pweb {

Api::Api() { 
    get_routes_.emplace("", &Api::basic);
    post_routes_.emplace("", &Api::basic);
}

Api::Api(std::string base_route, HttpServer& server)
    : base_route_(base_route)
    , server_(&server) {
    server_->addApi(base_route_, this);
    get_routes_.emplace("", &Api::basic);
    post_routes_.emplace("", &Api::basic);
}

std::string Api::processRequest(std::string method, std::string path, std::string request_body) {
    std::string file;
    if (method == "GET") {
        auto val = get_routes_.find(path);
        if (val == get_routes_.end()) {
            return error();
        }
        FuncPtr func = val->second;
        file = (this->*func)(request_body);
    } else if (method == "POST") {
        auto val = post_routes_.find(path);
        if (val == get_routes_.end()) {
            return error();
        }
        FuncPtr func = val->second;
        file = (this->*func)(request_body);
    }
    return file;
}

} // end namespace pweb
