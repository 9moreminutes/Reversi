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
         donef = false;


    int connSock, 
        aiSock, 
        gameSock, 
        port, 
        msgSize, 
        clilen,
        aiPort;
    char buffer[64];
    string aiHostname;
    struct sockaddr_in client, server;

    /* Functions *************/
    void handleStart(string);
    void handleMove(string);
    bool isValid(string);
    bool checkMove(string);
    bool checkStart(string);

public:
    Server();
    ~Server();
    void waitForConnection();
    void handleCommand();
    void getCommand();
    bool done() {return donef;}
};

#endif