//============================================================================
// Name        : SpidermanAccel.cpp
// Author      : ducvd
//============================================================================

#include <iostream>
using namespace std;

#include "spidervnAccel/impl/CSystemUtil.h"

int main() {
	cout << "SpidermanVN accelerator" << endl;
	ISystemUtil* pSU = new CSystemUtil();

	cout <<  pSU->exe_Cmd("ls /home/spider") << endl;
	delete pSU;

	return 0;
}
