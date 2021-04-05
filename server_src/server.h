#ifndef SERVER_H
#define SERVER_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define close(s)

#define PORT 2000
#define BUF_SIZE 1024

void app(void);
void write_in_logs(char *ip, char *content);
int init_connection(void);

#endif