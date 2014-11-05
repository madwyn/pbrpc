# Required cmake version
cmake_minimum_required(VERSION 2.8.4)

project(proto_msg)

# The .proto source files
file(GLOB proto_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")

# If we are not compiling protobuf but using a precompiled one
if (NOT PROTOBUF_ROOT)
    find_package(Protobuf REQUIRED)
else()
    set(PROTOBUF_SRC_ROOT_FOLDER ${PROTOBUF_ROOT})
    set(PROTOBUF_PROTOC_EXECUTABLE ${protoc_BINARY_DIR}/protoc)
    include(FindProtobufExt)
endif()

# Generate the proto message files
PROTOBUF_GENERATE_CPP(proto_SRCS proto_HDRS ${proto_FILES})

set_source_files_properties(${proto_FILES} PROPERTIES GENERATED TRUE)

# Build library
add_library(proto_msg
    STATIC
    ${proto_SRCS}
    ${proto_HDRS}
)

add_dependencies(proto_msg protoc)

target_link_libraries(proto_msg protobuf)

target_include_directories(proto_msg PUBLIC "${proto_msg_BINARY_DIR}")
