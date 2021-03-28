#include "server.h"
#include <stdio.h>


int main(int argc, char const *argv[])
{
    init();

    app();

    end();
    return 0;
}