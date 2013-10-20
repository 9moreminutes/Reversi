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

int AI::getValue(GameEngine game, Tile player) {
	int playerValue = 0,
		oppValue = 0;
	for (int i = 0 ; i < 8 ; ++i) {
		for (int j = 0 ; j < 8 ; ++j) {
			if (game.getSpace(i,j) == player) {
				playerValue += values[i][j];
			}
			else if (game.getSpace(i,j) == opposite(player)) {
				oppValue += values[i][j];
			}
		}
	}
	return playerValue - oppValue;
}

Space AI::chooseMove(GameEngine game, int depth)
{
	
	if (game.gameOver() || depth == 0){
        return;
    }
        
	vector<Space> moves = game.getPossibleMoves(player);
    if isTurn(player)
        //do best move
	else
		//doworst move
            
            
}
