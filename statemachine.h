#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H_

class StateWorker 
{
public:
	virtual void doTransit(int transval, int from, int to, void* data)=0;
};

class StateMachine
{
private:	
	int n;
	int* rule;
	int n_rule;
	int cur_state;
	
	StateWorker** aWorker;
	bool* code_define;

public:
	StateMachine(int num_code);

	~StateMachine();

	void add_node(unsigned int CODE);
	
	void add_transition(unsigned int CODE_FROM, unsigned int CODE_TO, int TRANSITION_VAL, StateWorker* pWorker = NULL);

	/* void */
	void set_state(unsigned int);

	void run();	
};

#endif
