/*
 * IApproach.h
 *
 *  Created on: Jan 5, 2018
 *      Author: ducvd
 */

#ifndef APP_ESTIMATION_INTERFACE_IAPPROACH_H_
#define APP_ESTIMATION_INTERFACE_IAPPROACH_H_

class IApproach
{
public:
	virtual ~IApproach();
	virtual long complexity() = 0;	
};

#endif /* APP_ESTIMATION_INTERFACE_IAPPROACH_H_ */
