#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "server.h"

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

int init_connection(void)
{
    SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
    SOCKADDR_IN sin = {0};

    if (sock == INVALID_SOCKET)
    {
        perror("socket()");
        exit(errno);
    }

    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(PORT);
    sin.sin_family = AF_INET;

    if (bind(sock, (SOCKADDR *)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        perror("bind()");
        exit(errno);
    }
    return sock;
}

int read_client(SOCKET sock, SOCKADDR_IN *sin, char *buffer)
{
    int n = 0;
    size_t sinsize = sizeof *sin;

    if ((n = recvfrom(sock,
                      buffer, BUF_SIZE - 1,
                      0,
                      (SOCKADDR *)sin,
                      sinsize)) < 0)
    {
        perror("recvfrom()");
    }

    buffer[n] = 0;

    return n;
}

void app(void)
{
    SOCKET sock = init_connection();
    char buffer[BUF_SIZE];
    while (1)
    {
        SOCKADDR_IN from = {0};
        read_client(sock, &from, buffer);
        printf("%s", buffer);
    }
    closesocket(sock);
}