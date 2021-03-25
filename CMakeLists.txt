cmake_minimum_required(VERSION 3.0)

project(keylogger VERSION 0.0.1)

set(SERVER_SRCS
)

set(SERVER_HEADERS
    
)


add_executable(server server/main.cpp ${SERVER_SRCS} ${SERVER_HEADERS})
target_compile_features(server PRIVATE cxx_std_17)
target_include_directories(server PUBLIC src/)
target_link_libraries(server)