
/*
 *
 *  Created on: Oct 30, 2018
 *      Author: spider
 */

#ifndef APP_COMPLETED_INTERFACE_INFORMATION_IANEVENT_H_
#define APP_COMPLETED_INTERFACE_INFORMATION_IANEVENT_H_

#include <string>
class IAnEvent
{
public:
    virtual ~IAnEvent();
    virtual std::string name() = 0;
};


#endif /* APP_SOLVE_INTERFACE_MODEL_IWHATEVER_H_ */
