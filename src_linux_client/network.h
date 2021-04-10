#ifndef NETWORK_H
#define NETWORK_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)

#define PORT 2000
#define IP "127.0.0.1"
#define BUF_SIZE 50

int init_connection();
const void send_message(int sock, struct sockaddr_in serv, char *buffer);


#endif