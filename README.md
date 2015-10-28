# pbrpc

This is a dedicated demo for [libpbrpc](https://github.com/madwyn/libpbrpc) using C++.

# What's so great about it?

It provides an interface between JavaScript in browser and local resources.

NPAPI is fading away. Chrome will drop it [permanently](https://www.chromium.org/developers/npapi-deprecation) and so will [others](https://developer.mozilla.org/en-US/Add-ons/Plugins).

One big advantage of NPAPI is local device accessibility such as hardware and file system.

There are alternatives, for Chrome you can use [native messaging](https://developer.chrome.com/extensions/messaging#native-messaging), for Firefox they came up with something similar called [js-ctypes](https://developer.mozilla.org/en-US/docs/Mozilla/js-ctypes). But they won't save your day. These are not exactly the same thing, and what about other browsers? Safari, Edge and the old love IE?

The great thing about this project along with [pbrpc-client-js](https://github.com/madwyn/pbrpc-client-js) is you get them all. Using Protocol Buffers or just plain JSON, you can handle all browsers.

One server rules the local resources including hardware and file system, the web client makes some RPC calls to get everything it wanted.

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
