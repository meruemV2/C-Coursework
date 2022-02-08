proj5.x: passserver.o proj5.o
	g++ -std=c++11 -o proj5.x proj5.o passserver.o -lcrypt
proj5.o: passserver.h hashtable.h proj5.cpp
	g++ -c -std=c++11 proj5.cpp
passserver.o: passserver.h passserver.cpp hashtable.h hashtable.hpp
	g++ -c -std=c++11 passserver.cpp

clean:
	-rm *.o

