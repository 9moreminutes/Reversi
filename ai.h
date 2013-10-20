#ifndef ____ai__
#define ____ai__

#include <iostream>
#include "Space.h"
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
        {99, -8, 8, 6, 6, 8, -8, 99} };
    
public:
    AI() {
    }
    ~AI();
    int getValue(GameEngine game, Tile);
    int minimax(GameEngine game, int depth, Tile);
    Space chooseMove(GameEngine game, int depth, Tile);
    
    void changeTurn(Tile player);
    
};


#endif
