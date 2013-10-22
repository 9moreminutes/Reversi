#ifndef CLIENT_H
#define CLIENT_H

//#include <winsock2.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sys/types.h>
#include "board.h"

class Client
{
public:
    Client();
    void serverConnect();
    void makeBoard(char*);
    void makeMove(int,char);
    void startGame();
    void quitGame();
    void getBoard();

private:
    SOCKET connSock;
    SOCKADDR_IN client;
    int grid[8][8]; // For use by GUI app
    char buffer[64];
};

#endif // CLIENT_H
