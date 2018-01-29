/*
 * CTestUtil.cpp
 *
 *  Created on: Jan 27, 2018
 *      Author: spider
 */

#include <spidervnAccel/impl/test/CUnitTestFramework.h>
#include <spidervnAccel/impl/test/CUnitTestMain.h>
#include "spidervnAccel/impl/CDirectoryUtil.h"
#include "spidervnAccel/impl/CSystemUtil.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

CUnitTestMain::CUnitTestMain()
{
	initialize_();
}

CUnitTestMain::~CUnitTestMain() {
	un_Initialize();
}

void CUnitTestMain::initialize_()
{
	_pDir = new CDirectoryUtil();
	_pSU_ = new CSystemUtil();
}

void CUnitTestMain::un_Initialize()
{
	delete _pDir;
	delete _pSU_;
}

void CUnitTestMain::runAll_Test()
{
	printf("Start UnitTest Utils\r\n");
	testExcuteCmd();
	testDirectory();
	printf("Finish UnitTest Utils\r\n");
}

void CUnitTestMain::testExcuteCmd()
{
	string res01;
	string res02;

	printf("\tExecuteCmd testing....");
	res01 = _pSU_->exe_Cmd("pwd");
	res02 = _pSU_->exe_Cmd("ls -la .");

	if (!res01.empty() && !res02.empty())
	{
		printf("\t\t----Test ExecuteCommand\t[PASSED]\r\n");
	}
	else
	{
		printf("\t\t----Test ExecuteCommand\t[ERROR]********************************************************\r\n");
	}

	printf("\tExecuteCmd tested");
}


void CUnitTestMain::testDirectory()
{
	int n_TestCount = 0;
	int nPassed = 0;
	bool bOK;

	printf("\tDirectory testing....\r\n");

	string shome = "/home/spider/";
	string shome_1 = "/home/spider";
	string sfile = "setup.exe";
	string strFullPath = "/home/spider/myspiderman.tar.gz";

	string sExpectedJoin = shome + sfile;
	string sExpectedBase = shome_1;
	string sExpectedExt_ = "gz";
	string sExpectedName = "myspiderman.tar.gz";
	string sExpectedTruncName_ = "myspiderman";

	string sExt_;
	string sName;
	string sName_Trunc;
	string s_Base_Path;

	string sCurrentDir = ".";
	std::vector<string> vDir_;
	std::vector<string> vFile;

	string sPath_Join_ = _pDir->joinDirectory(shome, sfile);
	string sPath_Join1 = _pDir->joinDirectory(shome_1, sfile);

	// Test joining Path
	printf("\tTest joining path...\r\n");
	bOK = sPath_Join1 == sPath_Join_;
	n_TestCount++;
	nPassed += (int)bOK;
	CUnitTestFramework::assert(bOK, "\t\tTwo path join must equal /home/spider/setup.exe");

	bOK = sPath_Join1 == "/home/spider/setup.exe";
	n_TestCount++;
	nPassed += (int)bOK;
	CUnitTestFramework::assert(bOK, string("\t\tTwo path join must equal /home/spider/setup.exe (result=") + sPath_Join1 + ")");

	// Test Get base Dir
	printf("\tTest Base/Name/Extension/TruncateExtension ...\r\n");

	sExt_ = _pDir->getFileExt_(strFullPath);
	sName = _pDir->getFileName(strFullPath);
	s_Base_Path = _pDir->getBaseDir_(strFullPath);
	sName_Trunc = _pDir->truncFileExt_(sName);

	bOK = sExt_ == sExpectedExt_;
	n_TestCount++;
	nPassed += (int)bOK;
	CUnitTestFramework::assert(bOK, string("\t\tFile extension wrong (result=") +  sExt_ + ")");

	bOK = sName == sExpectedName;
	n_TestCount++;
	nPassed += (int)bOK;
	CUnitTestFramework::assert(bOK, "\t\tFilename wrong");

	bOK = s_Base_Path == sExpectedBase;
	n_TestCount++;
	nPassed += (int)bOK;
	CUnitTestFramework::assert(bOK, "\t\tBase directory wrong");


	bOK = sName_Trunc == sExpectedTruncName_;
	n_TestCount++;
	nPassed += (int)bOK;
	CUnitTestFramework::assert(bOK, string("\t\tTruncate extension wrong. Result=") + sName_Trunc);

	// Test Enumdirectory
	printf("\tTest EnumDirectory ...\r\n");
	_pDir->enumDir(".", vFile, vDir_);
	bOK = vFile.size() > 0 || vDir_.size() > 0;
	n_TestCount++;
	nPassed += (int)bOK;
	CUnitTestFramework::assert(bOK, "\t\tEnumdirectory wrong");

	printf("\tDirectory tested [Total/Passed] = [%d/%d]", n_TestCount, nPassed);
}

