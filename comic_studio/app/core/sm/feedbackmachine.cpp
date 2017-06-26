#include "feedbackmachine.h"
#include "statemachine.h"

FeedbackMachine::FeedbackMachine(const StateMachine* innerMachine, int exitState):
	StateMachine( (unsigned int)2, (int*) NULL, STT_MAIN, STT_END, (StateWorker*) NULL)
{
	this->pInnerMachine = innerMachine;

	add_transition(STT_MAIN, STT_END, exitState, this);
	// add_transition(STT_MAIN, STT_END, );
}

void FeedbackMachine::doTransit(int transval, int from, int to, void* data) 
{

}

