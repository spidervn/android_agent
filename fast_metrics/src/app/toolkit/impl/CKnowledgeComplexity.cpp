/*
 * CKnowledgeComplexity.cpp
 *
 *  Created on: May 2, 2018
 *      Author: spider
 */

#include <app/toolkit/impl/CKnowledgeComplexity.h>

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

CKnowledgeComplexity::CKnowledgeComplexity() {
	// TODO Auto-generated constructor stub

}

CKnowledgeComplexity::~CKnowledgeComplexity() {
	// TODO Auto-generated destructor stub
}

int CKnowledgeComplexity::distinctVocab(std::string content, std::vector<std::string>& v_Vocab)
{
	/*
	 * State machine?
	 *
	 */

	int STT_START__ = 0;
	int STT_END  = 1;
	int STT_BEGINWORD = 2;
	int STT_ENDWORD = 3;

	int state = STT_START__;
	string currentWord = "";
	string word_Lower_;

	for (int i=0;i<=content.size();i++)
	{
		// The last check
		if (i==content.size())
		{
			//
			if (state == STT_BEGINWORD)
			{
				// Yield the word now
				std::transform(currentWord.begin(), currentWord.end(), currentWord.begin(), CKnowledgeComplexity::easytolower);

				if (std::find(v_Vocab.begin(), v_Vocab.end(), currentWord) == v_Vocab.end())
				{
					v_Vocab.push_back(currentWord);
					// printf("Last Newword=%s; At Position %d; TextAround=%s\r\n", currentWord.c_str(), i, content.substr(i-5, 10).c_str());
				}
			}

			state = STT_END;
		}
		else
		{
			char ch = content[i];
			if (state == STT_START__)
			{
				 if ((ch >= 'a' && ch <= 'z') || ( ch >= 'A' && ch <= 'Z' ))
				 {
					 state = STT_BEGINWORD;
					 currentWord = ch;
				 }
				 else
				 {
					 state = STT_ENDWORD;
				 }
			}
			else if (state == STT_BEGINWORD)
			{
				if ((ch >= 'a' && ch <= 'z') || ( ch >= 'A' && ch <= 'Z' ) || ch=='-')	// Note "-" is linking character
				{
					currentWord += ch;
				}
				else
				{
					state = STT_ENDWORD;

					// Yield the word now
					std::transform(currentWord.begin(), currentWord.end(), currentWord.begin(), CKnowledgeComplexity::easytolower);

					if (std::find(v_Vocab.begin(), v_Vocab.end(), currentWord) == v_Vocab.end())
					{
						v_Vocab.push_back(currentWord);
						// printf("Newword=%s; At Position %d; TextAround=%s\r\n", currentWord.c_str(), i, content.substr(i-5, 10).c_str());
					}
				}
			}
			else if (state == STT_ENDWORD)
			{
				if ((ch >= 'a' && ch <= 'z') || ( ch >= 'A' && ch <= 'Z' ))
				{
					 state = STT_BEGINWORD;
					 currentWord = ch;
				}
				else
				{
					 state = STT_ENDWORD;
				}
			}
			else
			{
				printf("Abnormal cases**********************************\r\n");
			}
		}
	}

	std::sort(v_Vocab.begin(), v_Vocab.end());
	return 0;
}


char CKnowledgeComplexity::easytolower(char in) {
  if(in <= 'Z' && in >= 'A')
    return in - ('Z' - 'z');
  return in;
}
