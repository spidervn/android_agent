/*
 * ILinearApproach.h
 *
 *  Created on: Jan 6, 2018
 *      Author: spider
 */

#ifndef APP_ESTIMATION_INTERFACE_ILINEARAPPROACH_H_
#define APP_ESTIMATION_INTERFACE_ILINEARAPPROACH_H_

#include "IApproach.h"
#include "metrics/interface/linear/ICodebase.h"
#include "metrics/interface/linear/IUML.h"
#include "metrics/interface/linear/IDesignInterface.h"
#include "metrics/interface/linear/IDesignUnitTest.h"
#include "metrics/interface/linear/ICodeInterface.h"
#include "metrics/interface/linear/ICodeUnitTest.h"
#include "metrics/interface/linear/IKnowledgeFundamental.h"
#include "metrics/interface/linear/IRunUnitTest.h"
#include "metrics/interface/linear/INativeSystemTest.h"

class ILinearApproach : public IApproach
{
public:
	virtual ~ILinearApproach() {}
	virtual int define_Linear(
								ICodebase*,
								IKnowledgeFundamental*,
								IUML*,
								IDesignInterface*,
								IDesignUnitTest*,
								ICodeInterface*,
								ICodeUnitTest*,
								IRunUnitTest*,
								INativeSystemTest*) = 0;
};



#endif /* APP_ESTIMATION_INTERFACE_ILINEARAPPROACH_H_ */
