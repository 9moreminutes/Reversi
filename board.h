#ifndef _board_h_
#define _board_h_

#include <vector>
#include <stack>
#include <string>
#include <iostream>

#include "Space.h"

using namespace std;

class GameEngine{
private:
    vector <vector <Space> > board;
    
    stack <Space> moves;
    
    vector <vector <Space> > undo;
    
    vector <int> directions; //holds which of the 8 directions are valid
    
    
public:
    //constructor, initializes board
    GameEngine(){
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
    ~GameEngine();
    //push and pop functions to modify stack
    Space popMove(){
        Space s = moves.top();
        moves.pop();
        return s;
    }
    void pushMove(Space s){
        moves.push(s);
    }
    

    string displayBoard();
    
    
    void makeMove(Space s, Tile player);
    void goThroughSpaces(int i, int &x, int &y);
    bool checkIfValid(Space s, Tile player);
    bool isOnBoard(int row, int column);
    void undoMove(); // pops move from stack and undoes
    vector<Space> showPossibleMoves(Tile player); //if empty, no moves
    int tallyPoints();
    void resetGame();
    bool checkDirection(int row, int column, int xdirec, int ydirec, Tile enemycolor);
    void drawBoard();
    void setSpace(Tile t, int row, int column);
};

#endif
