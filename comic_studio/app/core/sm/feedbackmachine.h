
#ifndef _FEEDBACK_MACHINE_H_
#define _FEEDBACK_MACHINE_H_

#include "statemachine.h" 

class FeedbackMachine: public StateMachine, public StateWorker 
{
private:
	const StateMachine* pInnerMachine;
	class FeedbackWorker;	
	FeedbackWorker* pWorker;
public:
	static const int STT_MAIN = 1;
	static const int STT_END = 2;
	FeedbackMachine(const StateMachine* innerMachine, int exitState);	

	void doTransit(int transval, int from, int to, void* data);
};

#endif
