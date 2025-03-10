#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

DIR *directory;
char *PWD;
struct dirent *dirRead;

int main(int argc, char *argv[]){
	if(argc < 2){
		PWD = getenv("PWD");
		directory = opendir(PWD);
		fprintf(stdout, "\nListing directory (%s):\n", PWD);
		while((dirRead = readdir(directory)) != NULL){
			fprintf(stdout, "%s\n", dirRead->d_name);
		}
		closedir(directory);
	}
}
