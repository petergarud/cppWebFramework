#ifndef BINDING_SOCKET_HPP
#define BINDING_SOCKET_HPP

#include "simple_socket.hpp"

namespace pweb {

class BindingSocket : public SimpleSocket {
public:
    // default constructor
    BindingSocket(int domain, int type, int protocol, int port, unsigned long ip_address);
    int connect_to_network(int sock, sockaddr_in address) override;
};

} // end namespace pweb

#endif
