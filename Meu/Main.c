#include "BlokusDuo.h"

int main(void)  {
  int currentPlayer = 1, turn = 0;
  int board[16][16], available[2][21];
  MOVE move;
  int check, player1, player2;
  int bonus[2] = { 0, 0 };

  player1 = aiOrHuman(1);
  player2 = aiOrHuman(2);
  
  initBoard(board, available);
  showBoard(board);
  
  do  {
    check = checkPossible(currentPlayer, turn, board, available);
    if(check == 1)  { /*  If there's a possible play  */
      do  {
        move = askMove(currentPlayer, turn, (currentPlayer == 1 ? (player1 == AI ? 1 : 0) : (player2 == AI ? 1 : 0)));
        check = checkMove(currentPlayer, move, board, available, turn);

        if(check != 1)
          readError(check);
      }while(check != 1);
    }
    else  { /*  Fill struct move with 0000 (automatic pass turn)  */
      move.x = 0;
      move.y = 0;
      move.piece = 0;
      move.rotation = 0;
    }

  placeMove(move, board, currentPlayer, available);
  
  checkIfEnd(currentPlayer, bonus, move, available, board);
  
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

int aiOrHuman(int playerNumber) {
  int check;
  
  printf("Would you like AI for Player%d? If yes, insert 1. ", playerNumber);
  scanf("%d", &check);

  if(check == 1)
    return AI; /*  AI  */
  else
    return 0; /*  Human */
}

void readError(int check) {
  switch(check) {
    case PIECE_ALREADY_USED:
      printf("Piece already used.\n");
      break;
    case SPOT_NOT_EMPTY:
      printf("Grid spot not empty.\n");
      break;
    case SHARES_EDGE:
      printf("Piece shares at least one edge with another.\n");
      break;
    case NOT_SHARE_VERTEX:
      printf("Piece doesn't share any vertex with another.\n");
      break;
    case MUST_COVER_55:
      printf("Player 1's first move must cover (5, 5).\n");
      break;
    case MUST_COVER_AA:
      printf("Player 2's first move must cover (a, a).\n");
      break;
    case FIRST_MOVE:
      printf("The first move of each player must not be a pass.\n");
      break;
    default:
      printf("Couldn't read error code.\nThe program will now shutdown.\n");
      exit(0);
  }
}