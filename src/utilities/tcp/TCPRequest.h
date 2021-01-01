//
// Created by gaertnerl on 22.12.20.
//

#ifndef MOEBIUS_TCPREQUEST_H
#define MOEBIUS_TCPREQUEST_H

#include "../request/Request.h"

namespace moebius{
    class TCPRequest : public Request{
    public:
        void parse(Message message) override;
    };
}
#endif //MOEBIUS_TCPREQUEST_H
