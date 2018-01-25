/*
 * IArchiveExtrator.h
 *
 *  Created on: Jan 25, 2018
 *      Author: ducvd
 */

#ifndef SPIDERVNACCEL_INTERFACE_IARCHIVEEXTRATOR_H_
#define SPIDERVNACCEL_INTERFACE_IARCHIVEEXTRATOR_H_

#include <string>

class IArchiveExtrator
{
public:
	virtual ~IArchiveExtrator() {}

	virtual int extract_Archive__(std::string fileArchive, std::string dir_Out) = 0;
	virtual bool isArchiveFile(std::string sfile) = 0;
};


#endif /* SPIDERVNACCEL_INTERFACE_IARCHIVEEXTRATOR_H_ */
