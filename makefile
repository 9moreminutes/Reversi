all: Reversi

Server.o: Server.h Server.cpp
	g++ -std=c++11 -c Server.cpp

board.o: board.h Space.h board.cpp
	g++ -std=c++11 -c board.cpp

Reversi: Server.o board.o
	g++ -std=c++11 board.o Server.o -o Reversi

clean:
	rm -rf *.o Reversi