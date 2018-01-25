/*
 * CDirectoryUtil.h
 *
 *  Created on: Jan 26, 2018
 *      Author: ducvd
 */

#ifndef SPIDERVNACCEL_IMPL_CDIRECTORYUTIL_H_
#define SPIDERVNACCEL_IMPL_CDIRECTORYUTIL_H_

#include <spidervnAccel/interface/IUtil.h>

class CDirectoryUtil: public IDirectoryUtil {
public:
	CDirectoryUtil();
	virtual ~CDirectoryUtil();

	int enumDir(std::string spath, std::vector<std::string>& vfile, std::vector<std::string>& vdir);
};

#endif /* SPIDERVNACCEL_IMPL_CDIRECTORYUTIL_H_ */
