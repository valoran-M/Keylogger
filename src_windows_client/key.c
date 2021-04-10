#include <stdio.h>
#include <windows.h>

#include "key.h"

int isCapsLock(void)
{
    return (GetKeyState(VK_CAPITAL) & 0x0001);
}

char *translate_key(DWORD vkCode)
{
    char *key = malloc(KEY_SIZE);
    memset(key, '\0', KEY_SIZE);
    if (vkCode > 64 && vkCode < 91)
    {
        if (!(GetAsyncKeyState(VK_SHIFT) ^ isCapsLock()))
            vkCode += 32;
        char key_char = (char)vkCode;
        sprintf(key, "%c", key_char);
        return key;
    }
    return key;
}