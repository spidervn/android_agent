#include "comicdb.h"
#include <stdlib.h>
#include <stdio.h>
#include <libpq-fe.h>

#include <sys/types.h>
/* for ntohl/htonl */
#include <netinet/in.h>
#include <arpa/inet.h>

#include <libpqtypes.h>
#include <string.h>

using namespace std;

ComicDB::ComicDB(const char* szConnInfo) {
	this->connStr = szConnInfo;
	this->pConn = PQconnectdb(szConnInfo);

	if (PQstatus(pConn) != CONNECTION_OK) {
		printf("Connect failed\r\n");
		pConn = NULL;
	}
}

ComicDB::~ComicDB()
{
	if (pConn != NULL) {
		PQfinish(pConn);
	        pConn = NULL;	
	}
}

void ComicDB::test() 
{
	const char* connInfo = "host=localhost port=5433 dbname=spider_dev user=spider_dev password=123456 connect_timeout=10";
	PGconn*	pConn;
	PGresult* pRes;
	int nFields;
	int i,j;

	pConn = PQconnectdb(connInfo);

	if (PQstatus(pConn) != CONNECTION_OK) {
		printf("Connected failed: %s", PQerrorMessage(pConn));
		PQfinish(pConn);
		return;
	}


	if (PQstatus(pConn) != CONNECTION_OK)
	{
		printf("Connectio to DB failed %s\r\n", PQerrorMessage(pConn));
		PQfinish(pConn);
		return;
	}

	pRes = PQexec(pConn, "BEGIN");
	if (PQresultStatus(pRes) != PGRES_COMMAND_OK) 
	{
		printf("BEGIN command failed %s\r\n", PQerrorMessage(pConn));
		PQclear(pRes);

		PQfinish(pConn);
		return;
	}
	PQclear(pRes);

	pRes = PQexec(pConn, "DECLARE myportal CURSOR for select * from pg_database;");

	if (PQresultStatus(pRes) != PGRES_COMMAND_OK) 
	{
		printf("Declare cursor failed: %s\r\n", PQerrorMessage(pConn));
	}

	PQclear(pRes);


	pRes = PQexec(pConn, "FETCH ALL in myportal");
	if (PQresultStatus(pRes) != PGRES_TUPLES_OK) 
	{
		printf("Fetch all failed %s", PQerrorMessage(pConn));
		PQclear(pRes);
		PQfinish(pConn);
		return;
	}

	nFields = PQnfields(pRes);
	for (int i=0;i<nFields;i++) {
		printf("%-15s", PQfname(pRes, i));
	}
	printf("\r\n");

	for (int i=0;i < PQntuples(pRes);i++) 
	{
		for (int j=0; j<nFields; j++) {
			printf("%-15s", PQgetvalue(pRes, i, j));
		}
		printf("\n");
	}

	PQclear(pRes);

	pRes = PQexec(pConn, "CLOSE myportal");
	PQclear(pRes);

	pRes = PQexec(pConn, "END");
	PQclear(pRes);

	PQfinish(pConn);
}

void ComicDB::test1() 
{
	const char* connInfo = "host=localhost port=5433 dbname=spider_dev user=spider_dev password=123456 connect_timeout=10";
	PGconn*	pConn;
	PGresult* pRes;
	int nFields;
	int i,j;

	pConn = PQconnectdb(connInfo);

	if (PQstatus(pConn) != CONNECTION_OK) {
		printf("Connected failed: %s", PQerrorMessage(pConn));
		PQfinish(pConn);
		return;
	}

	printf("Mark 1\r\n");
	pRes = PQexec(pConn, "select id,title from comic");
	if (PQresultStatus(pRes) != PGRES_TUPLES_OK)
	{
		printf("SELECT command failed %s\r\n", PQerrorMessage(pConn));
		PQclear(pRes);

		PQfinish(pConn);
		return;
	}

	printf("Mark 2\r\n");
	int col_i_title,
	    col_i_id;
	
	col_i_id = PQfnumber(pRes, "id");
	printf("Mark 2.1\r\n");
	col_i_title = PQfnumber(pRes, "title");
	printf("Mark 2.2\r\n");


	// nFields = PQnfields(pRes);
	// printf("Row count = %n\r\n", nFields);
	int nRows = PQntuples(pRes);
	printf("Row count = %n\r\n", nRows);
	for (int i=0;i<nRows;i++) {
		char* ptrId;
		char* ptrTitle;
		int id;
		int titleLen;

		ptrId = PQgetvalue(pRes, i, col_i_id);
		ptrTitle = PQgetvalue(pRes, i, col_i_title);

		id = ntohl(*((uint32_t*) ptrId));
		titleLen = PQgetlength(pRes, i, col_i_title);

		printf("Row(%d)[%d, %s]\r\n", id, ptrTitle);
	}

	PQclear(pRes);
	PQfinish(pConn);
}

