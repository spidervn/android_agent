
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cassert>
#include "statemachine.h"

#define MAX_STATE 10000
using namespace std;

#define SAFEFREE(x) if (x) { free(x);x=NULL; }

/*
class StateWorker {
public:
	StateWorker() {}
	virtual void doTransit(int transval, int from, int to, void* data) = 0; 
};
*/

/*
class StateMachine 
{
private:
	int n;
	int* rule;
	int n_rule;
	int cur_state;
	
	StateWorker** aWorker;
	bool* code_define;

public:*/
StateMachine::StateMachine(int num_code)
{
	n = num_code;
	assert(num_code <= MAX_STATE);

	n_rule = 0;
	rule = (int*)malloc(sizeof(int)*num_code*3);		// [EACH RULE HAS 3 VALUE [from,to,transition]
	code_define = (bool*)malloc(sizeof(bool)*num_code);
	aWorker = (StateWorker**)malloc(sizeof(StateWorker*)*n_rule);

	for (int i=0;i<n;i++) {
		code_define[i] = false;
	}
}

StateMachine::~StateMachine()
{
	free(code_define);
	free(rule);
	SAFEFREE(aWorker);
}

void StateMachine::add_node(unsigned int CODE) 
{
	assert(CODE < n);

	code_define[CODE] = true;
	cur_state = CODE;
}

void StateMachine::add_transition(unsigned int CODE_FROM, unsigned int CODE_TO, int TRANSITION_VAL, StateWorker* pWorker)
{
	assert(code_define[CODE_FROM]);
	assert(code_define[CODE_TO]);
		
	bool b_dup = false;
	for (int i=0;i<n_rule;i++)  
	{
		// duplicate
		if (rule[i*3] == CODE_FROM && rule[i*3+1] == CODE_TO && rule[i*3+2] == TRANSITION_VAL) {
			b_dup = true;
			break;
		}
	}
	
	if (!b_dup)
	{
		rule[n_rule*3] = CODE_FROM;
		rule[n_rule*3+1] = CODE_TO;
		rule[(n_rule)*3+2] = TRANSITION_VAL;

		aWorker[n_rule++] = pWorker;
	}
}

void StateMachine::set_state(unsigned int nw_state)
{
	assert(nw_state < n);
	assert(code_define[nw_state]);

	cur_state = nw_state;
}

void StateMachine::add_action(int transval, void* p_data) {
	for (int i=0;i<n_rule;i++) {
		if (cur_state == rule[i*3] && rule[i*3+2] == transval) {
			// Rule matched 
			if (aWorker[i] != NULL) {
				aWorker[i]->doTransit(transval, cur_state, rule[i*3+1], p_data);
			}

			// Transform into new state	
			set_state(rule[i*3+1]);	
		}
	}
}
void StateMachine::run()
{
	while (true)
	{
		unsigned int nw_state;
		int trans_val;
		bool b_match = false;

		printf("My state is %d\r\n", cur_state);
		printf("\tEnter transition: ");
		cin >> trans_val;
		
		for (int i=0;i<n_rule;i++) {
			if (rule[i*3] == cur_state && rule[i*3+2] == trans_val) {
					
				nw_state = rule[i*3+1];
				b_match = true;
				break;
			}
		}

		if (b_match)
		{
			printf("Rule matched. Change state to %d\r\n", nw_state);
			set_state(nw_state);
		} 
		else
		{
			printf("Matching nothing. Enter again\r\n");
		}
		}
}

/*};*/

#define M_START 		0
#define M_SING_SONG 	1
#define M_FARAWELL 		2
#define M_CHOOSE_FIELD 	3
#define M_KICKOFF 		4
#define M_HALF_TIME 	5
#define M_FULL_TIME 	6
#define M_END_MATCH 	7
#define M_END 			8

#define M_TRANS_STEP	0			// Default transititon; time 

class MatchSM : public StateMachine, StateWorker
{
public:
	MatchSM(int num_code) : StateMachine(num_code), StateWorker() 
	{
		add_node(M_START);
		add_node(M_SING_SONG);
		add_node(M_FARAWELL);
		add_node(M_CHOOSE_FIELD);
	}

	~MatchSM()
	{

	}
	
	void doTransit(int transval, int from, int to, void* data) 
	{
		printf("OK\r\n");
	}
};

/*
int main(int argc, char** argv)
{
	printf("State Machine\r\n");

	StateMachine m(10);

	m.add_node(1);
	m.add_node(2);

	m.add_transition(1,2,1);
	m.add_transition(2,1,2);
	m.add_transition(2,1,3);

	int INITIAL_STATE = 0; 
	int FINAL_STATE = 10;

	m.run();

	MatchSM match(10);	
	match.doTransit(0,0,0,NULL);
}
*/
