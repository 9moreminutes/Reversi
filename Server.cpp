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
    close(connSock);
    close(gameSock);
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
    cout << command << endl;
    if (command.substr(0,4) == "UNDO" || 
        command.substr(0,7) == "DISPLAY" || 
        command.substr(0,4) == "EXIT" ||
        command.substr(0,4) == "EASY" ||
        command.substr(0,6) == "MEDIUM" ||
        command.substr(0,4) == "HARD") {
        cout << "Command was keyword" << endl;
        return true;
    }

    return checkMove(command) || checkStart(command);
}

bool Server::checkMove(string command) {
    return ((command[0] > 64 && command[0] < 73) || (command[0] > 96 && command[0] < 105)) && (command[2] > 48 && command[2] < 57);
}

bool Server::checkStart(string command) {
    if (command.substr(0,8) == "HUMAN-AI") {
        return true;
    }
    return false;
}

void Server::waitForConnection() {
    clilen = sizeof(client);
    gameSock = accept(connSock, (struct sockaddr *) &client, (socklen_t*) &clilen);
    if (gameSock < 0)
        perror("Error accepting connection");
    write(gameSock,"WELCOME\n", 8);
}

void Server::handleCommand() {
    //convert char[] to string
    string command(buffer);

    //make sure command is valid
    if (!isValid(command)) {
        write(gameSock,"ILLEGAL\n",8);
        return;
    }

    if (command.substr(0,4) == "EXIT") {
        cout << "EXIT command recieved...exiting" << endl;
        donef = true;
        return;
    }

    if (!started) {
        if (checkStart(command)) {
            if (command.substr(0,8) == "HUMAN-AI") {
                write(gameSock,"OK\n",3);
                cout << "Starting human vs. AI game..." << endl;
                started = true;
            } 
        }
        else {
            write(gameSock,"ILLEGAL\n",8);
        }
        return;
    }

    if (command.substr(0,4) == "EASY" || command.substr(0,6) == "MEDIUM" || command.substr(0,4) == "HARD") {
        if (command.substr(0,4) == "EASY") {
            diff = EASY;
            write(gameSock,"OK\n",3);
            return;
        }
        if (command.substr(0,6) == "MEDIUM") {
            diff = MEDIUM;
            write(gameSock,"OK\n",3);
            return;
        }
        diff = HARD;
        write(gameSock,"OK\n",3);
        return;
    }

    if (checkMove(command)) {
        write(gameSock,"YOU MADE A MOVE\n",16);
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
    while(!server.done()) {
        server.getCommand();
        server.handleCommand();
    }

    return 0;
}