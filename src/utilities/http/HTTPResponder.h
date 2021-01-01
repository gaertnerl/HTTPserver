//
// Created by gaertnerl on 22.12.20.
//

#ifndef MOEBIUS_HTTPRESPONDER_H
#define MOEBIUS_HTTPRESPONDER_H

#include "../response/Responder.h"
#include "HTTPRequest.h"

namespace moebius {
    class HTTPResponder : public Responder<HTTPRequest> {

    };
}

#endif //MOEBIUS_HTTPRESPONDER_H
