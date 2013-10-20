#include "ai.h"

/* Possible Tile Values??
 ___ ___ ___ ___ ___ ___ ___ ___
 1| 99| -8|  8|  6|  6|  8| -8| 99|
 2| -8|-24| -4| -3| -3| -4|-24| -8|
 3|  8| -4|  7|  4|  4|  7| -4|  8|
 4|  6| -3|  4|  0|  0|  4| -3|  6|
 5|  6| -3|  4|  0|  0|  4| -3|  6|
 6|  8| -4|  7|  4|  4|  7| -4|  8|
 7| -8|-24| -4| -3| -3| -4|-24| -8|
 8| 99| -8|  8|  6|  6|  8| -8| 99|
 a   b   c   d   e   f   g   h*/

//EASY depth 1
//MEDIUM depth 3
//HARD depth 5

Space AI::chooseMove(GameEngine game, int depth) {
	
	if (game.gameOver() || depth == 0){
        return;
    }
        
		vector<Space> moves = game.getPossibleMoves(player);
    if (currentTurn == aiPlayer)
        changeTurn(currentTurn);
        //do best move
    else
        //doworst move
            
            
}

void AI::changeTurn(Tile player) {
    if (player == WHITE) currentTurn = BLACK;
    else currentTurn = WHITE;
}
