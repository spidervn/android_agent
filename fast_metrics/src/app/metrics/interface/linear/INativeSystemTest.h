/*
 * INativeSystemTest.h
 *
 *  Created on: Jan 5, 2018
 *      Author: ducvd
 */

#ifndef APP_METRICS_INTERFACE_INATIVESYSTEMTEST_H_
#define APP_METRICS_INTERFACE_INATIVESYSTEMTEST_H_


class INativeSystemTest
{
public:
	virtual ~INativeSystemTest() {}
	virtual long complexity_() = 0;	
};


#endif /* APP_METRICS_INTERFACE_INATIVESYSTEMTEST_H_ */
