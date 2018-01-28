/*
 * CDirectoryUtil.cpp
 *
 *  Created on: Jan 26, 2018
 *      Author: ducvd
 */

#include "CDirectoryUtil.h"
#include <dirent.h>

using namespace std;

CDirectoryUtil::CDirectoryUtil() {
}

CDirectoryUtil::~CDirectoryUtil() {
}

int CDirectoryUtil::enumDir(std::string spath, std::vector<std::string>& vfile, std::vector<std::string>& vdir_)
{
	DIR *dir;
	struct dirent *ent;

	vfile.clear();
	vdir_.clear();

	if ((dir = opendir (spath.c_str())) != NULL)
	{
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL)
	  {
		  // printf ("%s\n", ent->d_name);
		  if (ent->d_type == DT_DIR)
		  {
			  vdir_.push_back(ent->d_name);
		  }
		  else if (ent->d_type == DT_REG || ent->d_type == DT_LNK)
		  {
			  vfile.push_back(ent->d_name);
		  }
	  }
	  closedir (dir);
	}
	else
	{
		return 1;
	}
	return 0;
}

std::string CDirectoryUtil::getBaseDir_(std::string spath)
{
	std::string s_Separator = "/";
	std::string::size_type idx;
	string res;

	idx = spath.rfind(s_Separator);

	if (idx == string::npos)
	{
		res = "";
	}
	else
	{
		res = spath.substr(0, idx);
	}

	return res;
}

std::string CDirectoryUtil::getFileName(std::string strFullPath)
{
	std::string s_Separator = "/";
	std::string::size_type idx;
	string res;

	idx = strFullPath.rfind(s_Separator);

	if (idx == string::npos)
	{
		res = strFullPath;
	}
	else
	{
		res = strFullPath.substr(idx + s_Separator.length());
	}

	return res;
}

std::string CDirectoryUtil::getFileExt_(std::string sFile)
{
	string s_Dot = ".";
	string res;
	string::size_type idx = sFile.rfind(s_Dot);

	if (idx == string::npos)
	{
		res = "";	// No extension
	}
	else
	{
		res = sFile.substr(idx + s_Dot.length());
	}

	return res;
}

string CDirectoryUtil::joinDirectory(std::string spath1, std::string spath2)
{
	string s_Separator = "/";
	string::size_type idx;
	string res;

	idx = spath1.rfind(s_Separator);
	if (idx != string::npos && idx  == spath1.length()-1)
	{
		res = spath1.substr(0, spath1.length() -1 ) + spath2;
	}
	else
	{
		res = spath1 + spath2;
	}

	return res;
}
