/*
 *
 * CREATED BY SENSESX 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <locale.h>



// TODO: Fix resize window issue. It doens't refresh the way it should.
// Lookup for functions that would fix this problem.


char *appNameGfx[220] = {
"███████╗████████╗██████╗ ██╗   ██╗██╗  ██╗███████╗██╗  ██╗███████╗██╗     ██╗",
"██╔════╝╚══██╔══╝██╔══██╗╚██╗ ██╔╝╚██╗██╔╝██╔════╝██║  ██║██╔════╝██║     ██║",
"███████╗   ██║   ██████╔╝ ╚████╔╝  ╚███╔╝ ███████╗███████║█████╗  ██║     ██║",
"╚════██║   ██║   ██╔══██╗  ╚██╔╝   ██╔██╗ ╚════██║██╔══██║██╔══╝  ██║     ██║",
"███████║   ██║   ██║  ██║   ██║   ██╔╝ ██╗███████║██║  ██║███████╗███████╗███████╗",
"╚══════╝   ╚═╝   ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
};

char *developedBySensesx[3] = {
"╔════════════════════════════════════════════════╗",
"║		DEVELOPED BY SENSESX              ║",
"╚════════════════════════════════════════════════╝"
};

int j = 2;

void printBanners(WINDOW *p, char **banner, int linecount, int startline, int startcol){
	for(int i = 0;i <= linecount; i++){
		mvwprintw(p, j++ + startline, startcol,"%s", banner[i]);
		wrefresh(p);
	}

}

void blobSimulation(WINDOW *p){

}



char *whoami;
char bufferInput[256];

int main(){
	//raw(); || Control chars are not interpreted by shell
	//noecho(); || User input is not printed on the screen
	cbreak(); // Control keys are granted to work 

	setlocale(LC_ALL, "");
	whoami = getenv("USER");
	initscr();
	if(!has_colors()){ // change colors later with init_color ?
		printw("Terminal doesn't support colors");
		getch();
		return EXIT_FAILURE;
	}
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	int boxHeight, boxWidth, startY, startX;
	int yMax, xMax;

	refresh();
	getmaxyx(stdscr, yMax, xMax);

	boxHeight = yMax;
	boxWidth = xMax;
	startY = 0;
	startX = 0;
	refresh();

	WINDOW *menuWin = newwin(boxHeight, boxWidth, startY, startX);
	WINDOW *optionWin = newwin(8, 30,yMax - 45, (xMax/3) + 21);

	wattron(menuWin, COLOR_PAIR(1));
	box(menuWin, 0, 0); // wborderw: only if more control is needed
	wrefresh(menuWin);
	printBanners(menuWin, appNameGfx, 5, 4,(xMax / 3) - 5);
	printBanners(menuWin, developedBySensesx, 2, 9, (xMax / 3) + 11);

	attroff(COLOR_PAIR(1));

	int choice = 0;
	int cursorHighlight = 0;

	box(optionWin, 0, 0);
	wrefresh(optionWin);

	keypad(optionWin, true);
	char *options[4]={
	"1. SHELL APPLICATION",
	"2. SUDDEN MINIGAME",
	"3. ABOUT THIS APPLICATION",
	"4. EXIT"
	};


	while(1){
		for(int i =0; i <= 3; i++){
			if(i == cursorHighlight){
				wattron(optionWin, A_REVERSE);
			}
			mvwprintw(optionWin, i + 1, 1, "%s", options[i]);
			wattroff(optionWin, A_REVERSE);
			wrefresh(optionWin);
		}
		choice = wgetch(optionWin);
		switch(choice){
			case KEY_DOWN:
				if((cursorHighlight + 1) == 4){
					cursorHighlight = 0;	
					break;
				}
				cursorHighlight++;	
				break;
			case KEY_UP:
				if((cursorHighlight - 1) == -1){
					cursorHighlight = 3;
					break;
				}
				cursorHighlight--;	
				break;
			default:
				break;
		}
		if(choice == 10){
			break;
		}
	}

	WINDOW *shell = newwin(boxHeight, boxWidth, startY, startX);

	if(strcmp(options[cursorHighlight], options[0]) == 0){
		wprintw(shell, "hi");
		wrefresh(shell);
	}
	if(strcmp(options[cursorHighlight], options[0]) == 0){
		wprintw(shell, "hi");
		wrefresh(shell);
	}
	if(strcmp(options[cursorHighlight], options[0]) == 0){
		wprintw(shell, "hi");
		wrefresh(shell);
	}
	if(strcmp(options[cursorHighlight], options[0]) == 0){
		wprintw(shell, "hi");
		wrefresh(shell);
	}








	int c = getch();
	endwin();

	return 0;
}


