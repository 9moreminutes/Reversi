#include "Server.h"

Server::Server() {
    diff = Difficulty::EASY;
    started = false;

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

void Server::handleStart(string s) {
    playerColor = Tile::WHITE;
    aiColor = Tile::BLACK;
    game.resetGame();
}

void Server::handleMove(Row r, Column c) {
    //Make player move
    game.makeMove(Space(r,c,playerColor),playerColor);

    //Make AI move
    game.makeMove(Space(r,c,aiColor),aiColor);
}

void Server::handleUndo() {
    game.undoMove();
}

bool Server::isValid(string command) {
    if (command == "UNDO" || 
        command == "DISPLAY" || 
        command == "EXIT" ||
        command == "EASY" ||
        command == "MEDIUM" ||
        command == "HARD") {
        return true;
    }

    return checkMove(command) || checkStart(command);
}

bool Server::checkMove(string command) {
    return (command.length() == 3) && 
           ((command[3] > 64 && command[3] < 73) || (command[3] > 96 && command[3] < 105)) && 
           (command[3] > 48 && command[3] < 57);
}

bool Server::checkStart(string command) {
    return false;
}

void Server::waitForConnection() {
    clilen = sizeof(client);
    gameSock = accept(connSock, (struct sockaddr *) &client, (socklen_t*) &clilen);
    if (gameSock < 0)
        perror("Error accepting connection");
    write(gameSock,"WELCOME", 7);
}

void Server::handleCommand() {
    //convert char[] to string
    string command(buffer);

    //make sure command is valid
    if (!isValid(command)) {
        write(gameSock,"ILLEGAL",7);
    }

    if (!started) {
        if (!checkStart(command)) {
            write(gameSock,"ILLEGAL",7);
            return;
        }
    }

    if (command == "EASY" || command == "MEDIUM" || command == "HARD") {
        if (command == "EASY") {
            diff = EASY;
            write(gameSock,"OK",2);
            return;
        }
        if (command == "MEDIUM") {
            diff = MEDIUM;
            write(gameSock,"OK",2);
            return;
        }
        diff = HARD;
        write(gameSock,"OK",2);
        return;
    }

    if (checkMove(command)) {
        write(gameSock,"YOU MADE A MOVE",2);
        return;
    }
}

void Server::getCommand() {
    bzero(buffer, 256);
    read(gameSock, buffer, 256);
}

int main(int argc, char const *argv[])
{
    Server server;
    server.waitForConnection();
    while(true) {
        server.getCommand();
        server.handleCommand();
    }


    return 0;
}