#ifndef _CORE_SM_GRAPHMACHINE_H_
#define _CORE_SM_GRAPHMACHINE_H_

#include "statemachine.h"
#include <vector>

class GraphMachine : public StateMachineV2
{
private:
	std::vector<int> vRule;
	// Use a map or something ? 

public:
	GraphMachine();

	bool validate_machine();

	int define_graph(int** transitTable, int count);

	int defineSubMachine(int state, StateMachineV2* pMachine);	// Define state is a sub state machine

	// Return null if no submachine involved 
	virtual int calcNextState(int input, int currentState, int& output, int& nextState);

protected:
	bool validate_machine();	
};

#endif
