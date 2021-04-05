#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"

/** 
 *  This function initializes the connection if is not possible she leaves the program
 * 
 *  @param void
 *  @return socket created (int)
*/
int init_connection(void)
{
    int socket_desc;
    struct sockaddr_in server_addr;

    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (socket_desc < 0)
    {
        fprintf(stderr, "Error while creating socket\n");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully\n");

    // Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind to the set port and IP:
    if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        fprintf(stderr, "Couldn't bind to the port\n");
        exit(EXIT_FAILURE);
    }
    printf("Done with binding\n");

    printf("Listening for incoming messages...\n\n");
    return socket_desc;
}

/** 
 *  This function writes a string in a logs/ip.log
 *  
 *  @param string client ip
 *  @param content data written to the file 
 *  @return void
 */
void write_in_logs(char *ip, char *content)
{
    char nom_file[50] = "logs/";
    strcat(nom_file, ip);
    strcat(nom_file, ".log");
    FILE *file = fopen(nom_file, "a");

    fprintf(file, "%s\n", content);

    fclose(file);
}

/**
 *  The most import fonction with the buckle and the reception of data
 * 
 *  @param void
 *  @return void
 */
void app(void)
{
    int socket_desc = init_connection();
    struct sockaddr_in client_addr;

    char client_message[BUF_SIZE];
    socklen_t client_struct_length = sizeof(client_addr);

    while (1)
    {
        // Clean client_message
        memset(client_message, '\0', sizeof(client_message));
        // receive data
        if (recvfrom(socket_desc, client_message, sizeof(client_message), 0,
                     (struct sockaddr *)&client_addr, &client_struct_length) < 0)
            fprintf(stderr, "Couldn't receive\n");
        
        write_in_logs(inet_ntoa(client_addr.sin_addr), client_message);
    }
    // Close the socket:
    close(socket_desc);
}
