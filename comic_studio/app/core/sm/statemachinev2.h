#ifndef _CORE_SM_STATEMACHINEV2_H_
#define _CORE_SM_STATEMACHINEV2_H_

/*
 * State Machine V2 (Core)
 * 	@ducvd
 * 	June 16th 2017
 */
class TransitionHandler;

class StateMachineV2 
{
public:
	/* 
	 *
	 * sv2 = {s, e, I, O, S, delta} 
	 *	s: Start state
	 *	e: End state
	 *	I: Vocabulary Input
	 *	O: Vocabulary Output
	 *	S: Vocabulary States
	 *	delta: f(IxS) -> OxS
	 *		function: State, Input => NewState, Output
	 */
	StateMachineV2();

	int defineMachine(unsigned int* inputVocabulary, int coutInputVocab, unsigned int* outputVocabulary, int coutOutputVocab, unsigned int* stateVocabulary, int stateCount, unsigned int startState, unsigned int endState);

	virtual int calcNextState(int input, int currentState, int& output, int& nextState);

	int registerTransition(unsigned int stateFrom, unsigned int stateTo, TransitionHandler* pHandler);

	int removeTransitionHandler(unsigned int stateFrom, unsigned int stateTo);

	bool isEnded();	// Has reaching End State

	int step();

 	void turn_on();		// Start Start machine

	void turn_off();	// Stop using State machine

private:
	int state;
	int machine_progress;

	std::vector<long> transitionHandlerTable;
	std::vector<unsigned int> vInput;	// Vocabulary input
	std::vector<unsigned int> vOutput;	// Vocabulary output
	std::vector<unsigned int> vState;	// Vocabulary states
	unsigned int startState;
	unsigned int endState;

public:
	static const int RES_OK = 0;
	static const int RES_FAILED = 1;
	static const int RES_NOT_FOUND = 6;
	static const int ERROR_MACHINE_ALREADY_RUNNING = 2;
	static const int ERROR_INVALID_FLOW = 3;
	static const int ERROR_DUPLICATE_TRANSITION = 4;
	static const int ERROR_TRANSITION_NOT_FOUND = 5;

	static const int ERROR_INVALID_PARAMETER = 7;
	static const int ERROR_MACHINE_INVALID_BEGINEND_STATE = 8;

protected:
	static const int MACHINE_STEP_PREPARE = 0;
	static const int MACHINE_STEP_RUNNING = 1;
	static const int MACHINE_STEP_STOPPED = 2;


	int findTransitionHandler(unsigned int fromState, unsigned int toState, unsigned int intput, TransitionHandler*& pOutput);
};

class TransitionHandler 
{
	public:
		virtual void doEntry(unsigned int fromState, unsigned int toState, unsigned int transVal, void* pData = NULL);
};

#endif 
