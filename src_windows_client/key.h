#ifndef KEY_H
#define KEY_H

#define KEY_SIZE 20
#define UK "[UNKNOW]"

char *translate_key(DWORD vkCode);
const char *n_pad(DWORD vkCode);
const int isCapsLock(void);
const int isAltgrLock(void);

#endif