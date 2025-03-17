#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <stdbool.h>

char userbuf[64];

char username[64];
char password[64];

FILE *fp;
char lines[256];
char filepath[] = {"../../.main"};
char regexp[] = {"^(.+?),"};

int regsult;


bool validateUser(char *user, FILE *fileptr){
	fp = fopen(filepath, "a+");
	regex_t reg;
	if(regcomp(&reg, regexp, REG_EXTENDED) == -1){
		fprintf(stderr, "Regex compilation error.");
		return false;
	}
	printf("EXpression: %s String: %s", regexp, user);
	if((regsult = regexec(&reg, "Pedro,vini", 0, 0, 0)) == 0){
		fprintf(stdout, "User is being used already.");
		return true;
	}else if(regsult == REG_NOMATCH){
		fprintf(stdout, "User is not being used.");
		return false;
	}
	return true;	
}


int main(){
	fprintf(stdout, "Username: ");
	fgets(userbuf, sizeof(userbuf), stdin);
	strncpy(username, userbuf, sizeof(userbuf));
	memset(userbuf, 0, sizeof(userbuf));
	validateUser(username, fp);
	
	fprintf(stdout, "Password: ");
	fgets(userbuf, sizeof(userbuf), stdin);
	strncpy(password, password, sizeof(userbuf));
	memset(userbuf, 0, sizeof(userbuf));


}

