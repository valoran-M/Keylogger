#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "server.h"

int init_connection(void)
{
    int socket_desc;
    struct sockaddr_in server_addr;

    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (socket_desc < 0)
    {
        printf("Error while creating socket\n");
        return -1;
    }
    printf("Socket created successfully\n");

    // Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind to the set port and IP:
    if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Couldn't bind to the port\n");
        return -1;
    }
    printf("Done with binding\n");

    printf("Listening for incoming messages...\n\n");
    return socket_desc;
}

void write_in_logs(char *ip, char *content)
{
    char nom_file[50] = "logs/";
    strcat(nom_file, ip);
    strcat(nom_file, ".log");
    FILE *file = fopen(nom_file, "a");

    fprintf(file, "%s", content);

    fclose(file);
}

void app(void)
{
    int socket_desc = init_connection();
    struct sockaddr_in client_addr;

    char client_message[100];
    int client_struct_length = sizeof(client_addr);

    while (1)
    {
        // Clean buffers:
        memset(client_message, '\0', sizeof(client_message));
        if (recvfrom(socket_desc, client_message, sizeof(client_message), 0,
                     (struct sockaddr *)&client_addr, &client_struct_length) < 0)
        {
            printf("Couldn't receive\n");
            return -1;
        }
        write_in_logs(inet_ntoa(client_addr.sin_addr), client_message);
    }
    // Close the socket:
    close(socket_desc);
}