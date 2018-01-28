/*
 * CSystemUtil.cpp
 *
 *  Created on: Jan 26, 2018
 *      Author: ducvd
 */

#include <spidervnAccel/impl/CSystemUtil.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

using namespace std;

CSystemUtil::CSystemUtil() {
	// TODO Auto-generated constructor stub

}

CSystemUtil::~CSystemUtil() {
	// TODO Auto-generated destructor stub
}

std::string CSystemUtil::exe_Cmd(std::string cmd)
{
	std::array<char, 128> buffer;
	std::string result;
	std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
	if (!pipe)
		throw std::runtime_error("popen() failed!");
	while (!feof(pipe.get())) {
		if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
			result += buffer.data();
	}
	return result;
}
