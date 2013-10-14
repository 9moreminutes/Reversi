all: Reversi

Server.o: Server.h Server.cpp
	g++ -std=c++11 -g -c Server.cpp

board.o: board.h Space.h board.cpp
	g++ -std=c++11 -g -c board.cpp

Reversi: Server.o board.o
	g++ -std=c++11 -g board.o Server.o -o Reversi

clean:
	rm -rf *.o Reversi