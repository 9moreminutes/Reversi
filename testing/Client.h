#ifndef CLIENT_H
#define CLIENT_H

//#include <winsock2.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include "Space.h"


class Client
{
public:
    Client();
    void serverConnect(string);
    char* stripExtra(char*);
    void makeBoard(char*);
    void makeMove(char, char);
    void startGame();
    void quitGame();
    void getBoard();
    vector<Tile> getGrid();
    void setEasy();
    void setMedium();
    void setHard();

private:
    int connSock;
    sockaddr_in client;
    vector<Tile> grid; // For use by GUI app
    char buffer[256];
};

#endif // CLIENT_H
