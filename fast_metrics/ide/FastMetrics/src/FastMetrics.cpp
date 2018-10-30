#include <iostream>
using namespace std;

#include "estimation/interface/ILinearApproach.h"
#include "io/interface/ISerializer.h"
#include "toolkit/impl/CKnowledgeComplexity.h"
#include "application/CKnowlegeAnalyzeApp.h"

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
