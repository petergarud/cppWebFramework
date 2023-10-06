#ifndef CONNECTING_SOCKET_HPP
#define CONNECTING_SOCKET_HPP

#include "simple_socket.hpp"

namespace pweb {

class ConnectingSocket : public SimpleSocket {
public:
    // default constructor
    ConnectingSocket(int domain, int type, int protocol, int port, unsigned long ip_address);
    int connect_to_network(int sock, sockaddr_in address) override;
};

} // end namespace pweb

#endif
