#ifndef _CORE_STANDARD_LIB_H_
#define _CORE_STANDARD_LIB_H_

#include <vector>

/*
 * Different between two array:
 * 	return Number of Element are the same 
 * 	diffA => elements from A which not in B
 * 	diffB => elements from B which not in A
 *  
 */
template<class T>
int array_diff(T a[], int nA,  T b[], int nB,  std::vector<T> vDiffA, std::vector<T> vDiffB) {

	// Dummy algorithm
	int a = 1;
	int b = 1;
	int nSame = 0;

	std::vector<T>::iterator itA, itB;

	vDiffA.clear();
	vDiffB.clear();

	std::copy(a, a + nA, vDiffA.begin());	
	std::copy(b, b + nB, vDiffB.begin());

	itA = vDiffA.begin();
	itB = vDiffB.begin();

	while (itA != vDiffA.end()) {
		bool bFound = false;
		for (itB = vDiffB.begin(); itB != vDiffB.end(); itB++) {
			if (*itB == *itA) {
				bFound = true;
				break;
			}
		}

		if (bFound) {
			vDiffA.erase(itA);
			vDiffB.erase(itB);
		} else {
			nSame++;
		}
	}

	return nSame;
}

std::string getParentPath(const char* szPath) {
	return std::string("");
}


#endif 
