#ifndef SIMPLE_SERVER_HPP
#define SIMPLE_SERVER_HPP

#include "../sockets/pweb_lib_sockets.hpp"

namespace pweb {

class SimpleServer {
protected:
    ListeningSocket* sock_;

    // accept requests
    virtual void acceptor() = 0;
    // handle requests
    virtual void handler() = 0;
    // respond to requests
    virtual void responder() = 0;
    void test_connection(int);
public:
    SimpleServer(int domain, int type, int protocol, int port,
               unsigned long ip_address, int bklg);

    virtual ~SimpleServer();

    // launch server
    virtual void launch() = 0;
};

} // end namespace pweb

#endif
