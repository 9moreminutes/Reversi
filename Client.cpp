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

char *Client::stripExtra(char* input) {
    for (int i = 0, j = 23; i < 8; i+=8 j+=20){
        input[i]=input[j];
        input[i+1]=input[j+2];
        input[i+2]=input[j+4];
        input[i+3]=input[j+6];
        input[i+4]=input[j+8];
        input[i+5]=input[j+10];
        input[i+6]=input[j+12];
        input[i+7]=input[j+14];
    }
    

    return input;
}

void Client::makeBoard(char* input)
{
    input = stripExtra(input);
    char c;
    int index = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((c=input[index]) == '_') {
                grid[i][j] = EMPTY;
            }
            else if (c == 'O') {
                grid[i][j] = WHITE;
            }
            else {
                grid[i][j] = BLACK;
            }
            index++;
        }
    }
}

void Client::getBoard()
{
    write(connSock,"DISPLAY",sizeof(buffer));
    bzero(buffer, 256);
    read(connSock,buffer,sizeof(buffer));
    makeBoard(buffer);
}

void Client::makeMove(int row, char col) //NOT TESTED
{
    write(connSock,string(row)+" "+string(col),sizeof(buffer));
    getBoard()
}

void Client::startGame() //NOT TESTED
{
    write(connSock,"HUMAN-AI",sizeof(buffer));
}

void Client::quitGame() //NOT TESTED
{
    write(connSock,"EXIT",sizeof(buffer));
}

int main(int argc, char const *argv[])
{
    Client c();
    c.serverConnect();
    c.startGame();
    while(true) {
        c.getInput(); // waits for a button press then makes a move and requests board from server
        c.updateBoard() // paints the new board onto screen
    }
    
    return 0;
}