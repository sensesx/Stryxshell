#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *PWD;

int main(){
	if(PWD != NULL){
		memset(PWD, 0, strlen(PWD));
	}
	PWD = getenv("PWD");
	fprintf(stdout, "%s\n", PWD);

}
