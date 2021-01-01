//
// Created by gaertnerl on 22.12.20.
//

#ifndef MOEBIUS_REQUEST_H
#define MOEBIUS_REQUEST_H

#include "../message/message.h"

namespace moebius {

    class Request {
    private:
        Message message;
    public:
        virtual void parse(Message message) = 0;
        void set(Message message);
        Message get();
    };

}

#endif //MOEBIUS_REQUEST_H
