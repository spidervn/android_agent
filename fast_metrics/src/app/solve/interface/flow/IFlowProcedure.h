// IFlowProcedure.h
/*
 * ISerializer.h
 *
 *  Created on: Oct 30, 2018
 *      Author: spider
 */

#ifndef APP_SOLVE_INTERFACE_FLOW_IFLOWPROCEDURE_H_
#define APP_SOLVE_INTERFACE_FLOW_IFLOWPROCEDURE_H_

#include <string>
class IFLowProcedure
{
public:
    virtual ~IFLowProcedure();
    virtual std::string name() = 0;
};


#endif /* APP_SOLVE_INTERFACE_MODEL_IWHATEVER_H_ */
