/**
  We need a list of commands to be sent through socket
  I am unsure of output format of board, I'm assuming just a list of tiles from left->right and top->bottom
**/
#include "Client.h"
#include <iostream>
#include <sstream>

Client::Client()
{
}

void Client::serverConnect(string aiHostname)
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
    int port = 7349;
    aiHostname = "127.0.0.1";
    client.sin_family = AF_INET;
    client.sin_port = htons(port);
    struct hostent * aiHost;
    aiHost = gethostbyname(aiHostname.c_str());
    bcopy((char *)aiHost->h_addr, (char *)&client.sin_addr.s_addr, aiHost->h_length);
    // Connect to server
    for (;;)
    {
        if(connect(connSock, (struct sockaddr *) &client, sizeof(client)))
        {
            break;
        }
    }
    read(connSock,buffer,sizeof(buffer));
    startGame();
}

char *Client::stripExtra(char* input) {
    int j = 23;
    for (int i = 0; i < 200; i+=8){
        input[i]=input[j];
        input[i+1]=input[j+2];
        input[i+2]=input[j+4];
        input[i+3]=input[j+6];
        input[i+4]=input[j+8];
        input[i+5]=input[j+10];
        input[i+6]=input[j+12];
        input[i+7]=input[j+14];
        j+=19;
    }
    

    return input;
}

void Client::makeBoard(char* input)
{
    bzero(buffer, 256);
    read(connSock,buffer,sizeof(buffer));
    cout << "making board" << endl;
    cout << buffer << endl;
    char c;
    grid.erase(grid.begin(), grid.end());
    for (int i = 20; i < 200; i++) {
        c=buffer[i];
        if (c == '_') {
            grid.push_back(EMPTY);
        }
        else if (c == 'O') {
            grid.push_back(WHITE);
        }
        else if (c == '@'){
            grid.push_back(BLACK);
        }

    }
}

void Client::getBoard()
{
    write(connSock,"DISPLAY",sizeof(buffer));
    usleep(10000);
    bzero(buffer, 256);
    cout << "Read board from sock" << endl;
    makeBoard(buffer);
}

vector<Tile> Client::getGrid()
{
    return grid;
}

void Client::makeMove(char row, char col) //NOT TESTED
{
    stringstream ss;
    ss << col << " " << row << endl;
    write(connSock,ss.str().c_str(),sizeof(buffer));
    bzero(buffer, 256);
    read(connSock,buffer,sizeof(buffer));
    getBoard();

}

void Client::startGame() //NOT TESTED
{
    write(connSock,"HUMAN-AI",sizeof(buffer));
    bzero(buffer, 256);
    read(connSock,buffer,sizeof(buffer));
}

void Client::quitGame() //NOT TESTED
{
    write(connSock,"EXIT",sizeof(buffer));
}

void Client::setEasy()
{
    write(connSock,"EASY",4);
    bzero(buffer, 256);
    read(connSock,buffer,sizeof(buffer));
}

void Client::setMedium()
{
    write(connSock,"MEDIUM",6);
    bzero(buffer, 256);
    read(connSock,buffer,sizeof(buffer));
}

void Client::setHard()
{
    write(connSock,"HARD",4);
    bzero(buffer, 256);
    read(connSock,buffer,sizeof(buffer));
}
