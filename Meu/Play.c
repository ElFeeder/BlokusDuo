#include "BlokusDuo.h"

MOVE askMove(int currentPlayer, int turn)  {
  MOVE move;
  char code[5];

  printf("Turn %d\n", turn);
  printf("Player %d: ", currentPlayer == 1 ? 1 : 2);

  scanf("%s", code);
  printf("%s\n", code);

  move = decodeCode(code);
  
  return move;
}

MOVE decodeCode(char* code) {
  MOVE move;
  char ch;

  /*  We'll analise each character from the code.
      The first and the second are the board coordinates in which
      the center of the selected piece (third character) must be
      placed. The fourth character indicates the rotation of the
      piece. For more information, see Pieces.h */
  ch = code[0];
  if('0' <= ch && ch <= '9')
    move.x = ch - '0';
  if('a' <= ch && ch <= 'e')
    move.x = ch - 'a' + 10;

  ch = code[1];
  if('0' <= ch && ch <= '9')
    move.y = ch - '0';
  if('a' <= ch && ch <= 'e')
    move.y = ch - 'a' + 10;

  ch = code[2];
  move.piece = ch - 'a';

  ch = code[3];
  move.rotation = ch - '0';
}