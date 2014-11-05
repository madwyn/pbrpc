project(pbrpc_srv)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(pbrpc_srv_SRCS
    main.cpp
    ServerRPC.cc
    handle_pbrpc.cc
)
add_executable(pbrpc_srv ${pbrpc_srv_SRCS})

target_link_libraries(pbrpc_srv mongoose pbrpc proto_msg)
