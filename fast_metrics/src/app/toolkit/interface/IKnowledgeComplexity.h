/*
 * IKnowledgeComplexity.h
 *
 *  Created on: May 2, 2018
 *      Author: spider
 */

#ifndef APP_TOOLKIT_INTERFACE_IKNOWLEDGECOMPLEXITY_H_
#define APP_TOOLKIT_INTERFACE_IKNOWLEDGECOMPLEXITY_H_

#include <string>
#include <vector>

class IKnowledgeComplexity
{
public:
	virtual ~IKnowledgeComplexity() {}
	virtual int distinctVocab(std::string content, std::vector<std::string>& v_Vocab) = 0;
};


#endif /* APP_TOOLKIT_INTERFACE_IKNOWLEDGECOMPLEXITY_H_ */
