
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
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

StateMachine::StateMachine(unsigned int num_states, int* ls_state, int initState, int stateEnd, StateWorker* defaultWorker)
{
	n = num_states;
	assert(n <= MAX_STATE);

	n_rule = 0;	
	node_ids = (int*) malloc(sizeof(int) * num_states);
	// rule = (int*)malloc(sizeof(int)*num_code*3);		// [EACH RULE HAS 3 VALUE [from,to,transition]
	
	for (int i=0;i<num_states;i++) {

		node_ids[i] = ls_state[i];
	}

	std::sort(&node_ids[0], &node_ids[n-1]);

	// code_define = (bool*)malloc(sizeof(bool)*num_code);
	// aWorker = (StateWorker**)malloc(sizeof(StateWorker*)*n_rule);

	//for (int i=0;i<n;i++) {
	//	code_define[i] = false;
	//}

	this->machine_state = MACHINE_STEP_PREPARE;

	this->defaultWorker = defaultWorker;
	this->cur_state = initState;
	this->p_present_SM = this;		// Current State Machine 
						// Useful when adding Sub StateMachine
	this->end_state = stateEnd;
	this->begin_state = initState;
}

StateMachine::~StateMachine()
{
	free(node_ids);
	// free(rule);
	// SAFEFREE(aWorker);
}

/*
void StateMachine::add_node(unsigned int CODE) 
{
	assert(CODE < n);

	code_define[CODE] = true;
	cur_state = CODE;
}
*/

bool StateMachine::validate_machine() 
{	
	// Is determined to one_state	
	// All node must end at EndState

	int walk_node = begin_state;
	int queue_node[1000];
	int stack_node[1000];
	int n_queue = 0;
	int n_stack = 0;

	bool is_valid = true;
	/* stack_node[n_stack++] = walk_node; */

	/*
	while (n_queue > 0 && is_valid) {
		int walk_node = stack[--n_stack];	// Pop from stack

		for (int i=0;i<n_rule;i++) {
			int state_from = rule[i*3];
			int state_to = rule[i*3+1];

			if (state_from == walk_node) {
				stack_node[n_stack++] = 
			}
		}
	}
	*/

	int income_count[n];
	int outcome_count[n];
	int* p_found = NULL;
	bool b_valid = true;

	memset(income_count, 0, sizeof(int)*n);		// Zero
	memset(outcome_count, 0, sizeof(int)*n);		// Zero

	for (int i=0;i<n_rule;i++) {		
		int state_from = rule[i*3];
		int state_to = rule[i*3+1];

		p_found = std::find(node_ids, node_ids+n, state_to);
	
		if (p_found != node_ids + n) {
			// stack_node[n_stack++] = walk_node;
			income_count[p_found - node_ids]++;
		}

		p_found = std::find(node_ids, node_ids+n, state_from);

		if (p_found != node_ids + n) {
			outcome_count[p_found - node_ids]++;
		}
	}

	// EndNode must not have any outcome
	// OtherNode must has at least one income and one outcome
	for (int i=0;i<n;i++) {
		if (node_ids[i] == end_state) 
		{
			b_valid &= income_count[i] > 0 && outcome_count[i] == 0;
		}
		else 
		{
			b_valid &= income_count[i] > 0 && outcome_count[i] > 0;
		}
	}

	return is_valid;
}

bool StateMachine::is_defined(int state) {
	int* p_found = std::find(node_ids, node_ids + n, state);

	return p_found != node_ids + n; 
}

