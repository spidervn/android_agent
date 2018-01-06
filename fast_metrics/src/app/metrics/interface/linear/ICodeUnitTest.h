/*
 * ICodeUnitTest.h
 *
 *  Created on: Jan 5, 2018
 *      Author: ducvd
 */

#ifndef APP_METRICS_INTERFACE_ICODEUNITTEST_H_
#define APP_METRICS_INTERFACE_ICODEUNITTEST_H_

class ICodeUnitTest
{
public:
	virtual ~ICodeUnitTest() {}
	virtual long complexity_() = 0;
	
};



#endif /* APP_METRICS_INTERFACE_ICODEUNITTEST_H_ */
