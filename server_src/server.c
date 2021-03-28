#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/select.h>

#include "server.h"
#include "client.h"

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
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
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
    if (listen(sock, MAX_CLIENT) == SOCKET_ERROR)
    {
        perror("listen()");
        exit(errno);
    }
    return sock;
}

int read_client(SOCKET sock, char *buffer)
{
    int n = 0;

    if((n = recv(sock, buffer, BUF_SIZE - 1, 0)) < 0)
    {
        perror("recv()");

        n = 0;
    }

    buffer[n] = 0;

    return n;
}

void remove_client(Client *clients, int to_remove, int *actual)
{
    memmove(clients + to_remove,
            clients + to_remove + 1,
            (*actual - to_remove -
             1) *
                sizeof(Client));
    (*actual)--;
}

void clear_clients(Client *clients, int actual)
{
    for (size_t i = 0; i < actual; i++)
    {
        closesocket(clients[i].sock);
    }
}

void end_connection(int sock)
{
    closesocket(sock);
}

void app(void)
{
    SOCKET sock = init_connection();
    char buffer[BUF_SIZE];

    int acutal = 0;
    int max = sock;

    Client clients[MAX_CLIENT];

    fd_set rdfs;

    while (1)
    {
        int i = 0;

        FD_ZERO(&rdfs);

        FD_SET(STDIN_FILENO, &rdfs);

        FD_SET(sock, &rdfs);

        for (size_t i = 0; i < acutal; i++)
        {
            FD_SET(clients[i].sock, &rdfs);
        }
    }
}