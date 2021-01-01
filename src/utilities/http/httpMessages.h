//
// Created by gaertnerl on 02.10.20.
//

#ifndef MOEBIUS_HTTPMESSAGES_H
#define MOEBIUS_HTTPMESSAGES_H

#include <string>
#include <unordered_map>
#include "./httpHeaders.h"


namespace moebius{

    class HTTPRequest{
    private:
    public:
        std::unordered_map<RequestHeader, std::string , RequestHeaderHasher>  headers;
        const std::string body;
        HTTPRequest(
            std::unordered_map<RequestHeader, std::string , RequestHeaderHasher>  headers,
            std::string body
            );
    };

    class HTTPResponse{
    private:
    public:
        std::unordered_map<ResponseHeader, std::string , ResponseHeaderHasher>  headers;
        const std::string body;
        HTTPResponse();
    };
}

#endif //MOEBIUS_HTTPMESSAGES_H
