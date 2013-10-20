#ifndef ____ai__
#define ____ai__

#include <iostream>
#include "board.h"

using namespace std;

class AI {
private:
    signed int values[8][8] = {
        {99, -8, 8, 6, 6, 6, -8, 99},
        {-8, -24, -4, -3, -3, -4, -24, -8},
        {8, -4, 7, 4, 4, 7, -4, 8},
        {6, -3, 4, 0, 0, 4, -3, 6},
        {6, -3, 4, 0, 0, 4, -3, 6},
        {8, -4, 7, 4, 4, 7, -4, 8},
        {-8, -24, -4, -3, -3, -4, -24, -8},
        {99, -8, 8, 6, 6, 8, -8, -99} };
    
    Tile aiPlayer; //AI Color
    Tile opponent;
    Tile currentTurn;
    
public:
    AI(Tile p) {
        aiPlayer = p;
        if (p == WHITE) opponent = BLACK;
        else opponent = WHITE;
    }
    ~AI();
    
    Space chooseMove(GameEngine game, int depth);
    
    void changeTurn(Tile player);
    
};


#endif
