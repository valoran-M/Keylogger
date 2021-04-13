#ifndef NETWORK_H
#define NETWORK_H

#include <winsock2.h>

#define PORT 2000
#define IP "86.246.168.96"
#define BUF_SIZE 50

void init(void);
void end(void);
void app(void);
SOCKET init_connection();
void send_message(SOCKET sock, SOCKADDR_IN serv, char *buffer);

#endif