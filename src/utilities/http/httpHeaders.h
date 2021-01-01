//
// Created by gaertnerl on 11.10.20.
//

#ifndef MOEBIUS_HTTPHEADERS_H
#define MOEBIUS_HTTPHEADERS_H

#include <string>
#include <vector>
#include <unordered_map>

namespace moebius{

    class HeaderNameHelper{
    private:
        HeaderNameHelper();
        std::unordered_map<std::string, int> headerIds;
        void setupHeaderIds();
    public:
        static const std::vector<std::string> requestHeaders;
        static const std::vector<std::string> responseHeaders;
        static HeaderNameHelper& instance(){
            static HeaderNameHelper INSTANCE;
            return INSTANCE;
        }
        static bool isRequestHeader(const std::string&);
        static bool isResponseHeader(const std::string&);
        int getHeaderId(const std::string& headerName);
    };

    class Header{
    private:
        int id;
    public:
        const std::string name;
        Header(HeaderNameHelper helper, const std::string& name);
        int getId() const;
    protected:
        HeaderNameHelper nameHelper;
        bool equ(Header *other) const;
    };

    class RequestHeader: Header{
    public:
        RequestHeader(const HeaderNameHelper& helper, const std::string& name);
        bool operator ==(const RequestHeader &other) const;
    };

    class ResponseHeader: Header{
    public:
        ResponseHeader(const HeaderNameHelper& helper, const std::string& name);
        bool operator ==(const ResponseHeader &other) const;
    };

    class HeaderHasher{
    public: static int hash(Header *h) ;
    };

    class RequestHeaderHasher : HeaderHasher{
    public: int operator() (const RequestHeader & h) const;
    };

    class ResponseHeaderHasher : HeaderHasher{
    public: int operator() (const ResponseHeader & h) const;
    };
}

#endif //MOEBIUS_HTTPHEADERS_H
