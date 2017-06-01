#ifndef _MAXSIZE_STATEMACHINE_
#define _MAXSIZE_STATEMACHINE_

#include "statemachine.h"

class MaxSizeStateMachine: public StateMachine {
		int n;
	public:
		MaxSizeStateMachine(int size) { n=size; }
};


#endif

