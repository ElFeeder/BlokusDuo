#include "BlokusDuo.h"
#include "PiecesRotation.h"


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
      b = pieces[move.piece][0][rotation[move.rotation][y][x]];
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
  int winner;

  if(remainingPieces(currentPlayer, available) == 0)  {
    bonus[currentPlayer - 1] = 15;
    if(move.piece == 0) /* If we finish with the individual piece */
      bonus[currentPlayer - 1] = 20;

    winner = endGame(board, currentPlayer, available, bonus);
    return winner;
  }

  /*  If we reached this point, the game hasn't ended */
  return -1;
}

MOVE checkPossible(int currentPlayer, int turn, int board[16][16], int available[2][21], int *final, int bonus[2])  {
  MOVE move;
  int r;
  
  /*  We're gonna check for plays across the board. With
  the AI in mind, if the latter is player 1, we're starting
  from the lower right corner and moving our way up. That because
  we want to fill the opponent side as quickly as possible. (The
  same goes for player 2, starting from the upper left corner). */
  
  for (move.piece = 20; move.piece >= 0; move.piece--)  {
    for(move.rotation = 0; move.rotation < 8; move.rotation++)  {
      for (move.x = (currentPlayer == 1 ? 14 : 1); 
          (currentPlayer == 1 ? (move.x > 0) : (move.x < 15));
          (currentPlayer == 1 ? (move.x--) : (move.x++))) {
        for (move.y = (currentPlayer == 1 ? 14 : 1); 
            (currentPlayer == 1 ? (move.y > 0) : (move.y < 15));
            (currentPlayer == 1 ? (move.y--) : (move.y++))) {
          r = rand() % 300;
          if(checkMove(currentPlayer, move, board, available, turn) == 1 && r % 3 == 0) {
              *final = 0;
              return move;
          }
        } 
      }
    }
  }

  /*  If final = 1, previous player didn't have a play aswell. The game must end. */
  if(*final == 1) {
    move.x = endGame(board, currentPlayer, available, bonus);
    move.x = move.x - 3;
    return move;
  }
  else
    *final = 1;
  
  /*  Fill struct move with 0000 (automatic pass turn)  */
  move.x = 0;
  move.y = 0;
  move.piece = 0;
  move.rotation = 0;

  return move;
}