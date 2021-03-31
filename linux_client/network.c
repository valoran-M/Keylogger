#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "network.h"

void init(void)
{
#ifdef WIN32
    WSADATA wsa;
    int err = WSAStartup(MAKEWORD(2, 2), &wsa);
    if (err < 0)
    {
        puts("WSAStartup faild !");
        exit(EXIT_FAILURE);
    }
#endif
}

void end(void)
{
#ifdef WIN32
    WSACleanup();
#endif
}

int init_connection(SOCKADDR_IN *sin)
{
    /* UDP so SOCK_DGRAM */
    SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);

    sin->sin_family = AF_INET;
    sin->sin_port = htons(PORT);
    sin->sin_addr.s_addr = inet_addr(IP);

    if (sock == INVALID_SOCKET)
    {
        perror("socket()");
        exit(errno);
    }
    return sock;
}

void send_message(SOCKET sock, SOCKADDR_IN *serv, char *buffer)
{
    if (sendto(sock, buffer, strlen(buffer), 0, (SOCKADDR *)serv, sizeof *serv) < 0)
    {
        perror("sendto()");
        exit(errno);
    }
}

void app()
{
    char buffer[BUF_SIZE];
    SOCKADDR_IN *serv;
    SOCKET sock = init_connection(serv);

    memset(buffer, '\0', sizeof(buffer));

    printf("Enter message : ");
    gets(buffer);

    send_message(sock, serv, buffer);
}