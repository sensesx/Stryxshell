#ifndef LOCAL_H
#define LOCAL_H

#include <ncurses.h>

void execshell(void *p);
void printf_t(char *buf, WINDOW *sh);

typedef unsigned int LIBCOMMANDS;
#define printer (0 << 1);

#endif
