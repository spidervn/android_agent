TARGET=app
CC=g++
LDFLAGS=-lpthread
CFLAGS=-I/usr/include -std=c++11

OBJS=comicutil.o core/sm/statemachine.o core/sm/feedbackmachine.o tmenu.o main.o
CPPS=comicutil.cpp core/sm/statemachine.cpp core/sm/feedbackmachine.cpp tmenu.cpp main.cpp
INCLUDES=comicutil.h core/sm/statemachine.h core/sm/feedbackmachine.h tmenu.h

app: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(OBJS): $(CPPS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $(@:.o=.cpp) -o $(@:.o=.o) $(LDFLAGS)

clean:
	@rm  $(OBJS)
