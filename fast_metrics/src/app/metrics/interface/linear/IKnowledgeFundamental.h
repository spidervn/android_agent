/*
 * IKnowledgeFundamental.h
 *
 *  Created on: Jan 5, 2018
 *      Author: ducvd
 */

#ifndef APP_METRICS_INTERFACE_IKNOWLEDGEFUNDAMENTAL_H_
#define APP_METRICS_INTERFACE_IKNOWLEDGEFUNDAMENTAL_H_

#include "IKnowledgeUnit.h"

class IKnowledgeFundamental
{
public:
	virtual ~IKnowledgeFundamental() {}
	virtual int addUnit(IKnowledgeUnit*) = 0;
	virtual long complexity_() = 0;
};


#endif /* APP_METRICS_INTERFACE_IKNOWLEDGEFUNDAMENTAL_H_ */
