#include "listening_socket.hpp"

namespace pweb {

ListeningSocket::ListeningSocket(int domain, int type, int protocol, int port, unsigned long ip_address, int bklg) 
: BindingSocket(domain, type, protocol, port, ip_address), backlog_(bklg) {
    listen_id_ = start_listening();
    test_connection(listen_id_);
}

int ListeningSocket::start_listening() {
    return listen(sock_, backlog_); // sets socket to be able to
                                                // handle incoming connections
}

} // end namespace pweb
