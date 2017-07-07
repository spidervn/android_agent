#include "statemachinev2.h"

#include <algorithm>

using namespace std;

StateMachineV2::StateMachineV2()
{
	machine_progress = MACHINE_STEP_PREPARE;
}

int StateMachineV2::calcNextState(int input, int currentState, int&output, int& nextState) 
{
	return 0;
}

bool StateMachineV2::isEnded()
{	
	return true;
}

int StateMachineV2::defineMachine(unsigned int* inputVocabulary, int countInputVocab, unsigned int* outputVocabulary, int countOutputVocab, unsigned int* stateVocabulary, int stateCount, unsigned int startState, unsigned int endState)
{	

	if (countInputVocab < 0 || countOutputVocab < 0 || stateCount < 0) {
		return ERROR_INVALID_PARAMETER;
	}

	vInput.clear();
	vOutput.clear();
	vState.clear();

	std::copy(inputVocabulary, iputVocabulary + countInputVocab, vInput.begin());
	std::copy(outputVocabulary, outputVocabulary + countOutputVocab, vOutput.begin());
	std::copy(stateVocabulary, stateVocabulary + stateCount, vState.begin());
	
	std::sort(vInput.begin(), vInput.end());
	std::sort(vOutput.begin(), vOutput.end());
	std::sort(vState.begin(), vState.end());
	
	std::find(vState.begin(), vState.end(), startState);

	if (! std::binary_search(vState.begin(), vState().end(), startState) ||
	 	!std::binary_search(vState.begin(), vState.end(), endState)) 
	{
		return ERROR_MACHINE_INVALID_BEGINEND_STATE;
	}

	this->startState = startState;
	this->endState = endState;

	return RES_OK;
}

int StateMachineV2::registerTransition(unsigned int stateFrom, unsigned int stateTo, TransitionHandler* pHandler)
{
	int n = transitionHandlerTable.size() / 3;
	for (int i=0;i<n;i++) {
		unsigned int df_from =  transitionHandlerTable[i*3];	// Defined from
		unsigned int df_to = transitionHandlerTable[i*3+1];	// Defined to
		
		if (df_from == stateFrom && df_to == stateTo) {
			return ERROR_DUPLICATE_TRANSITION;
		}
	}

	transitionHandlerTable.push_back((long)stateFrom);
	transitionHandlerTable.push_back((long)stateTo);
	transitionHandlerTable.push_back((long)pHandler);

	return RES_OK;
}

int StateMachineV2::removeTransitionHandler(unsigned int stateFrom, unsigned int stateTo)
{
	bool bFound = false;
	int i = 0;
	while (i < transitionHandlerTable.size()) 
	{
		unsigned int df_from =  transitionHandlerTable[i];	// Defined from
		unsigned int df_to = transitionHandlerTable[i+1];	// Defined to
	
		if (df_from == stateFrom && df_to == stateTo) 		// Remove now
		{
			transitionHandlerTable.erase(transitionHandlerTable.begin() + i, transitionHandlerTable.begin() + i + 3);
			bFound = true;
		} else {
			i+=3;
		}
	}

	return bFound ?  RES_OK : ERROR_TRANSITION_NOT_FOUND;
}

int StateMachineV2::findTransitionHandler(unsigned int fromState, unsigned int toState, unsigned int input, TransitionHandler*& pOutput) 
{
	int n = transitionHandlerTable.size() / 3;
	int res = RES_NOT_FOUND;

	for (int i=0;i<n;i++) {
		unsigned int df_from =  transitionHandlerTable[3*i];	// Defined from
		unsigned int df_to = transitionHandlerTable[3*i+1];	// Defined to
	
		if (df_from == stateFrom && df_to == stateTo) 
		{
			long l = transitionHandlerTable[3*i+2];
			pOutput = (TransitionHandler*)l;
			
			res = RES_OK;
			break;
		}
	}
	return res;
}

int StateMachineV2::step(int input, int& output) 
{
	int nextState;
	TransitionHandler* pHandler;
	/*
	StateMachineV2* pSubMachine = NULL;
	bool bIsSubNode = false;

	if (bIsNodeSub) {
		if (pSubMachine->isEnded()) {
			
		} else {
			pSubMachine->step(input, output);
		}
	}
	*/

	if (calcNextState(input, currentState, output, nextState) == RES_OK) 
	{
		this->state = nextState;

		if (findTransitionHandler(currentState, nextState, input,pHandler) == RES_OK) 
		{
			pHandler->doEntry(currentState, nextState, input, pHandler);
		}

		return RES_OK;
	} 
	else 
	{
		return RES_FAILED;
	}
}

void StateMachineV2::turn_on() 
{
	machine_progress = MACHINE_STEP_RUNNING;
}

void StateMachineV2::turn_off()
{
	machine_progress = MACHINE_STEP_STOPPED;
}


