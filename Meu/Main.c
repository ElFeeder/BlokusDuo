#include "BlokusDuo.h"

int main(void)  {
  int currentPlayer = 1, turn = 0;
  int board[16][16], available[2][21];
  MOVE move;
  int check;
  int bonus[2] = { 0, 0 };

  initBoard(board, available);
  showBoard(board);

  do  {
    do  {
      move = askMove(currentPlayer, turn);
      check = checkMove(currentPlayer, move, board, available, turn);
    }while(check != 1);

  placeMove(move, board, currentPlayer, available);
  
  check = checkIfEnd(currentPlayer, bonus, move, available, board);
  if(check == 1)
    return 0;
  
  showBoard(board);

  currentPlayer = switchPlayer(currentPlayer);

  turn++;
  }while(1);

  return 0;
}

int switchPlayer(int currentPlayer) {
  if(currentPlayer == 1)
    currentPlayer = 2;
  else
    currentPlayer = 1;

  return currentPlayer;
}