//
// Created by gaertnerl on 01.11.20.
//

#include "httpParser.h"

#include <utility>

/* Raw http request and responses will be parsed here. They are formatted according to RFC 2616. (HTTP 1.1)
 *
 *   Request  = Request-Line CRLF
 *              *((general-header | request-header | entity-header) CRLF)
 *              CRLF
 *              [ message-body ]
 *
 *   Response = Status-Line CRLF
 *              *(( general-header | response-header | entity-header ) CRLF)
 *              CRLF
 *              [ message-body ]
 */

void moebius::HTTPParser::setRawMessage(moebius::Message message) {
    rawHTTP = std::move(message);
}

size_t moebius::HTTPParser::findNextWhitespace() {
    size_t newPos = rawHTTP.as_str().find(' ', pos);
    pos = newPos;
    return pos;
}

size_t moebius::HTTPParser::findNextCLRF() {
    size_t newPos = rawHTTP.as_str().find("\r\n", pos);
    pos = newPos;
    return pos;
}

size_t moebius::HTTPParser::findNextNewLIne() {
    size_t newPos = rawHTTP.as_str().find('\n', pos);
    pos = newPos;
    return pos;
}

moebius::HTTPParser::HTTPParser() : rawHTTP("") {}

moebius::HTTPRequest moebius::RequestParser::convert(moebius::Message rawHTTP) {
    this->rawHTTP = std::move(rawHTTP);

    int start = pos;
    findNextCLRF();
    int stop = pos;

    return HTTPRequest({}, "");
}

moebius::HTTPResponse moebius::ResponseParser::convert(moebius::Message rawHTTP) {

}
