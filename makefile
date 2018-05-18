team.x: team.h team.cpp driver.cpp
	g++ -std=c++11 -Wall -pedantic -o team.x driver.cpp
clean:
	rm -f *.o *.x core.* *.gch