#include <stdio.h>

#define BORDERFILL '+'

typedef struct move {
  int x;
  int y;
  int piece;
  int rotation;
} MOVE;

/*  Board.c */
void initBoard(int board[16][16]);

/*  Play.c  */
MOVE askMove(int currentPlayer, int turn);