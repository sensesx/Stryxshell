#include "HEADERS.h"
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <pty.h>

WINDOW *shell;
char *whoami;
char *pwd;
char userbuffer[50];
char userinput[2058];
DIR *directory;
struct dirent *dir;

int i = 0;
int z = 0; 

bool checkcommand(char *buf){
	int masterFd, slaveFd;

	bool commandExists = false;
	bool hasArgs = false;
	char command[64];
	char commandexec[64];
	char slaveName[64];

	for(int i = 0; ; i++){
		command[i] = buf[i];
		if(buf[i] == '\x0' || buf[i] == '\n' || buf[i] == '\x10'){
			break;
		}
	}

	directory = opendir("./builtins");
	while((dir = readdir(directory)) != NULL){
		if(strcmp(dir->d_name, command) == 0){
			commandExists = true;
			break;
		}
		wrefresh(shell);
	}
	if(!commandExists){
		wprintw(shell, "%s: command not found\n", command);
		return false;
	}
	openpty(&masterFd, &slaveFd, slaveName, NULL, NULL);

	if(hasArgs == false){
		snprintf(commandexec, sizeof(commandexec), "./builtins/%s", command);
		execv(commandexec, NULL);
	}
	return true;
}

char *readexec(char *buffer){
	checkcommand(buffer);
	if(buffer == NULL){
		wprintw(shell, "Nullado");
		wrefresh(shell);
	}
	else if(buffer[0] == '\x10'){
		wprintw(shell, "espaço");
		wrefresh(shell);
	}
	else if(buffer[0] == 'i'){
		wprintw(shell, "espaço dois");
		wrefresh(shell);
	}
	else{
		wprintw(shell, "espaço treis");
	}



	/*execv(buffer, NULL, NULL);*/
}



void errmessage(){

}


void buildUser(char *pwdbuf, char *hostbuf){
	snprintf(userbuffer, sizeof(userbuffer), "[%s]@[%s]:", pwdbuf, hostbuf);
}

void execshell(void *p){
	shell = (WINDOW *)p;
	whoami = getenv("USER");
	pwd = getenv("PWD");
	buildUser(whoami, pwd);
	werase(shell);
	while(1){

		wprintw(shell, "%s", userbuffer);
		wrefresh(shell);
		wgetstr(shell, userinput);
		readexec(userinput);
	}
}
