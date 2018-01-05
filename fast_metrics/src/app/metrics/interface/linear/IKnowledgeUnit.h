/*
 * IKnowledgeUnit.h
 *
 *  Created on: Jan 5, 2018
 *      Author: ducvd
 */

#ifndef APP_METRICS_INTERFACE_IKNOWLEDGEUNIT_H_
#define APP_METRICS_INTERFACE_IKNOWLEDGEUNIT_H_


class IKnowledgeUnit
{
public:
	virtual ~IKnowledgeUnit() {}
	virtual long numberOfSentences() = 0;	// Count number of sentences
	virtual long number_A4Page() = 0;		// Count by pages
	virtual long number_Conclusion() = 0;
};


#endif /* APP_METRICS_INTERFACE_IKNOWLEDGEUNIT_H_ */
