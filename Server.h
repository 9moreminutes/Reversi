#ifndef _server_h_
#define _server_h_

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
#include "Space.h"
#include "board.h"
#include "ai.h"

using namespace std;

enum Difficulty { EASY, MEDIUM, HARD };

class Server {
private:
    /* Data ******************/
    GameEngine game;
    Tile playerColor,
         aiColor;
    Difficulty diff = Difficulty::EASY,
               aiDiff = Difficulty::EASY;
    bool started = false,
         aiGame = false,
         gameover = false;
    AI ai;

    int connSock, 
        aiSock, 
        gameSock, 
        port, 
        msgSize, 
        clilen,
        aiPort;
    char buffer[256];
    string aiHostname;
    struct sockaddr_in client, server;

    /* Functions *************/
    void handleStart();
    void handleMove(string);
    void makeAIMove();
    bool isValid(string);
    bool checkMove(string);
    bool checkStart(string);

public:
    Server(char *);
    ~Server();
    void waitForConnection();
    void handleCommand();
    void getCommand();
    bool done();
    void runAI();
};

#endif