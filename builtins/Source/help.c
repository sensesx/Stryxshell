#include <stdio.h>
#include <stdlib.h>

int main(){
	fprintf(stdout, "\nHelp command show you all commands you need to use this terminal and a brief explanation about them.\nType <help \"command\"> to see the manual about certain program or type <man \"command\">\n ");
	fprintf(stdout, "\n\
ls <args>:\tlist given directory contents\n\
cd <args>:\tchange directory\n\
adduser:\tadd user to terminal\n\
deluser:\tdel terminal user\n\
man <args>:\thelp with commands\n\
pwd:\t\tprint current directory\n\
printf <string>\tprint string to screen\n\
time:\t\tshows current time\n\
useradd <args>:\tadd user\n\
userdel <args>:\tdelete user\n\
whoami:\t\tshows current user\n\
exit:\t\texits the terminal\n\
loguser:\t\tuse another account\n\
cat <file>:\tprint file contents\n\
echo <string>:\techoes string to the screen\n\
exec <args>:\texecutes command\n\
vimmer:\t\tsimple text editor\n\
");
}
