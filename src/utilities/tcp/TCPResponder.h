//
// Created by gaertnerl on 22.12.20.
//

#ifndef MOEBIUS_TCPRESPONDER_H
#define MOEBIUS_TCPRESPONDER_H

#include "../response/Responder.h"
#include "TCPRequest.h"

namespace moebius{

    class TCPResponder: public Responder<TCPRequest>{
    public:
    Message respondTo(TCPRequest request) override;
    };
}
#endif //MOEBIUS_TCPRESPONDER_H
