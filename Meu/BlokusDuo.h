#include <stdio.h>

#define BORDERFILL '+'

typedef struct {
  int x;
  int y;
  int piece;
  int rotation;
} MOVE;

void initBoard();