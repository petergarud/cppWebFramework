#include "connecting_socket.hpp"

namespace pweb {

// default constructor
ConnectingSocket::ConnectingSocket(int domain, int type, int protocol, int port, unsigned long ip_address)
    : SimpleSocket(domain, type, protocol, port, ip_address) {
    // establish the connection
    connection_ = connect_to_network(sock_, address_);
    test_connection(connection_);
}

// bind to network
int ConnectingSocket::connect_to_network(int sock, sockaddr_in address) {
    return connect(sock, (sockaddr*)&address, sizeof(address));
}

} // end namespace pweb
