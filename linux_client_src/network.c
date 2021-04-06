#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "network.h"

int init_connection()
{
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (sock == INVALID_SOCKET)
    {
        perror("socket()");
        exit(errno);
    }
    printf("socket creates successfully\n");
    return sock;
}

const void send_message(int sock, struct sockaddr_in serv, char *buffer)
{
    socklen_t server_struct_length = sizeof(serv);
    if (sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&serv, server_struct_length) < 0)
    {
        perror("sendto()");
        exit(errno);
    }
}