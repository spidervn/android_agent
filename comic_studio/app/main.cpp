#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "core/sm/statemachine.h"
#include "tmenu.h"
#include "comicutil.h"
#include "comicdb.h"
#include <dirent.h>
#include <vector>
#include <string>

using namespace std;

#define STT_AI_WAIT 0
#define STT_AI_ACCEPT_TASK 1
#define STT_AI_ASK_OWNER 2
#define STT_AI_END 3
#define STT_AI_SMOOTHCHANGE 4

#define AI_VAL_NEWCMD 1
#define AI_VAL_DEFAULT_TICK 2
#define AI_VAL_MENU_QUIT 3

int scandir() 
{
	DIR* dir;
	struct dirent* ent;
	string sBaseDir = "/home/spider";
	struct stat path_stat;


	if ((dir = opendir("/home/spider")) != NULL)  {
		while ((ent = readdir(dir) ) != NULL) {

		 	string sFullPath = sBaseDir + "/" + ent->d_name;

			stat(sFullPath.c_str(), &path_stat);

			if (S_ISDIR(path_stat.st_mode)) {
				printf("%s is <<Directory>>\r\n", sFullPath.c_str());
			} else if(S_ISREG(path_stat.st_mode)) {
				printf("%s is <<File>>\r\n", sFullPath.c_str());
			} else {
				printf("%s is <<Unknown>>\r\n", sFullPath.c_str());
			}
		}

		printf("Close Dir\r\n");
		closedir(dir);
		printf("After Close Dir\r\n");
	}
	else {
		/* Could not open directory */
		perror("");
	}

	return 0;
}

int main(int argc, char** argv) 
{
	/*
	TMenu main_menu(0,NULL,NULL,NULL);

	int ai_table[6][3] = {
		{ STT_AI_WAIT, STT_AI_ACCEPT_TASK, AI_VAL_NEWCMD },
		{ STT_AI_WAIT, STT_AI_SMOOTHCHANGE, AI_VAL_DEFAULT_TICK },
		{ STT_AI_ACCEPT_TASK, STT_AI_END, AI_VAL_MENU_QUIT },
		{ STT_AI_ACCEPT_TASK, STT_AI_WAIT, AI_VAL_DEFAULT_TICK },
		{ STT_AI_SMOOTHCHANGE, STT_AI_WAIT, AI_VAL_DEFAULT_TICK },
		{ STT_AI_SMOOTHCHANGE, STT_AI_ASK_OWNER, AI_VAL_NEWCMD }
	};	
	*/

	// scandir();
	ComicUtil cu;
	vector<string> v_comic;
	vector<string> v_chap;

	cu.scanDir("/home/spider/projects/truyenspidermanvn/contents-toweb/AlphaBigTime", v_comic, v_chap);

	printf("Comic list\r\n");
	for (int i=0;i<v_comic.size();i++) {
		printf("\t%d. %s\r\n", (i+1), v_comic[i].c_str());
	}

	printf("Chapter list\r\n");
	for (int i=0;i<v_chap.size();i++) {
		printf("\t%d. %s\r\n", (i+1), v_chap[i].c_str());
	}


	ComicDB 
	db("host=localhost port=5433 dbname=spider_dev user=spider_dev password=123456 connect_timeout=10");
	db.load2();

	ComicObject comic;
	comic.title = "XXX";
	int id = 0;
	int ret = 0;

	ret = db.createObj(comic, id);

	printf("Insert ret=%d,ret_id = %d\r\n", ret, id);
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
