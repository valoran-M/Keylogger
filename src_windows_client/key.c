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
        return key;
    }
    if (vkCode >= VK_NUMPAD0 && vkCode <= VK_DIVIDE)
        return n_pad(vkCode);
    printf("%d ", vkCode);
    return key;
}

static const char *number[] = {
    "à", "&", "é", "\"", "'", "(", "-", "è", "_", "ç"};
static const char *number_shifted[] = {
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const char *number_algr[] = {
    "@", UK, "~", "#", "{", "[", "|", "`", "\\", "^"};

static const char *f_key[] = {
    "[F1]", "[F2]", "[F3]", "[F4]", "[F5]", "[F6]", "[F7]",
    "[F8]", "[F9]", "[F10]", "[F11]", "[F12]"};




const int isCapsLock(void)
{
    return (GetKeyState(VK_CAPITAL) & 0x0001);
}

const int isAltgrLock(void)
{
    return (GetKeyState(VK_RMENU) < 0 && GetKeyState(VK_LCONTROL) < 0);
}

const char *n_pad(DWORD vkCode)
{
    switch (vkCode)
    {
    case VK_NUMPAD0:
        return "0";
    case VK_NUMPAD1:
        return "1";
    case VK_NUMPAD2:
        return "2";
    case VK_NUMPAD3:
        return "3";
    case VK_NUMPAD4:
        return "4";
    case VK_NUMPAD5:
        return "5";
    case VK_NUMPAD6:
        return "6";
    case VK_NUMPAD7:
        return "7";
    case VK_NUMPAD8:
        return "8";
    case VK_NUMPAD9:
        return "9";
    case VK_MULTIPLY:
        return "*";
    case VK_ADD:
        return "+";
    case VK_SEPARATOR:
        return "-";
    case VK_SUBTRACT:
        return "-";
    case VK_DECIMAL:
        return ".";
    case VK_DIVIDE:
        return "/";
    default:
        return UK;
    }
}