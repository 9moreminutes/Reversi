#include "Server.h"

Server::Server() {
    //make connection socket
    connSock = socket(AF_INET, SOCK_STREAM, 0);
    if (connSock < 0) {
        perror("Error making socket");
    }
    port = 7349;

    //set server address
    bzero((char *) &server, sizeof(server)); //clear variable data
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY; //this address

    //bind socket to server address
    if (bind(connSock, (struct sockaddr *) &server, sizeof(server)) != 0) {
        perror("Error binding socket");
        exit(1);
    }

    listen(connSock,5);
}

Server::~Server() {

}

void Server::handleCommand(char * c) {
    //convert char[] to string
    //string command(c);

}

void Server::waitForConnection() {
    clilen = sizeof(client);
    gameSock = accept(connSock, (struct sockaddr *) &client, (socklen_t*) &clilen);
    if (gameSock < 0)
        perror("Error accepting connection");
    write(gameSock,"WELCOME", 7);
}
void Server::handleStart(string s) {
    ////playerColor = Tile::WHITE;
    //aiColor = Tile::BLACK;
    //game.resetGame();
}

void Server::handleMove(Row r, Column c) {
    //Make player move
    //game.makeMove(Space(r,c,playerColor));

    //Make AI move
    //game.makeMove(Space(r,c,aiColor));
}

void Server::handleUndo() {
    //game.undoMove();
}

int main(int argc, char const *argv[])
{
    Server server;
    server.waitForConnection();


    return 0;
}