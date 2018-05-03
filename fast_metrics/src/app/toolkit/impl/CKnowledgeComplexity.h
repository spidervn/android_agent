/*
 * CKnowledgeComplexity.h
 *
 *  Created on: May 2, 2018
 *      Author: spider
 */

#ifndef APP_TOOLKIT_IMPL_CKNOWLEDGECOMPLEXITY_H_
#define APP_TOOLKIT_IMPL_CKNOWLEDGECOMPLEXITY_H_

#include <toolkit/interface/IKnowledgeComplexity.h>

class CKnowledgeComplexity: public IKnowledgeComplexity {
public:
	CKnowledgeComplexity();
	virtual ~CKnowledgeComplexity();

	int distinctVocab(std::string content, std::vector<std::string>& v_Vocab);

protected:
	static char easytolower(char in);
};

#endif /* APP_TOOLKIT_IMPL_CKNOWLEDGECOMPLEXITY_H_ */
