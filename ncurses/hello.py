import curses
import sys


msg = "Enter a String"
row = 0
col = 0
mystr = ""

stdscr = curses.initscr()   # Return Window object
curses.noecho()
curses.cbreak()

stdscr.keypad(True)
#curses.getmaxyx(stdscr, row, col)
row = 60
col = 80

stdscr.addstr(58, 0, "HIHIHI")
# curses.mvprintw(row/2, (col-len(msg))/2, "%s", msg)
# curses.getstr(mystr)
# curses.mvprintw(LINES - 2, 0, "You Entered: %s", mystr)
# curses.getch()
c = stdscr.getch()
curses.endwin()
