#include "BlokusDuo.h"
#include "PiecesRotation.h"

MOVE askMove(int currentPlayer, int turn)  {
  MOVE move;
  char code[5];
  int check;

  do  {
    printf("Turn %d\n", turn);
    printf("Player %d: ", currentPlayer == 1 ? 1 : 2);

    scanf("%s", code);

    check = checkCode(code);
    if(check == 0)
      printf("Invalid code.\n");
  } while(check != 1);
  
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

  return move;
}

int checkCode(char* code)  {
  char ch;

  /*  We'll evaluate each character to see if it
      corresponds to a valid play.  */

  ch = code[0];
  if(! (('0'<= ch && ch <= '9') || ('a' <= ch && ch <= 'e')) ) return FALSE;

  ch = code[1];
  if(! (('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'e')) ) return FALSE;

  ch = code[2];
  if(! ('a' <= ch && ch <= 'u') ) return FALSE;

  ch = code[3];
  if(! ('0' <= ch && ch <= '7') ) return FALSE;

  return TRUE;
}

int checkMove(int currentPlayer, MOVE move, int board[16][16], int available[2][21], int turn) {
  int xOffset = move.x - 2, yOffset = move.y - 2, valid = FALSE;
  int x, y, b, xx, yy;

  /*  Check piece availability  */
  if(available[currentPlayer - 1][move.piece] == 0) {
    printf("Piece already used.\n");
    return 0;
  }

  /* Check if we can place our piece in the requested grid space  */
  for(y = 0; y < 5; y++)  {
    for(x = 0; x < 5; x++)  {
      b = pieces[move.piece][0][rotation[move.rotation][y][x]];
      if(b == 1) {
        if(board[yOffset + y][xOffset + x] != 0 || yOffset + y < 0 ||
          15 < yOffset + y || xOffset + x < 0 || 15 < xOffset + x) {
          printf("Can't place the piece there.\n");
          return 0;
        }
      }
    }
  }

  /*  Check if the piece shared any edges */
  for(y = 0; y < 5; y++)  {
    for(x = 0; x < 5; x++)  {
      b = pieces[move.x][0][rotation[move.rotation][y][x]];
      if(b == 1) {
        xx = xOffset + x;
        yy = yOffset + y;
        if(board[yy][xx-1] == currentPlayer || board[yy][xx+1] == currentPlayer ||
          board[yy-1][xx] == currentPlayer || board[yy+1][xx] == currentPlayer )  {
          printf("Piece shares at least one edge with another.\n");
          return 0;
        }
      }
    }
  }

  /*  Check if it shares at least one vertex  */
  if(turn >= 2) {
    for(y = 0; y < 5; y++)  {
      for(x = 0; x < 5; x++)  {
        b = pieces[move.piece][0][rotation[move.rotation][y][x]];
        if(b == 1) {
          xx = xOffset + x;
          yy = yOffset + y;
          if(board[yy - 1][xx - 1] == currentPlayer || board[yy + 1][xx - 1]
            == currentPlayer || board[yy - 1][xx + 1] == currentPlayer ||
            board[yy + 1][xx + 1] == currentPlayer)
            valid = TRUE;
        }
      }
    }

    if(valid == FALSE)  {
      printf("Piece doesn't share any vertex.\n");
      return 0;
    }
  }
  else  {
    /* Player 1's first move must cover (5,5) */
    if(currentPlayer == 1 && ! (3 <= move.x && move.x <= 7 && 3 <= move.y
      && move.y <= 7 && pieces[move.piece][0][rotation[move.rotation]
      [5 - yOffset][5 - xOffset]] == 1)) {
        printf("Player 1's first move must cover (5, 5).\n");
	      return 0;
      }

      /* Player 2's first move must cover (a,a) */
      if(currentPlayer == 2 && ! (8 <= move.x && move.x <= 12 &&
        8 <= move.y && move.y <= 12 && pieces[move.piece][0][rotation[move.rotation]
        [10 - yOffset][10 - xOffset]] == 1)) {
          printf("Player 2's first move must cover (a, a).\n");
	        return 0;
      }
  }

  /* If we reach this point, the move is valid. */
  return 1;
}

void placeMove(MOVE move, int board[16][16], int currentPlayer, int available[2][21])  {
  int x, y, b;
  int xOffset = move.x - 2, yOffset = move.y - 2;

  for(y = 0; y < 5; y++)  {
    for(x = 0; x < 5; x++)  {
      b = pieces[move.piece][0][rotation[move.rotation][y][x]];
      if(b == 1)
        board[yOffset + y][xOffset + x] = currentPlayer;
    }
  }

  /* A piece was used, it can no longer be used by this player */
  available[currentPlayer - 1][move.piece] = 0;
}

int checkIfEnd(int currentPlayer, int bonus[2], MOVE move, int available[2][21], int board[16][16]) {
  if(remainingPieces(currentPlayer, available) == 0)  {
    bonus[currentPlayer - 1] = 15;
    if(move.piece == 0) /* If we finish with the individual piece */
      bonus[currentPlayer - 1] = 20;

    showBoard(board);
    printf("Player %d finished his pieces, so he won!\n", currentPlayer);
  
    return 1;
  }

  /*  If we reached this point, the game hasn't ended */
  return 0;
}