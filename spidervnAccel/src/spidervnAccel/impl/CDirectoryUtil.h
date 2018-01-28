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
	std::string getBaseDir_(std::string spath);
	std::string getFileName(std::string strFullPath);
	std::string getFileExt_(std::string sFile);
	std::string joinDirectory(std::string spath1, std::string spath2);
};

#endif /* SPIDERVNACCEL_IMPL_CDIRECTORYUTIL_H_ */
