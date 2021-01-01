//
// Created by gaertnerl on 22.12.20.
//

#include "Request.h"

#include <utility>

moebius::Message moebius::Request::get() {
    return message;
}

void moebius::Request::set(moebius::Message m) {
    this->message = std::move(m);
}

