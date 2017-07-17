#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <regex>
#include <boost/filesystem.hpp>

#include "comicutil.h"

using namespace std;
namespace bfs = boost::filesystem;

int ComicUtil::scanDir(const char* szDir, vector<string>& vComicDir, vector<string>& vChapterDir)
{
	DIR* pDir; 
	struct dirent* pEnt;
	struct stat stat_path;
	string sBaseDir;

	string stackDir[2000];
	int nStackDir = 0;
	int nDirType = DIR_TYPE_INVALID;

	vector<ComicDir> v_comic;
	vector<ChapterDir> v_chapter;

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

				// Parse comic info here
				ComicDir c_info;
				bfs::path p1(sBaseDir.c_str());


				c_info.dirName = sBaseDir;
				c_info.comicTitle = p1.filename().string(); // p1.parent_path().string();	// Todo: Get File Directory name here
											

				getImageFiles(sBaseDir.c_str(), 2, c_info.avatarList);

				std::sort(c_info.avatarList.begin(), c_info.avatarList.end());
				v_comic.push_back(c_info);
				
			} else if (nDirType == DIR_TYPE_CHAPTER) {
				vChapterDir.push_back(sBaseDir);
				bfs::path p1(sBaseDir.c_str());


				ChapterDir chap_info;

				chap_info.dirName = sBaseDir;
				chap_info.chapterName = p1.filename().string(); //p1.parent_path().string(); 	// Root directory

				getImageFiles(sBaseDir.c_str(), 1000, chap_info.imageFiles);
				
				std::sort(chap_info.imageFiles.begin(), chap_info.imageFiles.end());
				v_chapter.push_back(chap_info);
				
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
					// Do not scan inside since a Directory is a chapter 
					if (S_ISDIR(stat1F.st_mode) && strcmp("..",pEnt->d_name )!= 0 && strcmp(".", pEnt->d_name) != 0 && nDirType != DIR_TYPE_CHAPTER) {
						stackDir[nStackDir++] = sOneFile;
					}
				}

			}

		} else {
			// Temp code
			printf("Not dir %s\r\n", sBaseDir.c_str());
		}
	}

	printf("ComicList:\r\n");
	for (int i=0; i<v_comic.size(); i++) {
		printComic(v_comic[i]);
	}

	printf("ChapterList:\r\n");
	for (int i=0;i<v_chapter.size();i++) {
		printChapter(v_chapter[i]);
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

int ComicUtil::getImageFiles(const char* szDir,int limit ,vector<string>& vImg) {

	struct stat statDir;

	stat(szDir, &statDir);
	vImg.clear();

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
					if (isImageFile(pEnt->d_name) && vImg.size() < limit) {
						vImg.push_back(sFullPath);
					}
				}
			}	
		} else {
		}
	}
	else 
	{
		// Invalid
		return -1;
	}

	return 0;
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


void ComicUtil::printComic(ComicDir& comic)
{
	printf("Comic: \r\n\tDirectory: %s\r\n\tTitle: %s\r\n", comic.dirName.c_str(), comic.comicTitle.c_str());
	for (int i=0;i<comic.avatarList.size();i++) {
		printf("\t\t%d. %s\r\n", (i+1), comic.avatarList[i].c_str());
	}

}

void ComicUtil::printChapter(ChapterDir& chapter)
{
	printf("Chapter: \r\n\tDirectory: %s\r\n\tTitle: %s\r\n", chapter.dirName.c_str(), chapter.chapterName.c_str());
	printf("\tImages\r\n:");

	for (int i=0;i<chapter.imageFiles.size();i++) {
		printf("\t\t%d. %s\r\n", (i+1), chapter.imageFiles[i].c_str());
	}
}

