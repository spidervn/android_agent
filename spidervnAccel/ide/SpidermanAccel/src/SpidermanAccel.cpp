#include <iostream>
using namespace std;

#include "spidervnAccel/impl/CSystemUtil.h"
#include "spidervnAccel/impl/test/CUnitTestMain.h"
#include "spidervnAccel/impl/CCommander.h"


int main() {
	cout << "SpidermanVN accelerator" << endl;

	// CTestUtil cu;
	// cu.runAll_Test();
	// CUnitTestMain cu;
	// cu.runAll_Test();
	ICommander* pCmd_;
	ISystemUtil* pSU;

	pSU = new CSystemUtil();
	pCmd_ = new CCommander();

	// pCmd_->extract_AllArchiveComic(".");
	// pSU->exe_Cmd("cp -i /home/spider/2.txt /home/spider/1.txt");

	delete pCmd_;
	delete pSU;
	return 0;
}
