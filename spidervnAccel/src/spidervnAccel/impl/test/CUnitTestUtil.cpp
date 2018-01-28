/*
 * CUnitTestUtil.cpp
 *
 *  Created on: Jan 27, 2018
 *      Author: spider
 */

#include <spidervnAccel/impl/test/CUnitTestUtil.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

CUnitTestUtil::CUnitTestUtil() {
}

CUnitTestUtil::~CUnitTestUtil() {
}

void CUnitTestUtil::assert(bool b, std::string errmsg)
{
	if (!b)
	{
		cout << "\tTestFail: " << errmsg << endl;
	}
}
