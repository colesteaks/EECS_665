GFLAGS=-std=c++14


converter: main.o NFA.o State.o DFA.o DState.o
	g++ -g $(GFLAGS) main.o NFA.o State.o DFA.o DState.o -o converter

main.o: main.cpp NFA.h State.h DFA.h DState.h
	g++ -g $(GFLAGS) -c main.cpp

NFA.o: NFA.cpp NFA.h State.h
	g++ -g $(GFLAGS) -c NFA.cpp

DFA.o: DFA.cpp DFA.h DState.h
		g++ -g $(GFLAGS) -c DFA.cpp

State.o: State.cpp State.h
	g++ -g $(GFLAGS) -c State.cpp

DState.o: DState.cpp DState.h
	g++ -g $(GFLAGS) -c DState.cpp

clean:
	rm -rf *o converter main.o NFA.o State.o DState.o DFA.o

test:
	./converter sample_in.txt
