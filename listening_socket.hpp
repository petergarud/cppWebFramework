#ifndef LISTENING_SOCKET_HPP
#define LISTENING_SOCKET_HPP

#include "binding_socket.hpp"

namespace pweb {

class ListeningSocket : public BindingSocket {
private:
    int backlog_;
    int listen_id_;
public:
    // default constructor
    // @ backlog is how many incoming requests can be in queue before start not accepting any more
    ListeningSocket(int domain, int type, int protocol, int port, unsigned long ip_address, int bklg);

    // start listening
    int start_listening();
};

} // end namespace pweb

#endif
