#include <stdio.h>
#include <time.h>

int main(){
	time_t stime = time(0);
	time(&stime);
	printf("%s", ctime(&stime));
	

}
