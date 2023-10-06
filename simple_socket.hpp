#ifndef SIMPLE_SOCKET_HPP
#define SIMPLE_SOCKET_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace pweb { // for peter's web stuff
 
class SimpleSocket {
protected:
    int sock_; // identification of socket
    sockaddr_in address_; // used for binding/connecting socket when determining what kind
                         // of address family OS is looking at
    int connection_; // result of bind/connect call
public:
    /*
     * @param domain (or address family) the communication domain for socket
     *  - could be AF_INET (IP), AF_INET6 (IPv6), etc
     *  @param type the service type
     *  - could be SOCK_STREAM (virtual circuit protocol), etc
     *  - options limited based on address family
     *  @param protocol 
     *  - dependent on service type
     *  @param port port number
     *  @param address IP address of computer
     *  - example is 0.0.0.0 (INADDR_ANY)
     */
    SimpleSocket(int domain, int type, int protocol, int port, unsigned long ip_address);
    virtual ~SimpleSocket() = default;

    // pure virtual funciton that either binds (server) or connects (client) to network
    virtual int connect_to_network(int sock, sockaddr_in address) = 0; 
  
    // make sure connection is properly establish
    void test_connection(int);

    // Getter functions
    // int get_sock();
    // sockaddr_in get_address();
    // int get_connection();
};

} // end namespace pweb

#endif
