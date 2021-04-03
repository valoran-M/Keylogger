#ifndef SERVER_H
#define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)

#define PORT 2000

#define BUF_SIZE 1024

void app(void);
void write_in_logs(char *ip, char *content);
int init_connection(void);

#endif