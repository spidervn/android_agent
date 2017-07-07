#ifndef _COMIC_UTIL_H_
#define  _COMIC_UTIL_H_

#include <string>

typedef struct ComicDir_Struct {
	std::string dirName;
	std::string comicTitle;
	
	std::vector<std::string> chapterDirs;	// Chapter children
	std::vector<std::string> avatarList;		// List of avatars 
	
} ComicDir;

typedef struct ChapterDir_Struct {
	std::string dirName;
	std::string chapterName;

	std::vector<std::string> imageFiles;
} ChapterDir;

class ComicUtil 
{
public:
	static const int DIR_TYPE_CHAPTER = 0;
	static const int DIR_TYPE_COMIC = 1;
	static const int DIR_TYPE_NORMAL = 2;

	ComicUtil() {};

	int scanDir(const char* szDir);
};

#endif

