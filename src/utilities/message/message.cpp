//
// Created by gaertnerl on 25.09.20.
//


#include <cstring>

#include "message.h"

moebius::Message::Message(const std::string& message)
{
    this->message = message;
}

moebius::Message::Message(char buffer[], int buffer_length)
{
    this->message = std::string(buffer, buffer_length);
}

int moebius::Message::length()
{
    return message.length();
}

char* moebius::Message::create_char_ptr()
{
    char * char_message = new char[message.length() + 1];
    strcpy(char_message, message.c_str());
    return char_message;
}

std::string moebius::Message::as_str()
{
    return message;
}