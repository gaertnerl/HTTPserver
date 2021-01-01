//
// Created by gaertnerl on 22.12.20.
//

#ifndef MOEBIUS_HTTPREQUEST_H
#define MOEBIUS_HTTPREQUEST_H

#include "../request/Request.h"

namespace moebius {
    class HTTPRequest : public Request {
    public:
        void parse(Message message) override;
    };
}

#endif //MOEBIUS_HTTPREQUEST_H
