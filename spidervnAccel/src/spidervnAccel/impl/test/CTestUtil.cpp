/*
 * CTestUtil.cpp
 *
 *  Created on: Jan 27, 2018
 *      Author: spider
 */

#include <spidervnAccel/impl/test/CTestUtil.h>
#include "CUnitTestUtil.h"
#include "spidervnAccel/impl/CDirectoryUtil.h"
#include "spidervnAccel/impl/CSystemUtil.h"
#include <string>

using namespace std;

CTestUtil::CTestUtil()
{
	initialize_();
}

CTestUtil::~CTestUtil() {
	un_Initialize();
}

void CTestUtil::initialize_()
{
	_pDir = new CDirectoryUtil();
	_pSU_ = new CSystemUtil();
}

void CTestUtil::un_Initialize()
{
	delete _pDir;
	delete _pSU_;
}

void CTestUtil::runAll_Test()
{
	testExcuteCmd();
}

void CTestUtil::testExcuteCmd()
{
	string res01;
	string res02;

	res01 = _pSU_->exe_Cmd("pwd");
	res02 = _pSU_->exe_Cmd("ls -la .");

	if (!res01.empty() && !res02.empty())
	{
		printf("----Test ExecuteCommand\t[PASSED]");
	}
	else
	{
		printf("----Test ExecuteCommand\t[ERROR]********************************************************");
	}

	return;
}


void CTestUtil::testDirectory()
{
	string shome = "/home/spider/";
	string shome_1 = "/home/spider";

	string strFullPath = "/home/spider/myspiderman.tar.gz";
	string sfile = "setup.exe";

	string sPath_Join_ = _pDir->joinDirectory(shome, sfile);
	string sPath_Join1 = _pDir->joinDirectory(shome_1, sfile);

	CUnitTestUtil::assert(sPath_Join1 == sPath_Join_, "Two path join must equal /home/spider/setup.exe");
	CUnitTestUtil::assert(sPath_Join1 == "/home/spider/setup.exe", "Two path join must equal /home/spider/setup.exe");


}
