#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <regex>

#include "comicutil.h"

using namespace std;
int ComicUtil::scandir(const char* szDir)
{
	DIR* pDir; 
	struct dirent* pEnt;
	struct stat stat_path;
	string sBaseDir;
	vector<string> vComicDir; 
	vector<string> vChapterDir;

	string stackDir[2000];
	int nStackDir = 0;
	

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

		// Check this dir 		
		stat(sBaseDir.c_str(), &path_stat);

		if (S_ISDIR(path_stat.st_mode)) {
			// Scan content 
			if ((pDir = opendir(sBaseDir.c_str())) != NULL) 
			{
				while ((pEnt = readdir(pDir) != NULL)	
				{
					string sOneFile = sBaseDir + "/" + pDir->d_name;
					struct stat stat1F;

					stat(sOneFile.c_str(), &stat1F);
					

					if (sOneFile.c_str()) {					
					}
				}

			}

			if (p

		} else if (S_ISREG(path_stat.st_mode)) {
			// Ignore			
			prinf("Invalid directory");
		} else {
			// Failed
		}	
	}

	pDir = opendir(szDir);
	while (nStackDir > 0) 
	{

	}

	if ((pDir = opendir(szDir)) != NULL) 
	{
		while ((pEnt = readdir(pDir)) != NULL) 
		{
			string sFullPath = string("") + szDir + "/" + pEnt->d_name;
	
					
			// Full path 
		}
	}

	return 0;
}


int ComicUtil::checkOneDir(const* char szDir) 
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

		if((pDir = opendir(szDir)) != NULL)) 
		{
			while ((pEnt = readdir(pDir)) != NULL) 
			{
				string sFullPath = string("") + szDir + "/" + pEnt->d_name;
				if (isFile(pEnt->d_name) && isImageFile(pEnt->d_name)) 
				{	
															if (isImageFile(pEnt->d_name)
						nCountImg++;
					else 
						nCountOther++;
				}
			}	
		}
	}
	else 
	{
		// Invalid
		return -1;
	}


	if (nCountImg >= 10 && nCountOther < 5) {
		return DIR_TYPE_CHAPTER;
	} else if (nCountImg < 10 && nCountOther < 5) {
		return DIR_TYPE_COMIC;
	} else {
		return DIR_TYPE_NORMAL;
	}

	return DIR_TYPE_INVALID;
}

bool ComicUtil::isImageFile(const char* szFile) 
{
	regex extReg("(.jpg|.png|.jpeg|.gif)$", regex_constants::icase);

	return regex_search(szFile, extReg);
}
