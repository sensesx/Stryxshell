#include <dirent.h>
#include <stdio.h>
#include "../../HEADERS.h"
#include <stdlib.h>

DIR *directory;
char *PWD;
struct dirent *dirRead;

int main(int argc, char *argv[]){
	if(argc < 2){
		PWD = getenv("PWD");
		directory = opendir(PWD);
		while((dirRead = readdir(directory)) != NULL){
			fprintf(stdout, "%s\n", dirRead->d_name);
		}

	}
}
