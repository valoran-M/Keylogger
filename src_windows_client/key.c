#include <stdio.h>
#include <windows.h>

#include "key.h"

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
    }
    else if (vkCode >= 48 && vkCode <= 57)
        key = number(vkCode);
    else if (vkCode >= VK_LBUTTON && vkCode <= 7)
        key = "";
    else if (vkCode >= VK_NUMPAD0 && vkCode <= VK_DIVIDE)
        key = n_pad(vkCode);
    else if (vkCode >= VK_F1 && vkCode <= VK_F24)
        key = f_key(vkCode);
    else
    {
        printf("%d", vkCode);
        key = other(vkCode);
    }
    return key;
}

char *n_pad(DWORD vkCode)
{
    char *key[] = {
        "0", "1", "2", "3", "4", "5",
        "6", "7", "8", "9", "*", "+",
        "-", "-", ".", "/"};
    return key[vkCode - VK_NUMPAD0];
}

char *f_key(DWORD vkCode)
{
    char *key[] = {
        "[F1]", "[F2]", "[F3]", "[F4]", "[F5]", "[F6]",
        "[F7]", "[F8]", "[F9]", "[F10]", "[F11]", "[F12]",
        "[F13]", "[F14]", "[F15]", "[F16]", "[F17]", "[F18]",
        "[F19]", "[F20]", "[F21]", "[F22]", "[F23]", "[F24]"};

    return key[vkCode - VK_F1];
}

char *number(DWORD vkCode)
{
    char *number[] = {
        "à", "&", "é", "\"", "'", "(", "-", "è", "_", "ç"};
    char *number_shifted[] = {
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    char *number_algr[] = {
        "@", UK, "~", "#", "{", "[", "|", "`", "\\", "^"};

    if (isCapsLock() || isShiftLock())
        return number_shifted[vkCode - 48];
    if (isAltgrLock())
        return number_algr[vkCode - 48];
    else
        return number[vkCode - 48];
}

char *other(DWORD vkCode)
{
    return UK;
}

const int isCapsLock(void)
{
    return (GetKeyState(VK_CAPITAL) & 0x0001);
}

const int isAltgrLock(void)
{
    return (GetKeyState(VK_RMENU) < 0 && GetKeyState(VK_LCONTROL) < 0);
}

const int isShiftLock(void)
{
    return GetKeyState(VK_SHIFT) < 0;
}