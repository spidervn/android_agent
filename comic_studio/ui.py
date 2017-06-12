#!/usr/bin/python
from os import system
import curses

def init_Win1():
	myscreen = curses.initscr()

	myscreen.border(0)
	myscreen.addstr(12, 25, "Python curses action")
	myscreen.refresh()
	myscreen.getch()

	myscreen.endwin()


def get_param(promt_string):
	screen.clear()
	screen.border(0)
	screen.addstr(2, 2, promt_string)
	screen.refresh()

	inp = screen.getstr(10,10,60)

	return inp

def execute_cmd(cmd_string):
	system("clear")
	a = system(cmd_string)

	print ""
	if a==0:
		print "Command executed correctly"
	else:
		print "Command terminated with error"

	raw_input("Press Enter")
	print ""

x = 0
while x != ord('4'):
	screen = curses.initscr()

	screen.clear()
	screen.border(0)
	screen.addstr(2, 2,"Please enter a number ...")
	screen.addstr(4, 4, "1 - Add a user")
	screen.addstr(5, 4, "2 - Restart Apache")
	screen.addstr(6, 4, "3 - Show disk space")
	screen.addstr(7, 4, "4 - Exit")
	screen.refresh()

	x = screen.getch()

	if x == ord('1'):
		username = get_param("Enter the username")
		homedir = get_param("Enter the home directory, eg /home/nate")
		groups = get_param("Enter comma-separated groups, eg adm, dialout, cdrom")
		shell = get_param("Enter the shell, eg /bin/bash")
		curses.endwin()

	if x == ord('2'):
		curses.endwin()
		execute_cmd("apachectl restart")

	if x == ord('3'):
		curses.endwin()
		execute_cmd("df -h")

curses.endwin()		