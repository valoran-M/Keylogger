cmake_minimum_required(VERSION 3.0)

project(keylogger VERSION 0.0.1)

set(SERVER_SRCS
    ./server_src/server.c
)

set(SERVER_HEADERS
    ./server_src/server.h
    ./server_src/client.h
)


add_executable(server server_src/main.c ${SERVER_SRCS} ${SERVER_HEADERS})
target_compile_features(server PRIVATE cxx_std_17)
target_include_directories(server PUBLIC server_src/)
