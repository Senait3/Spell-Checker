all: term.cpp
	g++ term.cpp

clean: 	
	rm-f *.o

run: all
	./a.out
