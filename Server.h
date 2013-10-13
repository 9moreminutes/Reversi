#ifndef _server_h_
#define _server_h_

#include <sys/types.h>
#include <sys/socket.h>
#include <string>
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

    int sock, port, msgSize;
    char[64] buffer;
    struct sockaddr_in client, server;

    /* Functions *************/
    void handleStart(string);
    void handleMove(Row, Column);
    void handleUndo();

public:
    Server();
    ~Server();

    void handleCommand();
};

#endif