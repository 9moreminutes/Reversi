#include "Server.h"

Server::Server() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
}

void handleCommand() {

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