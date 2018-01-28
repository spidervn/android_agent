/*
 * CCommander.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: ducvd
 */

#include "CCommander.h"
#include "CSystemUtil.h"
#include "CDirectoryUtil.h"

CCommander::CCommander() 
{
	// TODO Auto-generated constructor stub
}

CCommander::~CCommander() 
{
	// TODO Auto-generated destructor stub
}

int CCommander::extract_AllArchiveComic(std::string sPath)
{
	/*
	 * EAC1. Find all archive file
	 * EAC2. Each archive file, extract it to currentFolder
	 */
	IDirectoryUtil* pDu;
	ISystemUtil* pSu;

	pDu = new CDirectoryUtil();
	pSu = new CSystemUtil();



	return 0;
}

int CCommander::prepare_bulk_upload(std::string sExtractedComicPath)
{
	return 0;
}
