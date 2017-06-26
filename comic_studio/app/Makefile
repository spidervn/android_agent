TARGET=app
CC=g++
LDFLAGS=-lpthread
CFLAGS=-I/usr/include -std=c++11

OBJS=core/sm/statemachine.o core/sm/feedbackmachine.o tmenu.o main.o
CPPS=core/sm/statemachine.cpp core/sm/feedbackmachine.cpp tmenu.cpp main.cpp
INCLUDES=core/sm/statemachine.h core/sm/feedbackmachine.h tmenu.h

app: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(OBJS): $(CPPS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $(@:.o=.cpp) -o $(@:.o=.o) $(LDFLAGS)

clean:
	@rm  $(OBJS)
