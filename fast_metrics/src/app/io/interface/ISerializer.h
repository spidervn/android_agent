/*
 * ISerializer.h
 *
 *  Created on: Jan 6, 2018
 *      Author: spider
 */

#ifndef APP_IO_INTERFACE_ISERIALIZER_H_
#define APP_IO_INTERFACE_ISERIALIZER_H_

#include "estimation/interface/IApproach.h"

class ISerializer
{
public:
	virtual ~ISerializer() {}

	virtual int saveToFile(IApproach* , const char* ) = 0;
	virtual int loadFromFile(const char* , IApproach*) = 0;
};


#endif /* APP_IO_INTERFACE_ISERIALIZER_H_ */
