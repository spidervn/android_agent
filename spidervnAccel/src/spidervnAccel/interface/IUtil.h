/*
 * IUtil.h
 *
 *  Created on: Jan 25, 2018
 *      Author: ducvd
 */

#ifndef SPIDERVNACCEL_INTERFACE_IUTIL_H_
#define SPIDERVNACCEL_INTERFACE_IUTIL_H_

#include <string>
#include <vector>

class ISystemUtil
{
public:
	virtual ~ISystemUtil() {}

	virtual std::string exe_Cmd(std::string cmd) = 0;
};

class IDirectoryUtil
{
public:
	virtual ~IDirectoryUtil() {}

	virtual int enumDir(std::string spath, std::vector<std::string>& vfile, std::vector<std::string>& vdir) = 0;

	virtual std::string getBaseDir_(std::string spath) = 0;
	virtual std::string getFileName(std::string strFullPath) = 0;
	virtual std::string getFileExt_(std::string sFile) = 0;
	virtual std::string joinDirectory(std::string spath1, std::string spath2) = 0;
};


#endif /* SPIDERVNACCEL_INTERFACE_IUTIL_H_ */
