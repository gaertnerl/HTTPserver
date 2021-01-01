//
// Created by gaertnerl on 01.11.20.
//

#ifndef MOEBIUS_HTTPPARSER_H
#define MOEBIUS_HTTPPARSER_H

#include "../message/message.h"
#include "./httpMessages.h"

namespace moebius{

    class HTTPParser{
    protected:
        size_t pos = 0;
        Message rawHTTP;
        size_t findNextWhitespace();
        size_t findNextCLRF();
        size_t findNextNewLIne();
        void setRawMessage(Message message);
        HTTPParser();
    };

    class RequestParser : HTTPParser {
    public:
        HTTPRequest convert(Message rawHTTP);
    };

    class ResponseParser : HTTPParser {
        HTTPResponse convert(Message rawHTTP);
    };

}

#endif //MOEBIUS_HTTPPARSER_H
