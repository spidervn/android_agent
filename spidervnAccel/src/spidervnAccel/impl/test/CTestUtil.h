/*
 * CTestUtil.h
 *
 *  Created on: Jan 27, 2018
 *      Author: spider
 */

#ifndef SPIDERVNACCEL_IMPL_TEST_CTESTUTIL_H_
#define SPIDERVNACCEL_IMPL_TEST_CTESTUTIL_H_

#include "spidervnAccel/interface/IUtil.h"

class CTestUtil {
public:
	CTestUtil();
	virtual ~CTestUtil();

	void runAll_Test();
protected:
	void testExcuteCmd();
	void testDirectory();

	void initialize_();
	void un_Initialize();
private:
	IDirectoryUtil* _pDir;
	ISystemUtil* _pSU_;
};

#endif /* SPIDERVNACCEL_IMPL_TEST_CTESTUTIL_H_ */
