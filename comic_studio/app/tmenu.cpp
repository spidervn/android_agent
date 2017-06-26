#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <new>
#include "tmenu.h"
#include <iostream>

using namespace std;

TMenu::TMenu(int count, char* main_label,  int* vals, char** labels) 
{
	if (count > 0) {
		n = count;
		this->menu_val = (int*) malloc(sizeof(int) * count);	
		this->menu_list = (string*) malloc(sizeof(string)*count); // new string[count];		
		this->menu_label = main_label;
			
		for (int i=0; i<count;i++) {
			menu_val[i] = vals[i];
			menu_list[i] = labels[i];
		}
	}
}

TMenu::~TMenu() 
{
	free(menu_list);
	free(menu_val);
}

int TMenu::show()
{
	int choice = -1;
	string sinput;

	while (choice <= 0 && choice > n) {
		printf("Menu: %s\r\n", menu_label.c_str());
		for (int i=0;i<n;i++) {
			printf("\t%d. %s\r\n", (i+1), menu_list[i].c_str());
		}
		printf("Would you like to do?:");
		cin >> sinput;

		
		choice = atoi(sinput.c_str()) - 1;
	}

	return menu_val[choice-1];
}

