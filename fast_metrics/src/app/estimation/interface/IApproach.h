/*
 * IApproach.h
 *
 *  Created on: Jan 5, 2018
 *      Author: ducvd
 */

#ifndef APP_ESTIMATION_INTERFACE_IAPPROACH_H_
#define APP_ESTIMATION_INTERFACE_IAPPROACH_H_

#define APPROACH_LINE_OF_CODE 1	// Just count line of code
#define APPROACH_WELL_KNOWN 2	// Every task must well known; Any non-wellknown task is not acceptable
#define APPROACH_SAFETY	3		// Safety <=> Want to know everything 
								//	Including 
								// 		Well-know tasks| Non-Well Known | Unknown | Unknown of Unknown
#define APPROACH_VERY_FIRST	4	// Approach from the very first idea
#define APPROACH_WORKER_VILLAGER 5	// Most dummy method (Linear)
									
class IApproach
{
public:
	virtual ~IApproach();
	virtual long complexity_() = 0;
};

#endif /* APP_ESTIMATION_INTERFACE_IAPPROACH_H_ */