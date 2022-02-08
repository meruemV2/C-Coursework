proj4.x: proj4_driver.o
	g++ -o proj2.x -std=c++11 proj4_driver.o
proj4_driver.o: bet.h proj4_driver.cpp
	g++ -c -std=c++11 bet.h
	g++ -c -std=c++11 proj4_driver.cpp

clean:
	-rm *.o
