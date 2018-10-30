/*
 * CUnitTestUtil.cpp
 *
 *  Created on: Jan 27, 2018
 *      Author: spider
 */

#include <spidervnAccel/impl/test/CUnitTestFramework.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

CUnitTestFramework::CUnitTestFramework() {
}

CUnitTestFramework::~CUnitTestFramework() {
}

void CUnitTestFramework::assert(bool b, std::string errmsg)
{
	if (!b)
	{
		cout << "\tTestFail: " << errmsg << endl;
	}
}
