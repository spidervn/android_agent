TARGET=app
CC=g++
LDFLAGS=-lpthread -lboost_system -lboost_filesystem -lpq -lpqtypes
# $(pkg-config --libs libpq)
CFLAGS=-I/usr/include -std=c++11 
#$(pkg-config --cflags libpq)

OBJS=comicdb.o comicutil.o core/sm/statemachine.o core/sm/feedbackmachine.o tmenu.o main.o
CPPS=comicdb.cpp comicutil.cpp core/sm/statemachine.cpp core/sm/feedbackmachine.cpp tmenu.cpp main.cpp
INCLUDES=comicdb.h comicutil.h core/sm/statemachine.h core/sm/feedbackmachine.h tmenu.h

app: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(OBJS): $(CPPS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $(@:.o=.cpp) -o $(@:.o=.o) $(LDFLAGS)

clean:
	@rm  $(OBJS)
