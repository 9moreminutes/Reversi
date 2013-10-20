# include "board.h"
using namespace std;

GameEngine::~GameEngine() {
    
}

string GameEngine::displayBoard(){
    //set top row of column
    char boardarray[200] = {';',' ', ' ', '_', ' ', '_', ' ', '_', ' ', '_', ' ', '_', ' ', '_', ' ', '_', ' ', '_', ' ', '\n'};

    
    
    int n = 19; //there are 20 characters per row (including '\n')
    
    //print tiles row by row
    for (int i = 0; i < board.size(); i++){
        ++n;
        boardarray[n] =';';
        //store number
        ++n;
        switch (i) {
            case 0:
                boardarray[n] = '1';
                break;
            case 1:
                boardarray[n] = '2';
                break;
            case 2:
                boardarray[n] = '3';
                break;
            case 3:
                boardarray[n] = '4';
                break;
            case 4:
                boardarray[n] = '5';
                break;
            case 5:
                boardarray[n] = '6';
                break;
            case 6:
                boardarray[n] = '7';
                break;
            case 7:
                boardarray[n] = '8';
                break;
                
            default:
                break;
        }
        
        //store first '|'
        ++n;
        boardarray[n] = '|';
        
        //store player
        //go through each column in current row
        for (int j = 0; j < board[i].size(); ++j){
            ++n;
            if (board[i][j].getTile() == WHITE) boardarray[n] = 'O';
            else if (board[i][j].getTile() == BLACK) boardarray[n] = '@';
            else boardarray[n] = '_';
            
            ++n;
            boardarray[n] = '|';
        }
        
        //finish row with newline
        ++n;
        boardarray[n] = '\n';
        
    }
    
    
    //last row of chars
    ++n;
    boardarray[n] = ';';

    ++n;
    boardarray[n] = ' ';
    
    ++n;
    boardarray[n] = ' ';
    
    for (int i = 0; i < 8; ++i){
        ++n;
        boardarray[n] = i+65;
        
        ++n;
        boardarray[n] = ' ';
        
    }
    
    ++n;
    boardarray[n] = '\n';
    
    return string(boardarray);
    
}

void GameEngine::drawBoard(){
    for(int i = 0; i<8; ++i){
        for(int j = 0; j < 8; ++j){
            cout << board[i][j].getTile() << " ";
        }
        cout << endl;
    }
}

//flip tiles and update the board
void GameEngine::makeMove(int row, int col, Tile player){
    //check if valid move
    cout << "ROW:" << row << endl;
    cout << "COL:" << col << endl;
    if (!checkIfValid(Space(player,row+1,col+1), player)){
        return; //do nothing.
    }
    
    //make copy of current board in case of undo
    undo = board;

    int x = row;
    int y = col;

    board[x][y].setTile(player);
    directions.clear();
    int xdir =1, ydir = 1;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            directions.push_back(4);
        }
    }
    xdir = 1;
    ydir = 0;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            directions.push_back(0);
        }
    }
    xdir = 1;
    ydir = -1;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            directions.push_back(6);
        }
    }
    xdir = 0;
    ydir = 1;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            directions.push_back(2);
        }
    }
    xdir = 0;
    ydir = -1;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            directions.push_back(3);
        }
    }
    xdir = -1;
    ydir = 1;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            directions.push_back(5);
        }
    }
    xdir = -1;
    ydir = 0;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            directions.push_back(1);
        }
    }
    xdir = -1;
    ydir = -1;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            directions.push_back(7);
        }
    }
    cout << directions.size() << endl;
    for (int i = 0; i < directions.size(); ++i) {
        goThroughSpaces(directions[i], x, y);
        while (isOnBoard(x,y) && board[x][y].getTile() != player && board[x][y].getTile() != EMPTY) {
            board[x][y].setTile(player);
            goThroughSpaces(directions[i],x,y);
        }
        x=row;
        y=col;
    }
    changeTurn();
}

