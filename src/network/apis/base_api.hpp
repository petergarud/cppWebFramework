#ifndef BASE_API
#define BASE_API

#include <string>
#include "../servers/pweb_lib_servers.hpp"

namespace pweb {

class Api {
private:
    std::string base_route_;
    HttpServer* server_;
public:
    Api(std::string base_route, HttpServer& server)
        : base_route_(base_route)
        , server_(&server) {
        server_->addApi(base_route_, this);

    }
    virtual ~Api() = default;
};

} // end namespace pweb

#endif
