#ifndef BLOKUSDUO_H
#define BLOKUSDUO_H

#include <stdio.h>

#define BORDERFILL '+'

#define TRUE 1
#define FALSE 0

typedef struct move {
  int x;
  int y;
  int piece;
  int rotation;
} MOVE;

/*  Main.c  */
int switchPlayer(int currentPlayer);


/*  Board.c */
void initBoard(int board[16][16], int available[2][21]);
void showBoard(int board[16][16]);

int remainingPieces(int currentPlayer, int available[2][21]);


/*  Play.c  */
MOVE askMove(int currentPlayer, int turn);
MOVE decodeCode(char* code);

int checkCode(char* code);
int checkMove(int currentPlayer, MOVE move, int board[16][16], int available[2][21], int turn);
int checkIfEnd(int currentPlayer, int bonus[2], MOVE move, int available[2][21], int board[16][16]);

void placeMove(MOVE move, int board[16][16], int currentPlayer, int available[2][21]);

#endif