void ComicDB::test2() 
{
	const char* conninfo="host=localhost port=5433 dbname=spider_dev user=spider_dev password=123456 connect_timeout=10";
	PGconn     *conn;
    PGresult   *res;
    const char *paramValues[1];
    int         paramLengths[1];
    int         paramFormats[1];
    uint32_t    binaryIntVal;

	/* Make a connection to the database */
    conn = PQconnectdb(conninfo);

    /* Check to see that the backend connection was successfully made */
    if (PQstatus(conn) != CONNECTION_OK)
    {
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        PQfinish(conn);
        return;
    }

    /*
     * The point of this program is to illustrate use of PQexecParams() with
     * out-of-line parameters, as well as binary transmission of data.
     *
     * This first example transmits the parameters as text, but receives the
     * results in binary format.  By using out-of-line parameters we can avoid
     * a lot of tedious mucking about with quoting and escaping, even though
     * the data is text.  Notice how we don't have to do anything special with
     * the quote mark in the parameter value.
     */

    /* Here is our out-of-line parameter value */
    paramValues[0] = "joe's place";

    /*res = PQexecParams(conn,
                       "SELECT id, title FROM comic WHERE title != $1",
                       1,       
                       NULL,    
                       paramValues,
                       NULL,    
                       NULL,    
                       1);*/

	res = PQexec(conn, "SELECT id, title FROM comic ORDER BY id");

    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        fprintf(stderr, "SELECT failed: %s", PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        return;
    }

    PQclear(res);

    /*
     * In this second example we transmit an integer parameter in binary form,
     * and again retrieve the results in binary form.
     *
     * Although we tell PQexecParams we are letting the backend deduce
     * parameter type, we really force the decision by casting the parameter
     * symbol in the query text.  This is a good safety measure when sending
     * binary parameters.
     */

    /* Convert integer value "2" to network byte order */
    binaryIntVal = htonl((uint32_t) 2);

    /* Set up parameter arrays for PQexecParams */
    paramValues[0] = (char *) &binaryIntVal;
    paramLengths[0] = sizeof(binaryIntVal);
    paramFormats[0] = 1;        /* binary */

    /*res = PQexecParams(conn,
                       "SELECT id, title FROM comic WHERE id != $1::int4",
                       1,       
                       NULL,    
                       paramValues,
                       paramLengths,
                       paramFormats,
                       1);*/
	res = PQexec(conn, "SELECT id, title FROM comic");                       

    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        fprintf(stderr, "SELECT failed: %s", PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        return;
    }

    int         i,
                j;
    int         id_fnum,
                title_fnum;

    /* Use PQfnumber to avoid assumptions about field order in result */
    id_fnum = PQfnumber(res, "id");
    title_fnum = PQfnumber(res, "title");

    for (i = 0; i < PQntuples(res); i++)
    {
        char       *ptrId;
        char       *ptrTitle;

        int         blen;
        int         ival;

        /* Get the field values (we ignore possibility they are null!) */
        ptrId = PQgetvalue(res, i, id_fnum);
        ptrTitle = PQgetvalue(res, i, title_fnum);

        /*
         * The binary representation of INT4 is in network byte order, which
         * we'd better coerce to the local byte order.
         */
        ival = ntohl(*((uint32_t *) ptrId));

        /*
         * The binary representation of TEXT is, well, text, and since libpq
         * was nice enough to append a zero byte to it, it'll work just fine
         * as a C string.
         *
         * The binary representation of BYTEA is a bunch of bytes, which could
         * include embedded nulls so we have to pay attention to field length.
         */
         /*
        blen = PQgetlength(res, i, b_fnum);

        printf("tuple %d: got\n", i);
        printf(" i = (%d bytes) %d\n",
               PQgetlength(res, i, i_fnum), ival);
        printf(" t = (%d bytes) '%s'\n",
               PQgetlength(res, i, t_fnum), tptr);
        printf(" b = (%d bytes) ", blen);
        for (j = 0; j < blen; j++)
            printf("\\%03o", bptr[j]);
        printf("\n\n");
        */
        printf("Id=%d; Title=%s\r\n", ival, ptrTitle);
    }

    PQclear(res);
    /* close the connection to the database and cleanup */
    PQfinish(conn);
}

void ComicDB::load2() {
	
	const char* conninfo="host=localhost port=5433 dbname=spider_dev user=spider_dev password=123456 connect_timeout=10";
	PGconn     *conn;
    PGresult   *res;

    const char *paramValues[1];
    int         paramLengths[1];
    int         paramFormats[1];
    uint32_t    binaryIntVal;

	/* Make a connection to the database */
    conn = PQconnectdb(conninfo);

    /* Check to see that the backend connection was successfully made */
    if (PQstatus(conn) != CONNECTION_OK)
    {
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        PQfinish(conn);
        return;
    }

    PQinitTypes(conn);
    int resultFormat = 0;

    // res = PQparamExec(conn, NULL, "Select id, title from comic order by id;", resultFormat);
    res = PQexec(conn, "select id, title from comic");
	
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        fprintf(stderr, "SELECT failed: %s", PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        return;
    }

    if (!res) 
    {
    	printf("Error %s\r\n", PQgeterror());
    }

    int nRow = PQntuples(res);
    printf("Row count = %d\r\n", nRow);

    for (int i = 0; i < nRow; i++)
    {
    	PGint4 id;
    	// PGtext title = NULL;
    	char title[250];
	PGtext mytext = NULL; 	

    	int success = PQgetf(res, i, "%int4 %varchar", 0, &id, 1, &mytext);

	if (success)  {
		strcpy(title, mytext);
	    	printf("Row(%d)[id=%d; title(%d)=%s]\r\n", (i+1), id, 0, title);
	} else {
		printf("*ERROR: %s\n", PQgeterror());
		// printf("Error\r\n");
	}
    }

    PQclear(res);
    PQfinish(conn);	
}

