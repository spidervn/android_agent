#include <iostream>
using namespace std;

#include "app/estimation/interface/ILinearApproach.h"
#include "app/io/interface/ISerializer.h"
#include "app/toolkit/impl/CKnowledgeComplexity.h"
#include "app/application/CKnowlegeAnalyzeApp.h"

#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char* argv[]) {
	ILinearApproach* _pApp = NULL;
	ISerializer* pSerial = NULL;

	// pSerial = NULL;
	// pSerial->loadFromFile("x.input", _pApp);

	//	_pApp->define_Linear(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	//	_pApp->complexity();			// work hour


	CKnowlegeAnalyzeApp app;
	app.run(argc, argv);

	return 0;
}
