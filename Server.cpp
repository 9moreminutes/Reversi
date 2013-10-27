#include "Server.h"

Server::Server(char * p) {
    //make connection socket
    connSock = socket(AF_INET, SOCK_STREAM, 0);
    if (connSock < 0) {
        perror("Error making socket");
    }
    port = atoi(p);

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

void Server::handleStart() {
    playerColor = Tile::WHITE;
    aiColor = Tile::BLACK;
    game.resetGame();
    if (aiGame) {
        cout << "Starting game against AI at " << aiHostname << ":" << aiPort << "...";
        aiSock = socket(AF_INET, SOCK_STREAM, 0);

        struct hostent * aiHost;
        struct sockaddr_in aiServer;
        bzero((char *) &aiServer, sizeof(aiServer)); //clear variable data
        aiServer.sin_family = AF_INET;
        aiServer.sin_port = htons(aiPort);
        aiHost = gethostbyname(aiHostname.c_str());
        bcopy((char *)aiHost->h_addr, (char *)&aiServer.sin_addr.s_addr, aiHost->h_length);
        if (connect(aiSock,(struct sockaddr *) &aiServer,sizeof(aiServer)) < 0) 
            perror("Error connecting to other server");
        cout << "Connected to " << aiHostname << "..." << endl;
        aiColor = WHITE;
        playerColor = BLACK;
        runAI();
    }
}

void Server::runAI() {
    write(aiSock,"HUMAN-AI",8);
    Space first;
    if (aiDiff == EASY) {
        first = ai.chooseMove(game, 1, aiColor);
    }
    else if (aiDiff == MEDIUM) {
        first = ai.chooseMove(game, 3, aiColor);
    }
    else {
        first = ai.chooseMove(game, 5, aiColor);
    }
    game.makeMove(first.getRow(), first.getColumn(), aiColor);
    string s = "";
    switch(first.getColumn()) {
        case Column::a:
            s+="a ";
        break;
        case Column::b:
            s+="b ";
        break;
        case Column::c:
            s+="c ";
        break;
        case Column::d:
            s+="d ";
        break;
        case Column::e:
            s+="e ";
        break;
        case Column::f:
            s+="f ";
        break;
        case Column::g:
            s+="g ";
        break;
        case Column::h:
            s+="h ";
        break;
    }
    switch(first.getRow()) {
        case Row::ONE:
            s+="1";
        break;
        case Row::TWO:
            s+="2";
        break;
        case Row::THREE:
            s+="3";
        break;
        case Row::FOUR:
            s+="4";
        break;
        case Row::FIVE:
            s+="5";
        break;
        case Row::SIX:
            s+="6";
        break;
        case Row::SEVEN:
            s+="7";
        break;
        case Row::EIGHT:
            s+="8";
        break;
    }
    sleep(1);
    if (aiDiff == EASY) {
        write(aiSock, "EASY", 4);
    }
    else if (aiDiff == MEDIUM) {
        write(aiSock, "MEDIUM", 6);
    }
    else {
        write(aiSock, "HARD", 4);
    }
    sleep(1);
    write(aiSock, s.c_str(), 3);
    while(!done()) {
        getCommand();
        handleCommand();
    }
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
    if (game.checkIfValid(Space(playerColor, col, row),playerColor)) {
        char c = row + 64;
        cout << "Player made move at " << c << col << "..." << endl;
        game.makeMove(col-1, row-1, playerColor);
    }
    else {
        char c = row + 64;
        cout << "Player tried invalid move at " << c << col << "..." << endl;
        write(gameSock,"INVALID\n",8);
        return;
    }
    if (aiGame) {
        write(gameSock,game.displayBoard().c_str(),200);
        write(gameSock,game.tallyPoints().c_str(),24);
    }

    //Make AI move
    vector<Space> moves = game.showPossibleMoves(aiColor);
    if(!moves.empty()) {
        Space newMove;
        if (diff == EASY)
            newMove = ai.chooseMove(game,1,aiColor);
        else if (diff == MEDIUM)
            newMove = ai.chooseMove(game,3,aiColor);
        else
            newMove = ai.chooseMove(game,5,aiColor);
        string s = "";
        switch(newMove.getColumn()) {
            case Column::a:
                s+="a ";
            break;
            case Column::b:
                s+="b ";
            break;
            case Column::c:
                s+="c ";
            break;
            case Column::d:
                s+="d ";
            break;
            case Column::e:
                s+="e ";
            break;
            case Column::f:
                s+="f ";
            break;
            case Column::g:
                s+="g ";
            break;
            case Column::h:
                s+="h ";
            break;
        }
        switch(newMove.getRow()) {
            case Row::ONE:
                s+="1";
            break;
            case Row::TWO:
                s+="2";
            break;
            case Row::THREE:
                s+="3";
            break;
            case Row::FOUR:
                s+="4";
            break;
            case Row::FIVE:
                s+="5";
            break;
            case Row::SIX:
                s+="6";
            break;
            case Row::SEVEN:
                s+="7";
            break;
            case Row::EIGHT:
                s+="8";
            break;
        }
        cout << "Making move at " << s << "..." << endl;
        game.makeMove(newMove.getRow(),newMove.getColumn(),aiColor);
        if(!aiGame)
            write(gameSock,(s+"\n").c_str(),s.length()+1);
        else
            write(aiSock,(s).c_str(),s.length()+1);

        if (aiGame) {
            write(gameSock,game.displayBoard().c_str(),200);
            write(gameSock,game.tallyPoints().c_str(),24);
        }
    }
    else {
        write(gameSock,";No possible move\n",18);
        if (aiGame) {
            write(aiSock,";No possible move\n",18);
        }
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
    if (command.substr(0,5) == "AI-AI") {
        command.erase(0,6); // remove AI-AI
        cout << command << endl;
        int space = command.find(' ');
        string hostname = command.substr(0,space);
        command.erase(0,space+1); //remove hostname
        cout << command << endl;
        //check for port
        for (int i = 0; i < command.size(); ++i) {
            if(!isdigit(command[i])) {
                if (isspace(command[i])) {
                    space = i;
                    break;
                }
                return false;
            }
        }
        string portNum = command.substr(0,space);
        command.erase(0,space+1); //remove port
        cout << command << endl;
        //check difficulty 1
        Difficulty newdiff;
        if (command.substr(0,4) == "EASY") {
            newdiff = Difficulty::EASY;
            command.erase(0,5); //remove difficulty 1 and trailing space
        }
        else if (command.substr(0,6) == "MEDIUM") {
            newdiff = Difficulty::MEDIUM;
            command.erase(0,7); //remove difficulty 1 and trailing space
        }
        else if (command.substr(0,4) == "HARD") {
            newdiff = Difficulty::HARD;
            command.erase(0,5); //remove difficulty 1 and trailing space
        }
        else {
            return false;
        }

        //check difficulty 2
        if (command.substr(0,4) == "EASY") {
            aiDiff = Difficulty::EASY;
        }
        else if (command.substr(0,6) == "MEDIUM") {
            aiDiff = Difficulty::MEDIUM;
        }
        else if (command.substr(0,4) == "HARD") {
            aiDiff = Difficulty::HARD;
        }
        else {
            return false;
        }
        aiHostname = hostname;
        aiPort = atoi(portNum.c_str());
        diff = newdiff;
        aiGame = true;
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

void Server::makeAIMove() {
    vector<Space> moves = game.showPossibleMoves(aiColor);
    if(!moves.empty()) {
        Space newMove;
        if (diff == EASY)
            newMove = ai.chooseMove(game,1,aiColor);
        else if (diff == MEDIUM)
            newMove = ai.chooseMove(game,3,aiColor);
        else
            newMove = ai.chooseMove(game,5,aiColor);
        string s = "";
        switch(newMove.getColumn()) {
            case Column::a:
                s+="a ";
            break;
            case Column::b:
                s+="b ";
            break;
            case Column::c:
                s+="c ";
            break;
            case Column::d:
                s+="d ";
            break;
            case Column::e:
                s+="e ";
            break;
            case Column::f:
                s+="f ";
            break;
            case Column::g:
                s+="g ";
            break;
            case Column::h:
                s+="h ";
            break;
        }
        switch(newMove.getRow()) {
            case Row::ONE:
                s+="1";
            break;
            case Row::TWO:
                s+="2";
            break;
            case Row::THREE:
                s+="3";
            break;
            case Row::FOUR:
                s+="4";
            break;
            case Row::FIVE:
                s+="5";
            break;
            case Row::SIX:
                s+="6";
            break;
            case Row::SEVEN:
                s+="7";
            break;
            case Row::EIGHT:
                s+="8";
            break;
        }
        cout << "Making move at " << s << "..." << endl;
        game.makeMove(newMove.getRow(),newMove.getColumn(),aiColor);
        if(!aiGame)
            write(gameSock,(s+"\n").c_str(),s.length()+1);
        else
            write(aiSock,(s).c_str(),s.length()+1);

        if (aiGame) {
            write(gameSock,game.displayBoard().c_str(),200);
            write(gameSock,game.tallyPoints().c_str(),24);
        }
    }
    else {
        write(gameSock,";No possible move\n",18);
        if (aiGame) {
            write(aiSock,";No possible move\n",18);
        }
    }
}
void Server::handleCommand() {
    //convert char[] to string
    string command(buffer);

    //make sure command is valid
    if (!isValid(command)) {
        if (!aiGame)
            write(gameSock,"ILLEGAL\n",8);
        return;
    }

    if (command.substr(0,4) == "EXIT") {
        cout << "EXIT command recieved...exiting" << endl;
        gameover = true;
        return;
    }

    if (!started) {
        if (checkStart(command)) {
            if (command.substr(0,8) == "HUMAN-AI") {
                write(gameSock,"OK\n",3);
                cout << "Starting human vs. AI game..." << endl;
                started = true;
                handleStart();
            }
            else {
                write(gameSock,"OK\n",3);
                cout << "Starting AI vs. AI game..." << endl;
                started = true;
                handleStart();
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
        return;
    }

    if (command.substr(0,7) == "DISPLAY") {
        write(gameSock,game.displayBoard().c_str(),200);
        write(gameSock,game.tallyPoints().c_str(),24);
        return;
    }

    if (command.substr(0,4) == "UNDO") {
        game.undoMove();
        return;
    }
}

void Server::getCommand() {
    bzero(buffer, 256);
    if(!aiGame)
        read(gameSock, buffer, 256);
    else
        read(aiSock, buffer, 256);
}

bool Server::done() {
    return (gameover || game.gameOver());
}

int main(int argc, char *argv[])
{
    Server server(argv[1]);
    server.waitForConnection();
    while(!server.done()) {
        server.getCommand();
        server.handleCommand();
    }

    return 0;
}