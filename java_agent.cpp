#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream> 

using namespace std;

int run_features() {
	string spath;	// Java source code
	string smain;	// Main class
	string line;

	// Read main file
	ifstream myfile(smain);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			// New line 
			cout << line << endl;
		}

		myfile.close();
	}

	// Flow chart Generator	
	
	return 0;	
}

int main(int argc, char** argv) {
	
	// Comprehensive code ?
	// Function 1

	return 0;
}
