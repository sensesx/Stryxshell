#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

DIR *dirp;
struct dirent *dir;

int main(int argc, char *argv[]){
	dirp = opendir(".");
	while((dir = readdir(dirp)) != NULL){
		printf("%s", dir->d_name);
	}

}
