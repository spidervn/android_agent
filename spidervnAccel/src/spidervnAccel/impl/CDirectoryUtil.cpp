/*
 * CDirectoryUtil.cpp
 *
 *  Created on: Jan 26, 2018
 *      Author: ducvd
 */

#include "CDirectoryUtil.h"
#include <dirent.h>

CDirectoryUtil::CDirectoryUtil() {
	// TODO Auto-generated constructor stub

}

CDirectoryUtil::~CDirectoryUtil() {
	// TODO Auto-generated destructor stub
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
