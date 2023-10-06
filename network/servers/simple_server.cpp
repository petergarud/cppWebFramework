#include "simple_server.hpp"

namespace pweb {

SimpleServer::SimpleServer(int domain, int type, int protocol, int port, unsigned long ip_address, int bklg)
    : sock_(new ListeningSocket(domain, type, protocol, port, ip_address, bklg)) {
    }

SimpleServer::~SimpleServer() {
    delete sock_;
}

void SimpleServer::test_connection(int item_to_test) {
    if (item_to_test < 0) {
        std::cerr << "Failed to connect...";
        std::exit(EXIT_FAILURE);

    }
}

} // end namespace pweb
