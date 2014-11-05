#ifndef HTTP_DEF_H_INCLUDED
#define HTTP_DEF_H_INCLUDED


// HTTP methods
#define HTTP_GET        "GET"
#define HTTP_POST       "POST"
#define HTTP_PUT        "PUT"
#define HTTP_OPTIONS    "OPTIONS"

// HTTP header names
#define HEADER_Accept                   "Accept"
#define HEADER_Content_Type             "Content-Type"
#define HEADER_Content_Length           "Content-Length"

// Cross domain access header names
#define HEADER_Access_Control_Allow_Origin      "Access-Control-Allow-Origin"       // required
#define HEADER_Access_Control_Allow_Methods     "Access-Control-Allow-Methods"      // required
#define HEADER_Access_Control_Allow_Headers     "Access-Control-Allow-Headers"      // required if the request has an Access-Control-Request-Headers header

#define HEADER_Access_Control_Request_Method    "Access-Control-Request-Method"
#define HEADER_Access_Control_Request_Headers   "Access-Control-Request-Headers"


#endif
