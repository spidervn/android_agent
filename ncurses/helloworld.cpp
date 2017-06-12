
#include <ncurses.h>

int main()
{
	initscr();	/* Start curses mode */
	printw("Hello World !!!");

	refresh();
	getch();
	endwin();

	return 0;
}