int ComicDB::createObj(ComicObject& obj, int& retId)
{
	PQinitTypes(pConn);

	int db_ret = DB_RES_OK;
	int nSuccess = 0;
	const char* szSQL = "insert into comic(title, short_description, full_description, icon_grid, icon_detail, tag, created_time, modify_time, category_id, sub_category_id, view_count, status, language, translator, code) values ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15) returning id;";
	
	PGparam* param = PQparamCreate(pConn);
	PGtimestamp created_time;
	PGtimestamp modify_time;

	created_time = makeTime(2000, 1, 1, 0, 0, 0);
	modify_time = makeTime(2000, 1, 1, 0, 0, 0);

	if (PQputf(param, "%varchar %varchar %varchar %varchar %varchar %varchar %timestamp %timestamp %int4 %int4 %int4 %int2 %varchar %varchar %varchar",
			obj.title.c_str(),
			obj.short_description.c_str(),
			obj.full_description.c_str(),
			obj.icon_grid.c_str(),
			obj.icon_detail.c_str(),
			obj.tag.c_str(),

			&created_time,
			&modify_time,

			obj.category_id,
			obj.sub_category_id,
			obj.view_count,
			obj.status,

			obj.language.c_str(),
			obj.translator.c_str(),
			obj.code.c_str())) {
	} else {
		printf("HERE0 - Error %s\r\n", PQgeterror());
	}

	PGresult* pRes = PQparamExec(pConn, param, szSQL, 1);	// Ask binary output
	PQgetf(pRes,0, "%int4", &retId);

	if (PQresultStatus(pRes) == PGRES_TUPLES_OK)  
	{
		printf("HERE\r\n");
		// Inserted OK
		if (!PQgetf(pRes,0, "%int4", &retId)) {
			printf("HERE - Error %s\r\n", PQgeterror());
			db_ret = DB_RES_FAILED;
		}
	} 
	else 
	{
		printf("HERE1 - Error %s\r\n", PQgeterror());
		db_ret = DB_RES_FAILED;
	}

	PQclear(pRes);
	return db_ret;
}

int ComicDB::find(string* arrFind, int nFind, vector<ComicObject> &vout)
{
	const char* szSQL = "select id, title, short_description, full_description, icon_grid, icon_detail, tag, created_time, modify_time, category_id, sub_category_id, view_count, status, language, translator, code from comic";	
	return 0;
}

int ComicDB::getRow(PGresult* pRes, int tupleIndex, ComicObject& obj)
{
	int success = 0;
	int db_ret = DB_RES_OK;

	PGtext title = NULL;
	PGtext short_description = NULL;
	PGtext full_description = NULL;
	PGtext icon_grid = NULL;
	PGtext icon_detail = NULL;
	PGtext tag = NULL;
	PGtimestamp created_time;
	PGtimestamp modify_time;

	PGtext language;
	PGtext translator;
	PGtext code;

	success= PQgetf(pRes, tupleIndex, "%int4 %varchar %varchar %varchar %varchar %varchar %timestamp %timestamp %int4 %int4 %int4 %int2 %varchar %varchar %varchar", 
				0, &obj.id,
				1, &short_description,
				2, &full_description,
				3, &icon_grid,
				4, &icon_detail,
				5, &tag,
				
				6, &created_time,
				7, &modify_time,

				8, &obj.category_id,
				9, &obj.sub_category_id,
				10, &obj.view_count,
				11, &obj.status,

				12, &language,
				13, &translator,
				14, &code);

	if (success) {
		obj.short_description = short_description;
		obj.full_description = full_description;
		obj.icon_grid = icon_grid;
		obj.icon_detail = icon_detail;
		obj.tag = tag;

		obj.language = language;
		obj.translator = translator;
		obj.code = code;

		obj.created_time = created_time.epoch;
		obj.modify_time = modify_time.epoch;
	}  else {
		db_ret = DB_RES_FAILED;
	}

	return db_ret;
}

PGtimestamp ComicDB::makeTime(int y, int m, int d, int h, int min, int sec)
{
	PGtimestamp ts;

	ts.date.isbc = 0;
	ts.date.year = y;
	ts.date.mon = m - 1;
	ts.date.mday = d;
	ts.time.hour = h;
	ts.time.min = min;
	ts.time.sec = sec;

	return ts;
}
