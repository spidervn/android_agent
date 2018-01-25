/*
 * CArchiveExtractor.h
 *
 *  Created on: Jan 26, 2018
 *      Author: ducvd
 */

#ifndef SPIDERVNACCEL_IMPL_CARCHIVEEXTRACTOR_H_
#define SPIDERVNACCEL_IMPL_CARCHIVEEXTRACTOR_H_

#include <spidervnAccel/interface/IArchiveExtrator.h>
#include "spidervnAccel/interface/IUtil.h"
#include "spidervnAccel/interface/IUtil.h"

class CArchiveExtractor: public IArchiveExtrator {
public:
	CArchiveExtractor(IDirectoryUtil* dirUtil);
	virtual ~CArchiveExtractor();

	int extract_Archive__(std::string fileArchive, std::string dir_Out);
	bool isArchiveFile(std::string sfile);

private:
	IDirectoryUtil* _pDir;
	ISystemUtil* pSystem;
};

#endif /* SPIDERVNACCEL_IMPL_CARCHIVEEXTRACTOR_H_ */
