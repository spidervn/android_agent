/*
 * CArchiveExtractor.cpp
 *
 *  Created on: Jan 26, 2018
 *      Author: ducvd
 */

#include "CArchiveExtractor.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>

#include "CSystemUtil.h"

using namespace std;

CArchiveExtractor::CArchiveExtractor(IDirectoryUtil* dirUtil)
{
	_pDir = dirUtil;
	pSystem = new CSystemUtil();
}

CArchiveExtractor::~CArchiveExtractor()
{
	delete pSystem;
}

int CArchiveExtractor::extract_Archive__(std::string fileArchive, std::string dir_Out)
{
	vector<string> vfile;
	vector<string> vdir_;
	int nRet_ = 0;
	string fileExt; // File extension
	string baseDir;
	string file_Name__;
	string ext04;
	string ext07;
	string cmd;
	char szTmp[255];

	if (isArchiveFile(fileArchive))
	{
		fileExt = _pDir->getFileExt_(fileArchive);
		baseDir = _pDir->getBaseDir_(fileArchive);
		file_Name__ = _pDir->getFileName(fileArchive);

		ext04 = file_Name__.substr(file_Name__.length() >= 4 ? file_Name__.length() - 4 : 0, 4 );
		ext07 = file_Name__.substr(file_Name__.length() >= 7 ? file_Name__.length() - 7 : 0, 7);

		std::transform(ext04.begin(), ext04.end(), ext04.begin(), ::tolower);
		std::transform(ext07.begin(), ext07.end(), ext07.begin(), ::tolower);

		if (ext04 == ".tar" || ext07 == ".tar.gz")
		{
			sprintf(szTmp, "tar -xf \"%s\" --directory \"%s\"", fileArchive.c_str(), dir_Out.c_str());
			cmd = szTmp;
		}
		else if (ext04 == ".zip")
		{
			sprintf(szTmp, "unzip \"%s\" -d \"%s\"", fileArchive.c_str(), dir_Out.c_str());
			cmd = szTmp;
		}
		else if (ext04==".cbz" || ext04 == ".cbr")
		{
			sprintf(szTmp, "7z \"%s\" -d \"%s\"", fileArchive.c_str(), dir_Out.c_str());
			cmd = szTmp;
		}

		printf("Execute cmd: %s\r\n", cmd.c_str());
		// pSystem->exe_Cmd(cmd);
	}

	return nRet_;
}

bool CArchiveExtractor::isArchiveFile(std::string sfile)
{
	string ext04;
	string ext07;

	ext04 = sfile.substr(sfile.length() >= 4 ? sfile.length() - 4 : 0, 4);
	ext07 = sfile.substr(sfile.length() >= 7 ? sfile.length() - 7 : 0, 7);

	std::transform(ext04.begin(), ext04.end(), ext04.begin(), ::tolower);
	std::transform(ext07.begin(), ext07.end(), ext07.begin(), ::tolower);

	return ext04 == ".tar" || ext07 == ".tar.gz" ||
			ext04 == ".zip" ||
			ext04==".cbz" || ext04 == ".cbr";
}
