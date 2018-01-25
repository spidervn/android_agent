/*
 * CSystemUtil.h
 *
 *  Created on: Jan 26, 2018
 *      Author: ducvd
 */

#ifndef SPIDERVNACCEL_IMPL_CSYSTEMUTIL_H_
#define SPIDERVNACCEL_IMPL_CSYSTEMUTIL_H_

#include <spidervnAccel/interface/IUtil.h>

class CSystemUtil: public ISystemUtil {
public:
	CSystemUtil();
	virtual ~CSystemUtil();

	std::string exe_Cmd(std::string cmd);
};

#endif /* SPIDERVNACCEL_IMPL_CSYSTEMUTIL_H_ */
