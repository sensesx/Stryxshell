#include <stdlib.h>
#include <stdio.h>


char *whoami;

int main(){
	whoami = getenv("USER");
	printf("%s\n", whoami);
}
