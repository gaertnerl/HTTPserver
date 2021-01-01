//
// Created by gaertnerl on 22.12.20.
//

#ifndef MOEBIUS_RESPONDER_H
#define MOEBIUS_RESPONDER_H

#include "../message/message.h"
#include "../request/Request.h"

namespace moebius {

    // specified generic according to https://stackoverflow.com/a/30687399
    template <typename T, typename std::enable_if<std::is_base_of<Request, T>::value>::type* = nullptr>
    class Responder {

    public:
        virtual Message respondTo(T request) = 0;
    };

}


#endif //MOEBIUS_RESPONDER_H
