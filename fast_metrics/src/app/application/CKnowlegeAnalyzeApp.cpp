/*
 * CKnowlegeAnalyzeApp.cpp
 *
 *  Created on: May 2, 2018
 *      Author: spider
 */

#include <application/CKnowlegeAnalyzeApp.h>

#include "toolkit/impl/CKnowledgeComplexity.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

CKnowlegeAnalyzeApp::CKnowlegeAnalyzeApp() {
}

CKnowlegeAnalyzeApp::~CKnowlegeAnalyzeApp() {
}

void CKnowlegeAnalyzeApp::run(int argc, char* argv[])
{
	if (argc < 2)
	{
		return;
	}

	string wholeFile = "";
	string line;

	ifstream myfile (argv[1]);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			wholeFile += line;
		}
		myfile.close();
	}

	vector<string> v_Vocab;
	IKnowledgeComplexity* pComplex;
	pComplex = new CKnowledgeComplexity();
	pComplex->distinctVocab(wholeFile, v_Vocab);

	for (size_t i=0; i<v_Vocab.size(); i++)
	{
		printf("Word[%d]=%s\r\n", (int)(i+1), v_Vocab[i].c_str());
	}
}
