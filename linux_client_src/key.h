#ifndef KEYH
#define KEYH

#define UK "[UNKNOW]"

static const char *keycodes[] =
    {"[RESERVED]", "[ESC]", "&", "é", "\"", "ù", "(", "-", "è", "_", "ç", "à",
     ")", "=", "[BACKSPACE]", "[TAB]", "a", "z", "e", "r", "t", "y", "u", "i",
     "o", "p", "^", "$", "[ENTER]\n", "[L_CTRL]", "q", "s", "d", "f", "g", "h",
     "j", "k", "l", "m", "'", "²", "L_SHIFT", "*", "w", "x", "c", "v", "b",
     "n", ",", ";", ":", "!", "[R_SHIFT]", "*", "[L_ALT]", "[SPACE] ", "[CAPS_LOCK]",
     "[F1]", "[F2]", "[F3]", "[F4]", "[F5]", "[F6]", "[F7]", "[F8]", "[F9]", "[F10]", "[NUM_LOCK]",
     "[SCROLL_LOCK]", "NL_7", "NL_8", "NL_9", "-", "NL_4", "NL5",
     "NL_6", "+", "NL_1", "NL_2", "NL_3", "INS", "[DEL]", UK, UK, "<",
     "[F11]", "[F12]", UK, UK, UK, UK, UK, UK, UK, "[R_ENTER]", "[R_CTRL]", "/",
     "[PRT_SCR]", "[R_ALT]", UK, "[HOME]", "[UP]", "[PAGE_UP]", "[LEFT]", "[RIGHT]", "[END]",
     "[DOWN]", "[PAGE_DOWN]", "[INSERT]", "[DELETE]", UK, UK, UK, UK, UK, UK, UK,
     "[PAUSE]"};

static const char *shifted_keycodes[] =
    {"[RESERVED]", "[ESC]", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
     "°", "+", "[BACKSPACE]", "[TAB]", "A", "Z", "E", "R", "T", "Y", "U", "I",
     "O", "P", "¨", "£", "[ENTER]\n", "[L_CTRL]", "Q", "S", "D", "F", "G", "H",
     "J", "K", "L", "M", "%", "~", "[L_SHIFT]", "µ", "W", "X", "C", "V", "B",
     "N", "?", ".", "/", "§", "[R_SHIFT]", "*", "[L_ALT]", "[SPACE]", "[CAPS_LOCK]",
     "[F1]", "[F2]", "[F3]", "[F4]", "[F5]", "[F6]", "[F7]", "[F8]", "[F9]", "[F10]", "[NUM_LOCK]",
     "[SCROLL_LOCK]", "[HOME]", "[UP]", "[PGUP]", "-", "[LEFT]", "NL_5",
     "[R_ARROW]", "+", "[END]", "[DOWN]", "[PGDN]", "[INS]", "[DEL]", UK, UK, ">",
     "F11", "F12", UK, UK, UK, UK, UK, UK, UK, "[R_ENTER]", "[R_CTRL]", "/",
     "[PRT_SCR]", "[R_ALT]", UK, "[HOME]", "[UP]", "[PAGE_UP]", "[LEFT]", "[RIGHT]", "[END]",
     "[DOWN]", "[PAGE_DOWN]", "[INSERT]", "[DELETE]", UK, UK, UK, UK, UK, UK, UK,
     "[PAUSE]"};

#endif