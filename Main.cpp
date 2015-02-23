#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <string>

//PARA COMPILAR NCURSES g++ Main.cpp -lncurses -o main
using namespace std;

int main(int argc, char** argv){

	int dificultad;
	bool gano;
	int opc;
	int ch;

	//printw(15,50,"BIENVENID@");

	initscr();			/* Start curses mode 		  */
	raw();				
	keypad(stdscr, TRUE);		
	noecho();
	printw("Hello Player!!!\n");

	refresh();
	getch();

	printw("The pressed key is ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);

		refresh();	
    	getch();			
	endwin();
	/*do{

	}while (gano==false);*/

	return 0;
}

