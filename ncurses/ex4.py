import curses
import os

stdscr = curses.initscr()

curses.noecho()
curses.cbreak()

stdscr.keypad(1)


while True:
	

curses.nocbreak()
stdscr.keypad(0)
curses.echo()
curses.endwin()