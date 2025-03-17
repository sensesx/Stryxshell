#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>

int z = 1;
FILE *tmp;
char lines[256];

void printf_t(char *buffer, WINDOW *sh){
	for(int i = 0; i <= strlen(buffer); i++){
		wprintw(sh, "%c", buffer[i]);
	}
}
