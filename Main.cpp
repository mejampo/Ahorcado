#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(int argc, char** argv){


	int dificultad;
	bool gano;
	int opc;

	//printw(15,50,"BIENVENID@");

	initscr();			/* Start curses mode 		  */
	printw("Hello Player!!!\n");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	printw("Welcome to your ruin");
	refresh();
	getch();			/* Wait for user input */
	endwin();
	/*do{

	}while (gano==false);*/

	return 0;
}