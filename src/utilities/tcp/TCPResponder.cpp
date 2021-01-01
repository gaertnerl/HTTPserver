//
// Created by gaertnerl on 22.12.20.
//

#include "TCPResponder.h"

moebius::Message moebius::TCPResponder::respondTo(moebius::TCPRequest request) {
    return request.get(); //todo
}
