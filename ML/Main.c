#include "BlokusDuo.h"

int main(void)  {
  int currentPlayer, board[16][16], available[2][21];
  int bonus[2] = {0, 0}, iter = 0;
  int winner, final, turn;
  MOVE move;
  FILE *results;

  /* rand is only for the ML study  */
  srand(time(NULL));

  results = fopen("ResultsP1S1", "w");
  if(results == NULL) {
    printf("Error opening file.\n");
    exit(0);
  }

  fprintf(results, "11,12,13,14,15,16,17,18,19,1a,1b,1c,1d,1e,21,22,23,24,25,26,27,28,29,2a,2b,2c,2d,2e,31,32,33,34,35,36,37,38,39,3a,3b,3c,3d,3e,41,42,43,44,45,46,47,48,49,4a,4b,4c,4d,4e,51,52,53,54,55,56,57,58,59,5a,5b,5c,5d,5e,61,62,63,64,65,66,67,68,69,6a,6b,6c,6d,6e,71,72,73,74,75,76,77,78,79,7a,7b,7c,7d,");
          
  fprintf(results, "7e,81,82,83,84,85,86,87,88,89,8a,8b,8c,8d,8e,91,92,93,94,95,96,97,98,99,9a,9b,9c,9d,9e,a1,a2,a3,a4,a5,a6,a7,a8,a9,aa,ab,ac,ad,ae,b1,b2,b3,b4,b5,b6,b7,b8,b9,ba,bb,bc,bd,be,c1,c2,c3,c4,c5,c6,c7,c8,c9,ca,cb,cc,cd,ce,d1,d2,d3,d4,d5,d6,d7,d8,d9,da,db,dc,dd,de,e1,e2,e3,e4,e5,e6,e7,e8,e9,ea,eb,ec,ed,ee\n");

  fclose(results);
  
  do  {
    currentPlayer = 1;  /*  Right now, we want to start as player1  */
    final = 0;
    turn = 0;
    bonus[0] = 0;
    bonus[1] = 0;
    initBoard(board, available);
  
    while(1)  {
      move = checkPossible(currentPlayer, turn, board, available, &final, bonus);
      if(move.x < 0)  {
        if(move.x == -2)  /*  We're checking for wins on player1 now  */
          scanAndWrite(board, results);
        break;
      }
      
      placeMove(move, board, currentPlayer, available);
      
      winner = checkIfEnd(currentPlayer, bonus, move, available, board);
      
      if(winner != -1) {
        if(winner == 1) /*  We're checking for wins on player1 now  */
          scanAndWrite(board, results);
        break;
      }

      currentPlayer = switchPlayer(currentPlayer);

      turn++;
    }
    
    iter++;
  }while(iter < 10);

  return 0;
}

int switchPlayer(int currentPlayer) {
  return (currentPlayer == 1 ? 2 : 1);
}

int endGame(int board[16][16], int currentPlayer, int available[2][21], int bonus[2])  {
  int pieces1, pieces2, winner;
  
  pieces1 = remainingPieces(1, available);
  pieces2 = remainingPieces(2, available);

  printf(" Unplaced Tiles: %d / %d, Score: %d / %d.\n", pieces1, pieces2, bonus[0] - pieces1, bonus[1] - pieces2);
    if(pieces1 < pieces2)  {
      winner = 1;
      printf("Player 1 won the game!\n");
    }
    else if(pieces1 > pieces2)  {
      winner = 2;
      printf("Player 2 won the game!\n");
    }
    else if(pieces1 == pieces2) {
      winner = 0;
      printf("Draw game!\n");
    }
  
  return winner;
}

void scanAndWrite(int board[16][16], FILE *results) {
  int x, y;
  
  results = fopen("ResultsP1S1", "a");
  if(results == NULL) {
    printf("Error opening file.\n");
    exit(0);
  }

  /*  Scan board and write 1 for each spot occupied by player 1 */
  for(y = 1; y < 15; y++) {
    for(x = 1; x < 15; x++) {
      if(x == 14 && y == 14)  { /*  If we're in the last spot */
        if(board[y][x] == 1)
          fprintf(results, "1");
        else
          fprintf(results, "0");
      }
      else  {
        if(board[y][x] == 1)
          fprintf(results, "1,");
        else
          fprintf(results, "0,");
      }
    }
  }
  fprintf(results, "\n");
  fclose(results);
}