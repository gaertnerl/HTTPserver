//
// Created by gaertnerl on 01.11.20.
//

#include "HTTPServer.h"

moebius::Message moebius::HTTPServer::generate_response(moebius::Message message){
    return Message("HTTP/1.0 200 OK \r\n\r\n Hello from http server");
}

moebius::HTTPServer::HTTPServer()= default;
