//
// Created by gaertnerl on 24.09.20.
//

#ifndef MOEBIUS_TCPCLIENT_H
#define MOEBIUS_TCPCLIENT_H


#include <netinet/in.h>

#include "../utilities/message/message.h"

namespace moebius {

    class TCPClient {
    private:
        int socket;
        struct sockaddr_in serv_addr;

    public:
        TCPClient(const std::string& server_address = "127.0.0.1", int server_port = 8080);
        void request(Message message);
    };
}

#endif //MOEBIUS_TCPCLIENT_H
