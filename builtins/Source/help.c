#include <stdio.h>
#include <stdlib.h>

int main(){
	fprintf(stdout, "\nHelp command show you all commands you need to use this terminal and a brief explanation about them.\nType <help \"command\"> to see the manual about certain program or type <man \"command\">\n ");
	fprintf(stdout, "\n\
ls <args>:	 list given directory contents\n\
cd <args>:    	 change directory\n\
adduser:         add user to terminal\n\
deluser:      	 del terminal user\n\
man <args>:  	 help with commands\n\
pwd:             print current directory\n\
printf <string>: print string to screen\n\
time:            shows current time\n\
useradd <args>:  add user\n\
userdel <args>:  delete user\n\
whoami:          shows current user\n\
exit:            exits the terminal\n\
loguser:         use another account\n\
cat <file>:      print file contents\n\
echo <string>:   echoes string to the screen\n\
exec <args>:     executes command\n\
vimmer:          simple text editor\n\
");
}
