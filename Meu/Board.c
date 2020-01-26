#include "BlokusDuo.h"
#include "PieceSizes.h"

void initBoard(int board[16][16], int available[2][21])  {
  int x = 0, y = 0;

  /*  At the beggining, every piece is available for
      each player.  */
  for(y=0; y<2; y++)
    for(x=0; x<21; x++)
      available[y][x] = 1;
  
  /*  Fill board with 0 */
  for(y=0; y<16; y++)
    for(x=0; x<16; x++)
      board[y][x] = 0;
      
  /*  Fill the border */
  for(x=0; x<16; x++){
    board[ 0][ x] = 3;
    board[15][ x] = 3;
    board[ x][ 0] = 3;
    board[ x][15] = 3;
  }
}

int remainingPieces(int currentPlayer, int available[2][21])  {
  int i, a = 0;

  for(i = 0; i < 21; i++)
    a += available[currentPlayer - 1][i] * pieceSizes[i];

  return a;
}

void showBoard(int board[16][16])  {
  int x, y;
  
  printf("---------------------- Board ----------------------\n  ");
    /*  Print outside numbers and letters */
    for(x = 0; x < 16; x++)
      printf(" %c", ((x<10) ? x+'0' : x+'a'-10));
    printf("\n");
    for(y = 0; y < 16; y++){
      printf(" %c", ((y<10) ? y+'0' : y+'a'-10));
      /*  Check to see if we need to print a piece or border */
      for(x = 0; x < 16; x++)
        printf(" %c", (board[y][x] == 0 ? ' ' : board[y][x] < 3 ? board[y][x] + '0' : BORDERFILL));
      printf("\n");
    }
  printf("---------------------------------------------------\n");
}