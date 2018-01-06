/*
 * IDesignUnitTest.h
 *
 *  Created on: Jan 5, 2018
 *      Author: ducvd
 */

#ifndef APP_METRICS_INTERFACE_IDESIGNUNITTEST_H_
#define APP_METRICS_INTERFACE_IDESIGNUNITTEST_H_


class IDesignUnitTest
{
public:
	virtual ~IDesignUnitTest() {}
	virtual long complexity_() = 0;
};


#endif /* APP_METRICS_INTERFACE_IDESIGNUNITTEST_H_ */
