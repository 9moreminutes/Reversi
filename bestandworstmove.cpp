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
   a   b   c   d   e   f   g   h


*/
class char_importance{
  char status;
  int importance;
};

Position best_move(vector<vector<char_importance>> board){
  Space current_space;
  int most_important = INT_MIN;
  
  for(unsigned int i=0; i < available_moves.size(); i++){
    int temp = worst_move(board_if_move_is_applied);
	
    if(temp > most_imporant){
      current_space.row = available_moves[i].row;
      current_space.column = available_moves[i].column;
	  most_important = temp;
    }
  }
  return position;
}

Position worst_move(vector<vector<char_importance>> board){
  Space current_space;
  int least_important = INT_MAX;
  
  for(unsigned int i=0; i < available_moves.size(); i++){
    int temp = best_move(board_if_move_is_applied);
	
    if(temp > most_important){
      current_space.row = available_moves[i].row;
      current_space.column = available_moves[i].column;
      least_important = temp;
    }
  }
  return position;
}