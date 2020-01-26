#include "BlokusDuo.h"
#include "PiecesRotation.h"

MOVE askMove(int currentPlayer, int turn, int ai)  {
  MOVE move;
  char code[5];
  int check;
  
  if(ai == 0)  {  /*  If player is human  */
    do  {
      printf("Turn %d\n", turn);
      printf("Player %d: ", currentPlayer == 1 ? 1 : 2);

      scanf("%s", code);

      check = checkCode(code);
      
      if(check == 0)
        printf("Invalid code.\n");
    } while(check != 1);
  }
  else  { /*  If player is AI */

  }
  
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
      piece. If the code is 0000, that indicates that the player
      wants to pass the turn. For more information, see Pieces.h */
  
  if(strcmp("0000", code) == 0) {
    move.x = 0;
    move.y = 0;
    move.piece = 0;
    move.rotation = 0;
    
    return move;
  }

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
  if(! (('a' <= ch && ch <= 'u') || ch == '0')) return FALSE;

  ch = code[3];
  if(! (('0' <= ch && ch <= '7') || ch == '0')) return FALSE;

  return TRUE;
}

int checkMove(int currentPlayer, MOVE move, int board[16][16], int available[2][21], int turn) {
  int xOffset = move.x - 2, yOffset = move.y - 2, valid = FALSE;
  int x, y, b, xx, yy;

  /*  Check if pass */
  if(move.x == 0 && move.y == 0 && move.piece == 0 && move.rotation == 0) {
    /*  Check if it's the first turn of this player */
    if((turn == 0 && currentPlayer == 1) || (turn == 1 && currentPlayer == 2))
      return FIRST_MOVE;
    return 1;
  }

  /*  Check piece availability  */
  if(available[currentPlayer - 1][move.piece] == 0)
    return PIECE_ALREADY_USED;

  /* Check if we can place our piece in the requested grid space  */
  for(y = 0; y < 5; y++)  {
    for(x = 0; x < 5; x++)  {
      b = pieces[move.piece][0][rotation[move.rotation][y][x]];
      if(b == 1) {
        if(board[yOffset + y][xOffset + x] != 0 || yOffset + y < 0 ||
          15 < yOffset + y || xOffset + x < 0 || 15 < xOffset + x)
          return SPOT_NOT_EMPTY;
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
          board[yy-1][xx] == currentPlayer || board[yy+1][xx] == currentPlayer )
          return SHARES_EDGE;
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

    if(valid == FALSE)
      return NOT_SHARE_VERTEX;

  }
  else  {
    /* Player 1's first move must cover (5,5) */
    if(currentPlayer == 1 && ! (3 <= move.x && move.x <= 7 && 3 <= move.y
      && move.y <= 7 && pieces[move.piece][0][rotation[move.rotation]
      [5 - yOffset][5 - xOffset]] == 1))
	      return MUST_COVER_55;

      /* Player 2's first move must cover (a,a) */
      if(currentPlayer == 2 && ! (8 <= move.x && move.x <= 12 &&
        8 <= move.y && move.y <= 12 && pieces[move.piece][0][rotation[move.rotation]
        [10 - yOffset][10 - xOffset]] == 1))
	        return MUST_COVER_AA;
  }

  /* If we reach this point, the move is valid. */
  return 1;
}

void placeMove(MOVE move, int board[16][16], int currentPlayer, int available[2][21])  {
  int x, y, b;
  int xOffset = move.x - 2, yOffset = move.y - 2;

  /*  Check if automatic pass */
  if(move.x == 0 && move.y == 0 && move.piece == 0 && move.rotation == 0)
    return;

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
  
    exit(0);
  }

  /*  If we reached this point, the game hasn't ended */
  return 0;
}

int checkPossible(int currentPlayer, int turn, int board[16][16], int available[2][21])  {
  MOVE move;

  for (move.y = 1; move.y <= 15; move.y++)  {
    for (move.x = 1; move.x < 15; move.x++) {
      for (move.piece = 0; move.piece < 21; move.piece++) {
        for(move.rotation = 0; move.rotation < 8; move.rotation++)  {
          if(checkMove(currentPlayer, move, board, available, turn) == 1)
            return TRUE;
        }
      }
    }
  }
  /*  If we reach this point, there is no possible play */
  printf("No possible play for Player%d. Skip move.\n", currentPlayer);
  return FALSE;
}