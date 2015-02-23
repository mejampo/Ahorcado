#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <string>

//PARA COMPILAR NCURSES g++ Main.cpp -lncurses -o main
using namespace std;

#define WIDTH 30
#define HEIGHT 10 

int startx = 0;
int starty = 0;

char *choices[] = { "FACIL","MEDIO","DIFICIL","Exit"};

int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);


int main(int argc, char** argv){

	int dificultad;
	bool gano;
	int opc;
	int ch;

 	WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;

	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;
		
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	mvprintw(0, 0, "USE LAS FLECHAS PARA SELECCIONAR, PRESIONE ENTER PARA ELEGIR");
	refresh();
	print_menu(menu_win, highlight);
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case 10:
				choice = highlight;
				break;
			default:

				break;
		}

		print_menu(menu_win, highlight);
		if(choice != 0)	/* User did a choice come out of the infinite loop */
			break;
	}	
	clrtoeol();
	refresh();

		if(choice == 1){	//FACIL
			char ans[80];
			initscr();
			noecho();
			bool gano= false;
			int intentos=0;
			printw("MODO FACIL");
				do{

					mvprintw(LINES-2,0,"Lleva ",intentos," intentos");

				}while(gano==false);

			/*getstr(ans);

 			mvprintw(LINES - 2, 0, "You Entered: %s", ans);*/

 			getch();
 			endwin();

		}else if(choice==2){//MEDIO
			char ans[80];
			initscr();
			noecho();
			printw("MODO MEDIO");

			getch();
 			endwin();

		}else if(choice ==3){//DIFICIL
			char ans[80];
			initscr();
			noecho();
			printw("MODO DIFICIL");

			getch();
 			endwin();

		}
	endwin();
	return 0;
}


void print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;	

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

