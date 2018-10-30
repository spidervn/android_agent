/*
 * ISerializer.h
 *
 *  Created on: Oct 30, 2018
 *      Author: spider
 */

#ifndef APP_SOLVE_INTERFACE_MODEL_IWHATEVER_H_
#define APP_SOLVE_INTERFACE_MODEL_IWHATEVER_H_

#include <string>
class IWhatever
{
public:
    virtual ~IWhatever();
    virtual std::string name() = 0;
};


#endif /* APP_SOLVE_INTERFACE_MODEL_IWHATEVER_H_ */
