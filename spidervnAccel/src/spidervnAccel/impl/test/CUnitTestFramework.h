/*
 * CUnitTestUtil.h
 *
 *  Created on: Jan 27, 2018
 *      Author: spider
 */

#ifndef SPIDERVNACCEL_IMPL_TEST_CUNITTESTFRAMEWORK_H_
#define SPIDERVNACCEL_IMPL_TEST_CUNITTESTFRAMEWORK_H_

#include <string>

class CUnitTestFramework {
public:
	CUnitTestFramework();
	virtual ~CUnitTestFramework();

	static void assert(bool b, std::string errmsg);
};

#endif /* SPIDERVNACCEL_IMPL_TEST_CUNITTESTFRAMEWORK_H_ */
