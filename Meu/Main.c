#include "BlokusDuo.h"

int main(void)  {
  int currentPlayer = 1, turn = 0, board[16][16], available[2][21];
  int check = 1, bonus[2] = {0, 0}, final = 0;
  int player1, player2;
  MOVE move;
  char previousCode[5] = {'z', 'z', 'z', 'z'};

  player1 = aiOrHuman(1);
  player2 = aiOrHuman(2);
  
  initBoard(board, available);
  showBoard(board);
  
  while(1)  {
    move = checkPossible(currentPlayer, turn, board, available, (currentPlayer == 1 ?
                        (player1 == AI ? 0 : 1) : (player2 == AI ? 0 : 1)), &final, bonus);
    if(move.x == -1)  { /*  If there's a possible play and the player is human  */
      do  {
        move = askMove(currentPlayer, turn, board, available, previousCode, bonus);
        check = checkMove(currentPlayer, move, board, available, turn);

        if(check != 1)
          readError(check);
      }while(check != 1);
    }
    else
      if(move.x != 0 || move.y != 0 || move.piece != 0 || move.rotation != 0)
        printf("AI Play (Player%d)\nX = %d\tY = %d\tPeça = %d\tRotação = %d\n",
            currentPlayer, move.x, move.y, move.piece, move.rotation);

  placeMove(move, board, currentPlayer, available);
  
  checkIfEnd(currentPlayer, bonus, move, available, board);
  
  showBoard(board);

  currentPlayer = switchPlayer(currentPlayer);

  turn++;
  }

  return 0;
}

int switchPlayer(int currentPlayer) {
  return (currentPlayer == 1 ? 2 : 1);
}

int aiOrHuman(int playerNumber) {
  int check;
  
  printf("Would you like AI for Player%d? If yes, insert 1. ", playerNumber);
  scanf("%d", &check);

  return (check == 1 ? AI : 0);
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

void endGame(int board[16][16], int currentPlayer, int available[2][21], int bonus[2])  {
  int pieces1, pieces2;

  showBoard(board);
  
  pieces1 = remainingPieces(1, available);
  pieces2 = remainingPieces(2, available);

  printf(" Tiles: %d / %d, Score: %d / %d.\n", pieces1, pieces2, bonus[0] - pieces1, bonus[1] - pieces2);
    if(pieces1 != pieces2)
      printf("Player %d won the game!\n", ((pieces1 < pieces2) ? 1 : 2 ));
    else
      printf("Draw game.\n");
  
  exit(0);
}