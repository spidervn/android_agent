#include <iostream>
using namespace std;

#include "spidervnAccel/impl/CSystemUtil.h"
#include "spidervnAccel/impl/test/CTestUtil.cpp"

int main() {
	cout << "SpidermanVN accelerator" << endl;

	CTestUtil cu;
	cu.runAll_Test();

	return 0;
}
