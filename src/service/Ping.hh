#ifndef PBRPC_API_PING_HH_INCLUDED
#define PBRPC_API_PING_HH_INCLUDED

#include <rpc_ping.pb.h>

namespace pbrpc {
namespace api {

using ::google::protobuf::RpcController;
using ::google::protobuf::Closure;

class PingServiceImpl : public PingService {
public:
    PingServiceImpl() {};

    virtual void Ping(
            RpcController* controller,
            const PingRequest* request,
            PingResponse* response,
            Closure* done
    ) {
        // Do your processing here

        // Fill response
        response->set_result("I got your message: " + request->message());
    }
};

}
}

#endif
