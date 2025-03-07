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
		fprintf(stdout, "Output from ls:\n");
		while((dirRead = readdir(directory)) != NULL){
			fprintf(stdout, "\n%s", dirRead->d_name);
		}
		closedir(directory);
	}
}
