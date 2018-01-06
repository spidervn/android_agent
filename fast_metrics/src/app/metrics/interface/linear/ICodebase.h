/*
 * ICodebase.h
 *
 *  Created on: Jan 5, 2018
 *      Author: ducvd
 */

#ifndef APP_METRICS_INTERFACE_ICODEBASE_H_
#define APP_METRICS_INTERFACE_ICODEBASE_H_

class ICodebase
{
public:
	virtual ~ICodebase() {}
	virtual long line_OfCode() = 0;
	virtual long count_Classes() = 0;
	virtual long count_Methods() = 0;	
};

#endif /* APP_METRICS_INTERFACE_ICODEBASE_H_ */
