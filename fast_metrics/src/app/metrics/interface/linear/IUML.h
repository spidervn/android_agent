/*
 * IUML.h
 *
 *  Created on: Jan 5, 2018
 *      Author: ducvd
 */

#ifndef APP_METRICS_INTERFACE_IUML_H_
#define APP_METRICS_INTERFACE_IUML_H_

class IUML
{
public:
	virtual ~IUML() {}
	virtual long complexity_() = 0;
};


#endif /* APP_METRICS_INTERFACE_IUML_H_ */
