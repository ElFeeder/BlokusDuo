#include "BlokusDuo.h"

void initBoard(int board[16][16])  {
  int x = 0, y = 0;

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
  
  printf("---------------------- Board ----------------------\n  ");
    /*  Print outside numbers and letters */
    for(x = 0; x < 16; x++)
      printf(" %c", ((x<10) ? x+'0' : x+'a'-10));
    printf("\n");
    for(y = 0; y < 16; y++){
      printf(" %c", ((y<10) ? y+'0' : y+'a'-10));
      /*  Check to see if we reached the border, if so, print a '+' */
      for(x = 0; x < 16; x++)
        printf(" %c", (board[y][x] == 3 ? BORDERFILL : ' '));
      printf("\n");
    }
  printf("---------------------------------------------------\n");
}