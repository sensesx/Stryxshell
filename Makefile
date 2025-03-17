all: final 

final: shelling.c execshell.c
	echo "Compiling final application"
	gcc execshell.c shelling.c -g -o stryxshell -lncursesw -Wall -L./lib -lminha 
	# NOT EXECUTING (Shared Lib) -> gcc *.c -g -o stryxshell -lncursesw -L./builtins/Source -lmine -Wall 

clean:
	echo "Removing stuff"