int StateMachine::add_transition(unsigned int CODE_FROM, unsigned int CODE_TO, int TRANSITION_VAL, StateWorker* pWorker)
{
	if (machine_state == MACHINE_STEP_RUNNING) {
		// Can not modify after running
		return ERROR_MACHINE_ALREADY_RUNNING;
	}

	//assert(code_define[CODE_FROM]);
	//assert(code_define[CODE_TO]);
	assert(is_defined(CODE_FROM));
	assert(is_defined(CODE_TO));
		
	bool b_dup = false;
	for (int i=0;i<rule.size();i++)  
	{
		// duplicate
		if (rule[i*3] == CODE_FROM && rule[i*3+1] == CODE_TO && rule[i*3+2] == TRANSITION_VAL) {
			b_dup = true;
			break;
		}
	}
	
	if (!b_dup)
	{
		rule.push_back(CODE_FROM);
		rule.push_back(CODE_TO);
		rule.push_back(TRANSITION_VAL);
		// rule[n_rule*3] = CODE_FROM;
		// rule[n_rule*3+1] = CODE_TO;
		// rule[(n_rule)*3+2] = TRANSITION_VAL;

		ruleWorker.push_back(pWorker);
		// aWorker[n_rule++] = pWorker;
	}

	return RES_OK;
}

int StateMachine::step(int transval, void* p_data) {
	for (int i=0;i<n_rule;i++) {
		if (cur_state == rule[i*3] && rule[i*3+2] == transval) {


						
			// Rule matched 
			if (aWorker[i] != NULL) {
				aWorker[i]->doTransit(transval, cur_state, rule[i*3+1], p_data);
			}

			// Transform into new state	
			cur_state = rule[i*3+1];
		}
	}

	return cur_state;
}

int StateMachine::define_transition_table(int** transitTable, int count,  StateWorker* pWorker)
{
	if (machine_state == MACHINE_STEP_RUNNING) {
		return ERROR_MACHINE_ALREADY_RUNNING;
	}

	for (int i=0;i<count;i++) 
	{
		add_transition(transitTable[i][0], transitTable[i][1], transitTable[i][2], pWorker);
	}

	return RES_OK;
}

int StateMachine::start() 
{
	if (validate_machine()) {
		return RES_OK;
	} else {
		return ERROR_INVALID_FLOW;
	}
}

int StateMachine::calcNextState(int currentState, int input, int& nextState, int& output) {

	/*----------
	 * 4 cases
	 * 1. Graph output 
	 * 2. Manually output
	 * 3. Worker Related
	 * 4. Sub machine related
	 */

	/* Zoom 	 		 
	 * 	(s): --(i)---(s1,o1) 
	 * 	----- t_h = transit handler
	 * 	[ ----- s_m = sub_machine ]
	 *
	 * Go into another world
	 * 	[ Sub machine ]
	 * 	[ Sub machine ]
 	 */

	for (int i=0;i<n_rule;i++) {
		int sttFrom = rule[3*i];
		int sttTo = rule[3*i+1];
		int transVal = rule[3*i+2];

	}
	return 1;
}

/*
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
			cur_state = nw_state;
		} 
		else
		{
			printf("Matching nothing. Enter again\r\n");
		}
	}
}
*/

int StateMachine::add_sub_machine(unsigned int CODE_FROM, unsigned int CODE_TO,  int TRANSITION_VAL, StateMachine* pSub) 
{
	/*
	if (p_current_SM) {
		// 
		p_current_SM->	
	}
	p_current_SM->step(TRANSITION_VAL);
	*/
	
	if (machine_state == MACHINE_STEP_RUNNING) {
		return ERROR_MACHINE_ALREADY_RUNNING;
	}	

	assert(is_defined(CODE_FROM));
	assert(is_defined(CODE_TO));
		
	bool b_dup = false;
	for (int i=0;i<rule.size();i++)  
	{
		// duplicate
		if (rule[i*3] == CODE_FROM && rule[i*3+1] == CODE_TO && rule[i*3+2] == TRANSITION_VAL) {
			b_dup = true;
			break;
		}
	}
	
	if (!b_dup)
	{
		rule.push_back(CODE_FROM);
		rule.push_back(CODE_TO);
		rule.push_back(TRANSITION_VAL);
		// rule[n_rule*3] = CODE_FROM;
		// rule[n_rule*3+1] = CODE_TO;
		// rule[(n_rule)*3+2] = TRANSITION_VAL;

		ruleWorker.push_back(NULL);
		ruleMachine.push_back(pSub);
		
		// aWorker[n_rule++] = pWorker;		
		return RES_OK;
	}
	else 
	{
		return ERROR_DUPLICATE_TRANSITION;
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
/*
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