//go through each space in a specified direction
void GameEngine::goThroughSpaces(int i, int &x, int &y){
    switch (i) {
            //check right
        case 0:
            ++x;
            break;
            
            //check left
        case 1:
            --x;
            break;
            
            //check down
        case 2:
            ++y;
            break;
            
            //check up
        case 3:
            --y;
            break;
            
            //check diagonal right down
        case 4:
            ++x;
            ++y;
            break;
            
            //check diagonal left down
        case 5:
            --x;
            ++y;
            break;
            
            //check diagonal right up
        case 6:
            ++x;
            --y;
            break;
            
            //check diagonal left up
        case 7:
            --x;
            --y;
            break;
            
        default:
            break;
    }
}

bool GameEngine::checkIfValid(Space s, Tile player){
    int x = s.getRow();
    int y = s.getColumn();

    int xdir =1, ydir = 1;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            return true;
        }
    }
    xdir = 1;
    ydir = 0;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            return true;
        }
    }
    xdir = 1;
    ydir = -1;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            return true;
        }
    }
    xdir = 0;
    ydir = 1;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            return true;
        }
    }
    xdir = 0;
    ydir = -1;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            return true;
        }
    }
    xdir = -1;
    ydir = 1;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            return true;
        }
    }
    xdir = -1;
    ydir = 0;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            return true;
        }
    }
    xdir = -1;
    ydir = -1;
    if (isOnBoard(x+xdir,y+ydir) && board[x+xdir][y+ydir].getTile() == opposite(player)) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() != player && board[x+xdir+i][y+ydir+j].getTile() != EMPTY) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == player) {
            return true;
        }
    }
    return false;
}

bool GameEngine::isOnBoard(int row, int column){
    if ( row < 0 || row > 7 || column < 0 || column > 7) return false;
    else return true;
}

void GameEngine::undoMove(){
    
    board = undo;
    
}

vector <Space> GameEngine::showPossibleMoves(Tile player){
    vector <Space> result;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j].getTile() == EMPTY){
                Space s = Space(player, i+1, j+1);
                cout << s.getRow() << s.getColumn() << endl;
                if(checkIfValid(s, player)){
                    result.push_back(s);
                }
            }
        }
    }
    for(int k = 0; k < result.size(); k++){
        cout << result[k].getRow() << result[k].getColumn() << endl;
    }
    return result;
}

void GameEngine::resetGame() {
    board.clear();
    for(int i = 1; i <= 8; ++i){
        vector<Space> columns;
        board.push_back(columns);
        for(int j = 1; j <= 8; ++j){
            if((i == 4 && j == 5) || (i == 5 && j ==4)){
                Space s = Space(WHITE, i, j);
                board[i-1].push_back(s);
            }else if(((i == 4 && j == 4) || (i == 5 && j == 5))){
                Space s = Space(BLACK, i, j);
                board[i-1].push_back(s);
            }else {
                Space s = Space(EMPTY, i, j);
                board[i-1].push_back(s);
            }
        }
    }
}

bool GameEngine::checkDirection(int x, int y, int xdir, int ydir, Tile enemycolor){
    if (board[x+xdir][y+ydir].getTile() == enemycolor) {
        int i = xdir;
        int j = ydir;
        while (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == enemycolor) {
            i+=xdir;
            j+=ydir;
        }
        if (isOnBoard(x+xdir+i,y+ydir+j) && board[x+xdir+i][y+ydir+j].getTile() == opposite(enemycolor)) {
            return true;
        }
    }
    return false;
}

void GameEngine::setSpace(Tile t, int row, int column){
    board[row][column].setTile(t);
}

Tile GameEngine::getSpace(int col, int row) {
    return board[row][col].getTile();
}

bool GameEngine::isTurn(Tile player) {
    if (turn == player)
        return true;
    return false;
}

void GameEngine::changeTurn() {
    if (turn == WHITE)
        turn = BLACK;
    else
        turn = WHITE;
}

bool GameEngine::gameOver() {
    for (int i = 0; i < board.size(); ++i){
        for (int j = 0; i < board[j].size(); ++j){
            if (board[i][j].getTile() == EMPTY) return false;
            else continue;
        }
    }
    return true;
}

Tile GameEngine::opposite(Tile color){
    Tile tile;
    if (color == WHITE){
        tile = BLACK;       
    }
    else if (color == BLACK){
        tile = WHITE;
    }
    else{
        tile = EMPTY;
    }
    return tile;
}