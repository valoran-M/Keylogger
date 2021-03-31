#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

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

int init_connection()
{
    SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock == INVALID_SOCKET)
    {
        perror("socket()");
        exit(errno);
    }
    return sock;
}

void send_message(SOCKET sock, SOCKADDR_IN *serv, char *buffer)
{
    socklen_t len = sizeof serv;
    if (sendto(sock, buffer, strlen(buffer), 0, (SOCKADDR *)serv, &len) < 0)
    {
        perror("sendto()");
        exit(errno);
    }
}

void app()
{
    char buffer[BUF_SIZE];
    SOCKADDR_IN serv;

    serv.sin_family = AF_INET;
    serv.sin_port = htons(PORT);
    serv.sin_addr.s_addr = inet_addr(IP);

    SOCKET sock = init_connection();

    memset(buffer, '\0', sizeof(buffer) - 1);

    printf("Enter message : ");
    gets(buffer);

    send_message(sock, &serv, buffer);
}