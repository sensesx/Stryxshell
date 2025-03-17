#include "HEADERS.h"
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <dirent.h>
#include <pty.h>

WINDOW *shell;
char *whoami;
char *pwd;
char userbuffer[50];
char userinput[256];
DIR *directory;
struct dirent *dir;
FILE *fp;
FILE *temp;


int checkcommand(char *buf, char *pwd){
	int masterFd, slaveFd;
	bool commandExists = false;
	bool hasArgs = false;
	char command[64];
	char commandexec[100];
	char slaveName[64];
	char *args[20] = {0};
		for(int i = 0; ; i++){
		if(buf[i] == '\x0' || buf[i] == '\n' || buf[i] == '\x20' || buf[i] == '\x10'){
			command[i] = '\x00';
			break;
		}
		command[i] = buf[i];
	}
	directory = opendir("./builtins");
	while((dir = readdir(directory)) != NULL){
		if(strcmp(dir->d_name, command) == 0){
			commandExists = true;
			break;
		}
		wrefresh(shell);
	}

	// Dealing with exported functions -> Not the best way of course
	

	int argc = 0;
	char *token = strtok(buf, " ");  
	int i = 0;
	// Parse arguments
	while(token != NULL){
		args[i++] = token;
		argc ++;
        	token = strtok(NULL, " ");
	}

	if(argc >= 2){
		hasArgs = true;	
	}

	if(!commandExists){
		if(hasArgs){
			if(strcmp(args[0], "printf") == 0){
				printf_t(buf, shell);
				return true;
			}else{
				wprintw(shell, "%s: command not found\n", buf);
				return false;
			}
		}		
		wprintw(shell, "%s: command not found\n", buf);
		return false;
	}
		
	openpty(&masterFd, &slaveFd, slaveName, NULL, NULL);
	snprintf(commandexec, sizeof(commandexec), "./builtins/%s", command);

	int pid = fork();
	char buffer[1024] = {0};

	if(pid == 0){
		close(masterFd);
		dup2(slaveFd, STDIN_FILENO);
		dup2(slaveFd, STDOUT_FILENO);
		dup2(slaveFd, STDERR_FILENO);
		close(slaveFd);
		if(hasArgs == false){
			execv(commandexec, NULL);
			exit(1);
		}else{	
			execv(commandexec, args);
			exit(1);
		}

		exit(1);
	}else{
		wait(NULL);
		close(slaveFd);
		memset(buffer, 0, sizeof(buffer));
		read(masterFd, buffer, sizeof(buffer));
		scrollok(shell, TRUE);
		for(int i = 0; i <= strlen(buffer); i++){
			if(buffer[i] == '\n' || buffer[i] > 32 || buffer[i] == '\x20'){ // Bigger than control characters dec
								 // It's better to print one by one because some control characters mess up with the functionality
				waddch(shell, buffer[i]);
				wrefresh(shell);
			}
		}
		close(masterFd);
	}
	closedir(directory);
	return true;
}

void buildUser(char *pwdbuf, char *hostbuf){
	snprintf(userbuffer, sizeof(userbuffer), "[%s]@[%s]:", pwdbuf, hostbuf);
}

FILE *settings;
int retstatus;

void execshell(void *p){
	init_pair(2, COLOR_GREEN, 0);
	shell = (WINDOW *)p;
	whoami = getenv("USER");
	pwd = getenv("PWD");
	buildUser(whoami, pwd);
	werase(shell);

	wprintw(shell, "STRYXSHELL TERMINAL V1.0 - For more information or help, type help in the terminal.\n\n");

	while(1){
		wattron(shell, COLOR_PAIR(2));
		wprintw(shell, "%s", userbuffer); // future changes are going to be made for redirection i/o
		wattroff(shell, COLOR_PAIR(2));
		wrefresh(shell);
		wgetstr(shell, userinput);
		if(iscntrl(userinput[0])){
			wrefresh(shell);
			continue;
		}
		retstatus = checkcommand(userinput, pwd);
	}
}
