//
// Created by gaertnerl on 25.09.20.
//

#ifndef MOEBIUS_MESSAGE_H
#define MOEBIUS_MESSAGE_H

#include <string>

namespace moebius {

    class Message{
    private:
        std::string message;
    public:
        std::string as_str();
        char* create_char_ptr();
        int length();
        explicit Message(const std::string& message);
        explicit Message(char buffer[], int buffer_length);
    };
}

#endif //MOEBIUS_MESSAGE_H
