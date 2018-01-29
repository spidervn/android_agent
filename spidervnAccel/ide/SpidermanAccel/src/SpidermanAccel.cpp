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

	if (pCmd_->preRequisiteCheck() == 0)
	{
		printf("================================================================================\r\n");
		printf("\t[SpidermanvnProject] Extract all archive comic in this folder.\r\n");
		printf("================================================================================\r\n");
		pCmd_->extract_AllArchiveComic(".");
		printf("================================================================================\r\n");
		printf("\t[SpidermanvnProject] Finish extract.\r\n");
		printf("================================================================================\r\n");
	}
	else
	{
		printf("[SpidermanvnProject] Your system does not have enough requirements for run the work.\r\n");
	}

	delete pCmd_;
	delete pSU;
	return 0;
}
