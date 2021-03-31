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