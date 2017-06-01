
#include <stdio.h>
#include <conio.h>
#include "maxsizesm.h"

void MaxSizeStateMachine::initialize() {
	state = n;
}

void MaxSizeStateMachine::transduce(int[] arr, int n) {
	for (int i=0;i<n;i++) {
		state --;
	}

	if (state < 0) {
		// Output error here
		
	}
}
