#include "simple_socket.hpp"
#include <cstdlib>
#include <filesystem>

namespace pweb {

// default constructor
SimpleSocket::SimpleSocket(int domain, int type, int protocol, int port, unsigned long ip_address) {
    // create socket
    sock_ = socket(domain, type, protocol);
    test_connection(sock_);

    // address structure
    address_.sin_family = domain;
    address_.sin_addr.s_addr = htonl(ip_address);
    address_.sin_port = htons(port);
}

// ensure connection is properly establish
void SimpleSocket::test_connection(int item_to_test) {
    if (item_to_test < 0) {
        std::cerr << "Failed to connect...";
        std::exit(EXIT_FAILURE);

    }
}

// Getter functions
int SimpleSocket::get_sock() {
    return sock_;
}
sockaddr_in SimpleSocket::get_address() {
    return address_;
}
// int SimpleSocket::get_connection() {
//     return connection_;
// }

} // end namespace pweb
