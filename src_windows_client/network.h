#ifndef NETWORK_H
#define NETWORK_H

#include <winsock2.h>

#define PORT 2000
#define IP "127.0.0.1"
#define BUF_SIZE 1024

void init(void);
void end(void);
void app(void);
SOCKET init_connection();
const void send_message(SOCKET  sock, SOCKADDR_IN serv, char *buffer);

#endif