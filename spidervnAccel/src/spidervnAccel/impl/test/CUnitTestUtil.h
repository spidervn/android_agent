/*
 * CUnitTestUtil.h
 *
 *  Created on: Jan 27, 2018
 *      Author: spider
 */

#ifndef SPIDERVNACCEL_IMPL_TEST_CUNITTESTUTIL_H_
#define SPIDERVNACCEL_IMPL_TEST_CUNITTESTUTIL_H_

#include <string>

class CUnitTestUtil {
public:
	CUnitTestUtil();
	virtual ~CUnitTestUtil();

	static void assert(bool b, std::string errmsg);
};

#endif /* SPIDERVNACCEL_IMPL_TEST_CUNITTESTUTIL_H_ */
