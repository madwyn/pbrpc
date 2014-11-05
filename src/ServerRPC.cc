#include <string.h>
#include <stdlib.h>
#include <string>

#include "ServerRPC.hh"
#include "http_def.h"
#include "server_cfg.h"
#include "handle_pbrpc.hh"

using ::std::string;

namespace pbrpc {

void sendResponseCORS(struct mg_connection *conn, const string &response) {
    mg_printf(conn,
            "HTTP/1.1 200 OK\r\n"
            HEADER_Access_Control_Allow_Origin ": *\r\n"
            HEADER_Content_Type ": " CONTENT_APPLICATION_PROTOBUF "\r\n"
            HEADER_Content_Length ": %d\r\n",
            response.length()
    );

    mg_write(conn, response.c_str(), (int) response.length());
}

void sendResponsePROTO(struct mg_connection *conn, const string &response) {
    sendResponseCORS(conn, response);
}

void sendResponseOPTIONS(struct mg_connection *conn) {
    mg_printf(conn,
            "HTTP/1.1 200 OK\r\n"
            HEADER_Access_Control_Allow_Origin ": *\r\n"
            HEADER_Access_Control_Allow_Methods ": " HTTP_POST ", " HTTP_OPTIONS "\r\n"
            HEADER_Access_Control_Allow_Headers ": %s\r\n"
            HEADER_Content_Length ": %d\r\n",

            mg_get_header(conn, HEADER_Access_Control_Request_Headers),
            0
    );
}

int handleRPC(struct mg_connection *conn) {
    mg_request_info *request_info = mg_get_request_info(conn);

    // only process "POST" request
    if (IS_METHOD_POST(request_info->request_method)) {
        // check the content type
        const char *contentType = mg_get_header(conn, HEADER_Content_Type);
        if (IS_CONTENT_TYPE_PROTOBUF(contentType)) {
            const char* size_header = mg_get_header(conn, HEADER_Content_Length);
            int len = 0;
            sscanf(size_header, "%d", &len);

            char *buff = (char*) malloc(sizeof(char) * (len + 1));
            mg_read(conn, buff, len);
            sendResponsePROTO(conn, handle_pbrpc(buff, len));
            free(buff);
        } else {
            // empty or unknown content type, ignore
        }
    } else if (IS_METHOD_OPTIONS(request_info->request_method)) {
        // received HTTP OPTIONS
        sendResponseOPTIONS(conn);
    } else {
        // should be other POST messages
        sendResponsePROTO(conn, "The RPC request is not using POST.");
    }

    return 0;   // Mark as processed
}

int handleHTTP(struct mg_connection *conn) {
    // the URI starts with /rpc
    if (IS_URI_RPC(mg_get_request_info(conn)->uri)) {
        return handleRPC(conn);
    }
}

ServerRPC::ServerRPC() {
    init();
}

ServerRPC::~ServerRPC() {
}

int ServerRPC::start(void) {
    if (running) {
        return 0;
    }

    struct mg_callbacks callbacks;
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.begin_request = handleHTTP;

    char port[6];
    char threads[6];
    snprintf(port,    sizeof(port),    "%d", this->port);
    snprintf(threads, sizeof(threads), "%d", this->threads);

    const char *options[] = {"listening_ports", port, "num_threads", threads, "document_root", DOC_ROOT, NULL};

    ctx = this->ctx = mg_start(&callbacks, this, options);

    if (nullptr == ctx) {
        // failed to create the server
        return 1;
    }

    running = true;

    return 0;
}

void ServerRPC::init(void) {
    running = false;
    // init the PBRPC system
    init_pbrpc();
}


bool ServerRPC::stop(void) {
    if (running) {
        mg_stop(ctx);
        running = false;
        ctx = nullptr;
    }

    return !running;
}

}
