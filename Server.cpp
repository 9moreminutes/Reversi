#include "Server.h"

Server::Server() {
    //make connection socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Error making socket");
    }
    port = 7349;

    //set server address
    bzero((char *) &server, sizeof(server)); //clear variable data
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY; //this address

    //bind socket to server address
    if (bind(sock, server, sizeof(server)) == 0) {
        error("Error binding socket");
        exit(1);
    }

    listen(sock,5);
}

void handleCommand(char * c) {
    //convert char[] to string
    string command(c);

}

void Server::handleStart(string s) {
    playerColor = Tile::WHITE;
    aiColor = Tile::BLACK;

}

void Server::handleMove(Row r, Column c) {
    //Make player move
    game.makeMove(Space(r,c,playerColor));

    //Make AI move
    game.makeMove(Space(r,c,aiColor));
}

void Server::handleUndo() {
    game.undoMove();
}

int main(int argc, char const *argv[])
{
    Server server;
    return 0;
}