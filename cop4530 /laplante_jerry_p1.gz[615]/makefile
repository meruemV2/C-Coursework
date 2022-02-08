main: mydriver.o
		g++ -o main -std=c++11 mydriver.o
mydriver.o: tnode.h tlist.h mydriver.cpp
	g++ -c -std=c++11 tnode.h
	g++ -c -std=c++11 tlist.h
	g++ -c -std=c++11 mydriver.cpp

clean:
		-rm *.o
