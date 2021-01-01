//
// Created by gaertnerl on 11.10.20.
//

#include "httpHeaders.h"

#include <utility>


const std::vector<std::string> moebius::HeaderNameHelper::requestHeaders = {
        "request_header",
};

const std::vector<std::string> moebius::HeaderNameHelper::responseHeaders = {
        "response_header"
};

void moebius::HeaderNameHelper::setupHeaderIds() {
    int id = 0;
    for(const auto& value: requestHeaders) {
        headerIds.insert({value, id});
        id++;
    }
    for(const auto& value: responseHeaders) {
        headerIds.insert({value, id});
        id++;
    }
}

int moebius::HeaderNameHelper::getHeaderId(const std::string& headerName) {
    return headerIds.at(headerName);
}

moebius::HeaderNameHelper::HeaderNameHelper() {
    setupHeaderIds();
}

bool moebius::HeaderNameHelper::isRequestHeader(const std::string& newHeader) {
    for (auto &header : requestHeaders){
        if(header == newHeader) return true;
    }
    return false;
}

bool moebius::HeaderNameHelper::isResponseHeader(const std::string& newHeader) {
    for (auto &header : responseHeaders){
        if(header == newHeader) return true;
    }
    return false;
}

int moebius::Header::getId() const{
    return id;
}

moebius::Header::Header(HeaderNameHelper helper, const std::string& name):
nameHelper(std::move(helper))
{
    id = nameHelper.getHeaderId(name);
}

bool moebius::Header::equ(moebius::Header *other) const {
    return this->id == other->getId();
}

moebius::ResponseHeader::ResponseHeader(const HeaderNameHelper& helper, const std::string& name)
        :Header(helper, name){}

bool moebius::ResponseHeader::operator==(const moebius::ResponseHeader &other) const {
    return this->equ((Header *) &other);
}

moebius::RequestHeader::RequestHeader(const HeaderNameHelper& helper, const std::string& name)
        :Header(helper, name){}

bool moebius::RequestHeader::operator==(const moebius::RequestHeader &other) const {
    return this->equ((Header *) &other);
}

int moebius::HeaderHasher::hash(moebius::Header *h) {
    return h->getId();
}

int moebius::RequestHeaderHasher::operator()(const moebius::RequestHeader &h) const {
    return hash((Header *) &h);
}

int moebius::ResponseHeaderHasher::operator()(const moebius::ResponseHeader &h) const {
    return hash((Header *) &h);
}
