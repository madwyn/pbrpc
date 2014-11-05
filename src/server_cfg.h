#ifndef SERVER_CFG_H_INCLUDED
#define SERVER_CFG_H_INCLUDED

#include <string.h>


// the parameters and configurations
#define URI_RPC         "/rpc"          // the serviec URL
#define PATH_SSL_CERT   "ssl_cert.pem"  // the SSL certificate path
#define DOC_ROOT        "./web"

// string helpers
#define __STR_CON_EQ(str1, str2)        (0 == strcmp(str1, str2))
#define __STR_CON_START(str1, str2)     ((strlen(str1) >= (strlen(str2))) && (0 == strncmp(str1, str2, strlen(str2))))
#define __STR_EQ(str1, str2, CON)       (   ((NULL == str1) && (str1 == str2))  \
                                         || ((NULL != str1) && (NULL != str2) && CON(str1, str2)))

#define STR_EQUAL(str1, str2)   __STR_EQ(str1, str2, __STR_CON_EQ)
#define STR_START(str1, str2)   __STR_EQ(str1, str2, __STR_CON_START)

// the helper macros
#define IS_URI_RPC(       /* const char* */ uri)    STR_EQUAL(uri, URI_RPC)
#define IS_METHOD_POST(   /* const char* */ method) STR_EQUAL(method, HTTP_POST)
#define IS_METHOD_OPTIONS(/* const char* */ method) STR_EQUAL(method, HTTP_OPTIONS)

#define IS_CONTENT_TYPE_PROTOBUF(/* const char* */ content_type)    STR_START(content_type, CONTENT_APPLICATION_PROTOBUF)

// other HTTP strings
#define CONTENT_APPLICATION             "application/"
#define CONTENT_APPLICATION_JSON        CONTENT_APPLICATION "json"
#define CONTENT_APPLICATION_PROTOBUF    CONTENT_APPLICATION "x-protobuf"
#define CONTENT_TEXT_PLAIN              "text/plain"


#endif
