#include "simple_server.hpp"

namespace pweb {

SimpleServer::SimpleServer(int domain, int type, int protocol, int port, unsigned long ip_address, int bklg)
    : sock_(new ListeningSocket(domain, type, protocol, port, ip_address, bklg)) {
    }

SimpleServer::~SimpleServer() {
    delete sock_;
}

} // end namespace pweb
