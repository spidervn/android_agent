/*
 * CSerializer.h
 *
 *  Created on: Jan 6, 2018
 *      Author: spider
 */

#ifndef APP_IO_IMPL_CSERIALIZER_H_
#define APP_IO_IMPL_CSERIALIZER_H_

#include "io/interface/ISerializer.h"
#include "estimation/interface/IApproach.h"

class CSerializer: public ISerializer {
public:
	CSerializer();
	~CSerializer();

	int saveToFile(IApproach* , const char* );
	int loadFromFile(const char* , IApproach*);
};

#endif /* APP_IO_IMPL_CSERIALIZER_H_ */
