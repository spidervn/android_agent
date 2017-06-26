#include <stdlib.h>
#include <string.h>
#include "core/sm/statemachine.h"
#include "tmenu.h"

using namespace std;

#define STT_AI_WAIT 0
#define STT_AI_ACCEPT_TASK 1
#define STT_AI_ASK_OWNER 2
#define STT_AI_END 3
#define STT_AI_SMOOTHCHANGE 4

#define AI_VAL_NEWCMD 1
#define AI_VAL_DEFAULT_TICK 2
#define AI_VAL_MENU_QUIT 3

int main(int argc, char** argv) 
{
	TMenu main_menu(0,NULL,NULL,NULL);

	int ai_table[6][3] = {
		{ STT_AI_WAIT, STT_AI_ACCEPT_TASK, AI_VAL_NEWCMD },
		{ STT_AI_WAIT, STT_AI_SMOOTHCHANGE, AI_VAL_DEFAULT_TICK },
		{ STT_AI_ACCEPT_TASK, STT_AI_END, AI_VAL_MENU_QUIT },
		{ STT_AI_ACCEPT_TASK, STT_AI_WAIT, AI_VAL_DEFAULT_TICK },
		{ STT_AI_SMOOTHCHANGE, STT_AI_WAIT, AI_VAL_DEFAULT_TICK },
		{ STT_AI_SMOOTHCHANGE, STT_AI_ASK_OWNER, AI_VAL_NEWCMD }
	};	

	/*
	StateMachine m1;
	RepeatMachine m(&m1);

	m.step(inp1);
	m.step(inp2);

	while (!m.isEnd()) {
		m.step(m.currentState());
		m.defaultStep();
	}
	*/

	/*
	StateMachine m(1);

	StateMachine nodeMain(1);		// Menu Main

	StateMachine nodeAI(1);			// Main App (Android Agent)
	StateMachine nodeScanDir(1);		// Menu 01
	StateMachine nodeManipulator(1);	// Menu 02

	StateMachine node02(1);			// Menu 03	

	while (1) {
	}
	*/

	return 0;
}
