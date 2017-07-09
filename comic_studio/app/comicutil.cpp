#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <regex>

#include "comicutil.h"

using namespace std;
int ComicUtil::scanDir(const char* szDir, vector<string>& vComicDir, vector<string>& vChapterDir)
{
	DIR* pDir; 
	struct dirent* pEnt;
	struct stat stat_path;
	string sBaseDir;

	string stackDir[2000];
	int nStackDir = 0;
	int nDirType = DIR_TYPE_INVALID;
	

	// 
	// Chapter dir = chapter that there's at least 10 images and less than 4 other types files
	//	i) A directory
	//	ii) >= 10 child images
	//	iii) there're not too much other files types but images (<4 others file type; all image files type are ok)
	//
	// Comic dir = Comic that contains at least 01 chapter 
	// 	i) A directory 
	// 	ii) < 10 child images
	//

	// Enum all directories first 
	pDir = opendir(szDir);
	stackDir[nStackDir++] = szDir;

	while (nStackDir > 0) {
		string sBaseDir = stackDir[--nStackDir];

		// Temp code
		printf("Checking %s\r\n", sBaseDir.c_str());

		// Check this dir 		
		stat(sBaseDir.c_str(), &stat_path);

		if (S_ISDIR(stat_path.st_mode)) {

			nDirType = checkDirType(sBaseDir.c_str());

			// Temp code
			printf("%s = %d\r\n", sBaseDir.c_str(), nDirType);

			if (nDirType == DIR_TYPE_COMIC) {
				vComicDir.push_back(sBaseDir);
			} else if (nDirType == DIR_TYPE_CHAPTER) {
				vChapterDir.push_back(sBaseDir);
			}

			// Scan all sub directory
			if ((pDir = opendir(sBaseDir.c_str())) != NULL) 
			{
				while ((pEnt = readdir(pDir)) != NULL)
				{
					string sOneFile = sBaseDir + "/" + pEnt->d_name;
					struct stat stat1F;

					stat(sOneFile.c_str(), &stat1F);

					// Push into Stack 
					if (S_ISDIR(stat1F.st_mode) && strcmp("..",pEnt->d_name )!= 0 && strcmp(".", pEnt->d_name) != 0) {
						stackDir[nStackDir++] = sOneFile;
					}
				}

			}

		} else {
			// Temp code
			printf("Not dir %s\r\n", sBaseDir.c_str());
		}
	}
	return 0;
}


int ComicUtil::checkDirType(const char* szDir) 
{
	/*
	 * return Dir type 
	 * 	1. Normal dir
	 * 	2. Comic dir
	 * 	3. Chapter dir
	 * 	-1. Invalid
	 */


	// Checking all of its cotents (Not recursive)
	//
	int nRet = -1;
	int nCountImg = 0;			// Counting number of image
	int nCountOther = 0;			// Counting number of other files
	struct stat statDir;

	stat(szDir, &statDir);

	if (S_ISDIR(statDir.st_mode)) 
	{
		// IS_DIR
		DIR* pDir;
		struct dirent* pEnt;

		if((pDir = opendir(szDir)) != NULL) 
		{
			while ((pEnt = readdir(pDir)) != NULL) 
			{
				string sFullPath = string("") + szDir + "/" + pEnt->d_name;
				if (isFile(sFullPath.c_str()) && isImageFile(sFullPath.c_str())) 
				{
					if (isImageFile(pEnt->d_name))
						nCountImg++;
					else 
						nCountOther++;
				}
			}	
		} else {
			printf("HERE 2 %s\r\n", szDir);
		}
	}
	else 
	{
		// Invalid
		printf("HERE \r\n");
		return -1;
	}


	if (nCountImg >= 10 && nCountOther < 5 + 2) {
		return DIR_TYPE_CHAPTER;
	} else if (nCountImg < 10 && nCountOther < 5 + 2) {
		return DIR_TYPE_COMIC;
	} else {		

		printf("Dir Type %s: %d; %d\r\n", szDir, nCountImg, nCountOther);

		return DIR_TYPE_NORMAL;
	}

	return DIR_TYPE_INVALID;
}

bool ComicUtil::isFile(const char* szFile) 
{
	struct stat stat1;

	stat(szFile, &stat1);

	return S_ISREG(stat1.st_mode);
}

bool ComicUtil::isImageFile(const char* szFile) 
{
	regex extReg("(.jpg|.png|.jpeg|.gif)$", regex_constants::icase);

	return regex_search(szFile, extReg);
}
