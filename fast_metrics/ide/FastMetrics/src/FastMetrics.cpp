#include <iostream>
using namespace std;

#include "estimation/interface/ILinearApproach.h"
#include "io/interface/ISerializer.h"

int main() {
	ILinearApproach* _pApp = NULL;
	ISerializer* pSerial = NULL;

	pSerial = NULL;
	pSerial->loadFromFile("x.input", _pApp);

	_pApp->define_Linear(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	_pApp->complexity();			// work hour

	return 0;
}
