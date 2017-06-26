#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include <vector>
#include <stdlib.h>

class StateWorker 
{
public:
	// When this function call, the State has been already changed to "To"
	virtual void doTransit(int transval, int from, int to, void* data)=0;
};

class StateMachine
{
	
private:	
	static const int MACHINE_STEP_PREPARE = 0;
	static const int MACHINE_STEP_RUNNING = 1;
	static const int MACHINE_STEP_STOPPED = 2;

	int n;
	//int* rule;
	int n_rule;
	int machine_state;
	

	int cur_state;
	int end_state;
	int begin_state;	
	int* node_ids;	// List of registered states
	
	StateWorker** aWorker;
	StateWorker* defaultWorker;
	// bool* code_define;

	StateMachine* p_present_SM;

	//vector<int> ruleFrom;
	//vector<int> ruleTo;
	std::vector<int> rule;
	std::vector<StateWorker*> ruleWorker;
	std::vector<StateMachine*> ruleMachine;

	/* Inner functions */
	bool validate_machine();

	bool is_defined(int state);
public:
	static const int RES_OK = 0;
	static const int RES_FAILED = 1;
	static const int ERROR_MACHINE_ALREADY_RUNNING = 2;
	static const int ERROR_INVALID_FLOW = 3;
	static const int ERROR_DUPLICATE_TRANSITION = 4;

	StateMachine(unsigned int num_states, int* ls_state, int initState=0, int stateEnd = 0, StateWorker* defaultWorker = NULL);

	~StateMachine();

	/*void add_node(unsigned int CODE);*/
	
	int add_transition(unsigned int CODE_FROM, unsigned int CODE_TO, int TRANSITION_VAL, StateWorker* pWorker = NULL);

 	int add_sub_machine(unsigned int CODE_FROM, unsigned int CODE_TO, int TRANSITION_VAL, StateMachine* pSub);

	int define_transition_table(int** transitTable, int count, StateWorker* pWorker = NULL);

	/* void */
	/* void set_state(unsigned int); */

	int start();	// After starting, all adding is violation

	int step(int input, void* pData);

	int calcNextState(int currentState, int input1, int& nextState, int& output);	/* Calculating next state only;not change inner state class */

	/* void run();	*/
};

#endif
