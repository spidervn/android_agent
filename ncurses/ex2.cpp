
#include <ncurses.h>

int main()
{
	int ch;
	initscr();		/* Start curses mode */	
	raw();
	keypad(stdscr, TRUE);	/* We get F1, F2, etc ... */
	noecho();

	printw("Type any character to see it in bold\n");
	ch = getch();

	if (ch == KEY_F(1)) {
		printf("F1 Key pressed");
	} else {
		printw("The pressed key is ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}

	refresh();		/* Print it on to the real screen */
	getch();		/* Wait for user input */
	endwin();		/* End curses mode */

	return 0;
}
