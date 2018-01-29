/*
 * CCommander.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: ducvd
 */

#include "CCommander.h"
#include "CSystemUtil.h"
#include "CDirectoryUtil.h"
#include "spidervnAccel/impl/CSystemUtil.h"
#include "spidervnAccel/impl/CDirectoryUtil.h"
#include "spidervnAccel/impl/CArchiveExtractor.h"

#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

CCommander::CCommander() 
{
	pDu = new CDirectoryUtil();
	pSu = new CSystemUtil();
	pExtractor_ = new CArchiveExtractor(pDu);
}

CCommander::~CCommander() 
{
	delete pDu;
	delete pSu;
	delete pExtractor_;
}

int CCommander::preRequisiteCheck()	// Check whether
{
	return 0;
}

int CCommander::extract_AllArchiveComic(std::string sPath)
{
	/*
	 * EAC1. Find all archive file
	 * EAC2. Each archive file, extract it to currentFolder
	 */
	string s_Path = ".";
	string sNameTrunc;
	string sExtractTo_;
	string sChoice = "";
	int nInc = 0;
	char szTmp[13];
	vector<string> vDir_;
	vector<string> vFile;

	vector<string> vExtractFrom_;
	vector<string> vExtractTo_;

	if (pDu->enumDir(s_Path, vFile, vDir_) == 0)
	{
		for (unsigned int i=0; i<vFile.size(); i++)
		{
			if (pExtractor_->isArchiveFile(vFile[i]))
			{
				// Directory out = Filename without extension
				sNameTrunc = pDu->truncFileExt_(vFile[i]);
				sExtractTo_ = sNameTrunc;

				while (pDu->isExist(pDu->joinDirectory(sPath,sExtractTo_)))
				{
					sprintf(szTmp, "00%d", nInc++);
					sExtractTo_ = sNameTrunc + szTmp;
				}

				vExtractFrom_.push_back(pDu->joinDirectory(sPath, vFile[i]));
				vExtractTo_.push_back(pDu->joinDirectory(sPath, sExtractTo_));

				//
				// printf("Extract from %s to %s\r\n", pDu->joinDirectory(sPath, vFile[i]).c_str(),
				//		pDu->joinDirectory(sPath, sExtractTo_).c_str());
				// pExtractor_->extract_Archive__(pDu->joinDirectory(sPath, vFile[i]), pDu->joinDirectory(sPath, sExtractTo_));
				//
			}
		}
		printf("The following archive comic files will be extracted:\r\n");
		for (unsigned int i=0;i<vExtractFrom_.size();i++)
		{
			printf("\t%d. Archive file %s will be extracted to %s\r\n", (i+1), vExtractFrom_[i].c_str(), vExtractTo_[i].c_str());
		}

		while (!(sChoice == "y" || sChoice == "Y" || sChoice=="n" || sChoice=="N"))
		{
			printf("Do you want to proceed (Y/N)?");
			std::cin >> sChoice;
		}

		printf("Your answer is %s\r\n", sChoice.c_str());
		if (sChoice == "y" || sChoice == "Y")
		{
			for (unsigned int i=0;i<vExtractFrom_.size();i++)
			{
				printf("%d. Extracting from %s to %s\r\n", (i+1), vExtractFrom_[i].c_str(), vExtractTo_[i].c_str());
				pExtractor_->extract_Archive__(vExtractFrom_[i], vExtractTo_[i]);
				printf("\tFinish!\r\n");
			}
		}

	}

	return 0;
}

int CCommander::prepare_bulk_upload(std::string sExtractedComicPath)
{
	/*
	 * PBU1. Check preRequisite
	 * 			bulk_make_quality.sh
	 *			make_comic_avatar.sh
	 *			make_image_quality.sh
	 * PBU2.
	 * 			Run bulk_make_quality.sh
	 * PBU3.
	 *			For each ExtractedComicFolder
	 *				Create an ComicInfo folder
	 */

	return 0;
}
