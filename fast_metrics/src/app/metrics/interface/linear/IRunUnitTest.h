/*
 * IRunUnitTest.h
 *
 *  Created on: Jan 5, 2018
 *      Author: ducvd
 */

#ifndef APP_METRICS_INTERFACE_IRUNUNITTEST_H_
#define APP_METRICS_INTERFACE_IRUNUNITTEST_H_

class IRunUnitTest
{
public:
	virtual ~IRunUnitTest() {}
	virtual long complexity_() = 0;
};



#endif /* APP_METRICS_INTERFACE_IRUNUNITTEST_H_ */
