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

<<<<<<< HEAD
Space AI::chooseMove(GameEngine game, int depth) {
=======
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
>>>>>>> c38ba33509ee7d28aad5182067e4bd60391c06cd
	
	if (game.gameOver() || depth == 0){
        return;
    }
        
<<<<<<< HEAD
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
=======
	vector<Space> moves = game.getPossibleMoves(player);
    if isTurn(player)
        //do best move
	else
		//doworst move
            
            
}
>>>>>>> c38ba33509ee7d28aad5182067e4bd60391c06cd
