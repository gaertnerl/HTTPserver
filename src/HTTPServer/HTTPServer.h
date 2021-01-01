//
// Created by gaertnerl on 01.11.20.
//

#ifndef MOEBIUS_HTTPSERVER_H
#define MOEBIUS_HTTPSERVER_H

#include "./../TCPServer/tcpServer.h"

namespace moebius {

    class HTTPServer : public TCPServer{
    public:
        HTTPServer();
    protected:
        Message generate_response(moebius::Message message) override;
    };

}

#endif //MOEBIUS_HTTPSERVER_H
