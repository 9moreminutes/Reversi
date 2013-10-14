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

void Server::handleMove(string move) {
    int col = move[2] - 48;
    int row;
    if (isupper(move[0])) {
        row = move[0] - 64;
    }
    else {
        row = move[0] - 96;
    }
    //Make player move
    if (game.checkIfValid(Space(playerColor, row, col),playerColor)) {
        game.makeMove(Space(playerColor, row, col),playerColor);
        char c = row + 64;
        cout << "Player made move at " << c << col << "..." << endl;
    }
    else {
        char c = row + 64;
        cout << "Player tried invalid move at " << c << col << "..." << endl;
        write(gameSock,"INVALID\n",8);
        return;
    }
    //Make AI move
    vector<Space> moves = game.showPossibleMoves(aiColor);
    if(!moves.empty()) {
        string s;
        switch(moves[0].getColumn()) {
            case 0:
                s+="a ";
            break;
            case 1:
                s+="b ";
            break;
            case 2:
                s+="c ";
            break;
            case 3:
                s+="d ";
            break;
            case 4:
                s+="e ";
            break;
            case 5:
                s+="f ";
            break;
            case 6:
                s+="g ";
            break;
            case 7:
                s+="h ";
            break;
        }
        cout << s;
        cout << "Making move at " << moves[0].getColumn() << moves[0].getRow() << "..." << endl;
        game.makeMove(moves[0],aiColor);
        write(gameSock,"2",1);
    }
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
                handleStart(command);
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
            cout << "Difficulty set to EASY..." << endl;
            return;
        }
        if (command.substr(0,6) == "MEDIUM") {
            diff = MEDIUM;
            write(gameSock,"OK\n",3);
            cout << "Difficulty set to MEDIUM..." << endl;
            return;
        }
        diff = HARD;
        write(gameSock,"OK\n",3);
        cout << "Difficulty set to HARD..." << endl;
        return;
    }

    if (checkMove(command)) {
        handleMove(command);
        write(gameSock,"YOU MADE A MOVE\n",16);
        return;
    }

    if (command.substr(0,7) == "DISPLAY") {
        //game.display();
    }

    if (command.substr(0,4) == "UNDO") {
        game.undoMove();
    }
}

void Server::getCommand() {
    bzero(buffer, 64);
    read(gameSock, buffer, 64);
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