#include "server.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    init();

    app();

    end();
    return 0;
}