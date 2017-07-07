#include "GraphMachine.h"
#include <stdlib.h>

GraphMachine::GraphMachine()
{
}

int GraphMachine::define_graph(int** transitTable,int count)
{
	if (machine_state == MACHINE_STEP_RUNNING) {
		return ERROR_MACHINE_ALREADY_RUNNING;
	}

	vRule.clear();

	for (int i=0;i<count;i++) {
		vRule.push_back(transitTable[i][0]);
		vRule.push_back(transitTable[i][1]);
		vRule.push_back(transitTable[i][2]);
	}

	return RES_OK;
}

bool GraphMachine::validate_machine() 
{
	// Is determined to one_state	
	// All node must end at EndState
	/*
	int walk_node = begin_state;
	int queue_node[1000];
	int stack_node[1000];
	int n_queue = 0;
	int n_stack = 0;

	bool is_valid = true;
	*/
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

	/*
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
	*/
	return true;
}

int GraphMachine::calcNextState(int input, int currentState, int& output, int& nextState)
{
	// Is a sub machine
	if (mapSubMachine.find(currentState) != mapSubMachine.end()) 
	{
		StateMachineV2* pMachine = mapSubMachine[currentState];

		if (pMachine->isEnded()) {
			int subOutput = pMachine->getOutput();

			// 
			int n = vRule.size() / 3;
			bool bFound = false;
			for (int i=0;i<n;i++)
		       	{
				unsigned int fromState = vRule[3*i];
				unsigned int toState = vRule[3*i + 1];
				unsigned int tVal = vRule[3*i + 2];

				if (fromState == currentState && tVal == subOutput) 
				{
					nextState = toState;
					bFound = true;
					break;
				}
			}
		} else {
			
		}
	} 
	else 
	{
		int n = vRule.size() / 3;
		bool bFound = false;
		for (int i=0;i<n;i++)
	       	{
			unsigned int fromState = vRule[3*i];
			unsigned int toState = vRule[3*i + 1];
			unsigned int tVal = vRule[3*i + 2];

			if (fromState == currentState && tVal == intput) 
			{
				nextState = toState;
				bFound = true;
				break;
			}
		}
	}

	return bFound ?  RES_OK : RES_FAILED;
}

int GraphMachine::defineSubMachine(int state, StateMachineV2* pSubMachine) 
{
	mapSubMachine.put(state, pSubMachine);

	return RES_OK;
}
