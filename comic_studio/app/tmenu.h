#ifndef _TMENU_H_
#define _TMENU_

// Terminal Menu (Simplest)
#include <string>

class TMenu 
{
private:	
	int n;
	std::string menu_label;
	std::string* menu_list;
	int* menu_val;
public:
	TMenu(int count, char* main_label,  int* vals, char** labels);
	~TMenu();

	int show();
};

#endif
