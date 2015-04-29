# pbrpc
A simple implementation of Protobuf RPC server based on libpbrpc using C++

# File structure

`./deps`, the dependancies:

* `libpbrpc`, the RPC lib.
* `mongoose`, the HTTP server.

`./proto`, the RPC definitions:

* `rpc_ping.proto`, defines a PING RPC.

`./src`, the source files implement the RPC server.

# How to use

Simply use CMake to build.

# License

The MIT Lisense.
