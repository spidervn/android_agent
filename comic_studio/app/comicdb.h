#ifndef _COMIC_DB_H_
#define _COMIC_DB_H_

#include <string>
#include <vector>
#include <libpq-fe.h>
#include <libpqtypes.h>

#define DB_RES_OK 	0
#define DB_RES_FAILED 	1

typedef struct {
	int id;
	std::string title;
	std::string short_description;
	std::string full_description;
	std::string icon_grid;
	std::string icon_detail;
	std::string tag;
	long created_time;
	long modify_time;

	int category_id;
	int sub_category_id;
	int view_count;
	int status;

	std::string language;
	std::string translator;
	std::string code;

} ComicObject;

class ComicDB
{
public:
	ComicDB(const char* szConnInfo);

	~ComicDB();

	void test();	

	void test1();

	void test2();

	void load2();

	int createObj(ComicObject& obj, int& retId);

	int find(std::string* arrFind, int nFind, std::vector<ComicObject> &vout);

protected:
	int getRow(PGresult* pRes, int tupleIndex,  ComicObject& obj);
	PGtimestamp makeTime(int y, int m, int d, int h, int min, int sec);

private:
	PGconn* pConn;		// LibPQ types connection 
	std::string connStr;
};

#endif
