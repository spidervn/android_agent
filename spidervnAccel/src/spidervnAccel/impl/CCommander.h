/*
 * CCommander.h
 *
 *  Created on: Jan 25, 2018
 *      Author: ducvd
 */

#ifndef SPIDERVNACCEL_IMPL_CCOMMANDER_H_
#define SPIDERVNACCEL_IMPL_CCOMMANDER_H_

#include "spidervnAccel/interface/ICommander.h"

class CCommander: public ICommander {
public:
	CCommander();
	virtual ~CCommander();

	int extract_AllArchiveComic(std::string sPath);
	int prepare_bulk_upload(std::string sExtractedComicPath);
};

#endif /* SPIDERVNACCEL_IMPL_CCOMMANDER_H_ */
