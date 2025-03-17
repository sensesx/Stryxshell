#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>

DIR *directory;
char *PWD;
struct dirent *dirRead;
int opt;

#define GREEN "\e[1;32m"
#define DEFAULTCOLOR "\033[0m"
#define BLUE  "\e[1;33m"

int main(int argc, char *argv[]){
	bool map[3] = {false};
	if(argc < 2){
		PWD = getenv("PWD");
		directory = opendir(PWD);
		fprintf(stdout, "\nListing directory (%s):\n", PWD);
		while((dirRead = readdir(directory)) != NULL){
			if(dirRead->d_name[0] == '.'){
				continue;
			}
			fprintf(stdout, "%s\n", dirRead->d_name);
		}
		closedir(directory);
	}else{
		PWD = getenv("PWD");
		while((opt = getopt(argc, argv, "-halr")) != -1){
			switch(opt){
				case 'a':
					map[0] = true;
					break;
				case 'r':
					map[1] = true;
					break;	
				case 'l':
					map[2] = true;
					break;
				case 'h':
					fprintf(stdout, "Usage: ls -args    ARGS:\n");
					fprintf(stdout, "-h    Show this help message\n");
					fprintf(stdout, "-a    Show hidden files\n");
					fprintf(stdout, "-l    Show filetypes\n");
					return 0;
				default:
					fprintf(stderr, "\n %c not a valid argument.\n", opt);
					break;
			}
		}

		if(map[0]){
			// ALL
			PWD = getenv("PWD");
			directory = opendir(PWD);
			fprintf(stdout, "\nListing directory (%s):\n", PWD);
			while((dirRead = readdir(directory)) != NULL){
				if(dirRead->d_type == DT_DIR){
					fprintf(stdout, BLUE "%s\n", dirRead->d_name);
					continue;
				}else if(dirRead->d_type == DT_REG){
					fprintf(stdout, GREEN "%s\n", dirRead->d_name);
					continue;
				}
				fprintf(stdout, DEFAULTCOLOR "%s\n", dirRead->d_name);
			}
			closedir(directory);
			return 0;
		}

		if(map[1]){
			PWD = getenv("PWD");
			directory = opendir(PWD);
			fprintf(stdout, "\nListing directory (%s):\n", PWD);
			while((dirRead = readdir(directory)) != NULL){
				if(dirRead->d_type == DT_DIR){
					
				}
				fprintf(stdout, "%s\n", dirRead->d_name);
			}
			closedir(directory);
			return 0;

			return 0;
						
		}

		if(map[2]){
			
			return 0;
		}

		directory = opendir(PWD);
		fprintf(stdout, "\nListing directory (%s):\n", PWD);
		while((dirRead = readdir(directory)) != NULL){
			fprintf(stdout, "%s\n", dirRead->d_name);
		}
		closedir(directory);
	}
	return 0;
}
