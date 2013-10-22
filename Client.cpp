/**
  We need a list of commands to be sent through socket
  I am unsure of output format of board, I'm assuming just a list of tiles from left->right and top->bottom
**/
#include "Client.h"
#include <sstream>

Client::Client()
{
}

void Client::serverConnect()
{
    /*
     * Sockets take and send strings (char*)
     * must use function to translate input
     * moves and commands must be sent in string form to server
     */

    // Setup socket
    connSock = socket(AF_INET, SOCK_STREAM, 0);
    if (connSock < 0) {
        perror("Error making socket");
    }
    port = 7349;

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port(port);
    // Connect to server
    for (;;)
    {
        if(connect(connSock, (SCOKADDR*)&client, sizeof(client)))
        {
            break;
        }
    }
}

void Client::makeBoard(char* input)
{
    Stream s = input;
    char c;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if ((c<<s.get()) == EMPTY)
                grid[i][j] = EMPTY;
            else if (c == WHITE)
                grid[i][j] = WHITE;
            else
                grid[i][j] = BLACK;
}

void Client::getBoard()
{
    write(connSock,"getBoard",sizeof(buffer));
    bzero(buffer, 64);
    read(connSock,buffer,sizeof(buffer));
    makeBoard(buffer);
}

void Client::makeMove(int row, char col) //NOT TESTED
{
    write(connSock,"move "+row+" "+col,sizeof(buffer));

}

void Client::startGame() //NOT TESTED
{
    write(connSock,"start",sizeof(buffer));
}

void Client::quitGame() //NOT TESTED
{
    write(connSock,"quit",sizeof(buffer));
}
