#include "base_api.hpp"
#include "../servers/pweb_lib_servers.hpp"

namespace pweb {

Api::Api() { }

Api::Api(std::string base_route, HttpServer& server)
    : base_route_(base_route)
    , server_(&server) {
    server_->addApi(base_route_, this);
}

std::string Api::processRequest(std::string method, std::string path, std::string request_body) {
    return "/Users/petergarud/Documents/Personal/Development/Projects/cppWebFramework/src/html/index.html";
}

} // end namespace pweb
