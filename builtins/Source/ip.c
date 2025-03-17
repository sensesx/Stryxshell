#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>

struct ifaddrs *myip;

int main(int argc, char *argv[]){
	if(argc < 2){
		getifaddrs(&myip);
		printf("%s", inet_ntoa(*(struct in_addr *)myip->ifa_addr));
	}
}

