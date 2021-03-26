#ifndef SERVER_H
#define SERVER_H

#ifdef WIN32

#include <winsock2.h>

#endif

#ifdef __linux

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else

#error not defined for this platform

#endif

#define PORT 2000
#define MAX_CLIENT 10

#define BUF_SIZE 1024

#include "client.h"

void init(void);
void end(void);
void app(void);
int init_connection(void);
void end_connection(int sock);
int read_client(SOCKET sock, char *buffer);
void remove_client(Client *clients, int to_remove, int *actual);
void clear_clients(Client *clients, int actual);

#endif