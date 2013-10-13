#ifndef _server_h_
#define _server_h_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "Space.h"
#include "board.h"

using namespace std;

enum Difficulty { EASY, MEDIUM, HARD };

class Server {
private:
    /* Data ******************/
    GameEngine game;
    Tile playerColor,
         aiColor;
    Difficulty diff;

    int connSock, gameSock, port, msgSize, clilen;
    char buffer[64];
    struct sockaddr_in client, server;

    /* Functions *************/
    void handleStart(string);
    void handleMove(Row, Column);
    void handleUndo();

public:
    Server();
    ~Server();
    void waitForConnection();
    void handleCommand(char*);
};

#endif