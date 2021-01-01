##ABOUT HTTP

###Basic structure of http messages

- initial line
- header lines
- CRLF (blank line)
- optional: body

Initial Line
-
This one is different for requests and responses
####Request line
    METHOD PATH HTTP_VERSION
    GET /index.html HTTP/1.1

The path does not include the address and port, only the route.
####Response line / Status line
    HTTP-VERSION STATUS-CODE STATUS-PHRASE
    HTTP/1.1 200 OK

The status code indicates the type of response:
- 1xx indicates an informational message only
- 2xx indicates success of some kind
- 3xx redirects the client to another URL
- 4xx indicates an error on the client's part
- 5xx indicates an error on the server's part 

The phrase is meant to be human readable.

Header lines
-
    HEADER = HEADER-NAME: VALUE CRLF
- **!** value can contain LF
- header name is not case sensitive
- any number of spaces or tabs between ":" and value.

Header lines beginning with space or tab are part of the previous header line, folded into multiple lines for easy reading.

    is the same:
    Header1: value-1, value-2
    HEADER1: value-1,
             value-2

###header types
- HTTP 1.1 defines 46 headers
- **in requests** always define **Host** and **User-Agent**
- **in responses** always define **Server** and **Last-Modified**

---
source: https://www.jmarshall.com/easy/http/