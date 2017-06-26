#ifndef _AIAGENT_H_
#define _AIAGENT_H_

#include <core/sm/statemachine.h>

class AIAgent : public StateMachine
{
	public:
		AIAgent(unsigned int num_states, int* ls_state, int initState=0, int stateEnd = 0, StateWorker* defaultWorker = NULL);


};

#endif 
