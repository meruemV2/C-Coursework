in2post.x: in2post.o
	g++ -o in2post.x -std=c++11 in2post.o
in2post.o: stack.h in2post.cpp
	g++ -c -std=c++11 stack.h
	g++ -c -std=c++11 in2post.cpp

clean:
	-rm *.o
