#ifndef __ServerRPC_HH_INCLUDED_
#define __ServerRPC_HH_INCLUDED_

#include <mongoose.h>


namespace pbrpc {
class ServerRPC {
public:
    ServerRPC();
    virtual ~ServerRPC();
    void     init(void);
    int      start(void);
    bool     stop(void);

    struct mg_context *ctx = nullptr;

    int  port    = 9999;
    int  threads = 50;
    bool running = false;
};

}

#endif //__ServerRPC_HH_INCLUDED_
