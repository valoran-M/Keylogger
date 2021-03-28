#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

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

void remove_client(Client *clients, int to_remove, int *actual)
{
    memmove(clients + to_remove,
            clients + to_remove + 1,
            (*actual - to_remove - 
            1) * sizeof(Client));
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