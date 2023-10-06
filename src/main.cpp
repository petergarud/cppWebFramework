#include "pweb_lib.hpp"

int main() {
    pweb::HttpServer server = pweb::HttpServer();
    server.launch();
    return 0;
}
