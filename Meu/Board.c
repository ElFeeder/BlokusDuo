#include "BlokusDuo.h"

void initBoard()  {
  int x, y;

  printf("---------------------- Board ----------------------\n  ");
    for(x = 0; x < 16; x++)
      printf(" %c", ((x<10) ? x+'0' : x+'a'-10));
    printf("\n");
    for(y = 0; y < 16; y++){
      printf(" %c", ((y<10) ? y+'0' : y+'a'-10));
      for(x = 0; x < 16; x++) {
        if(x == 0 || x == 15 || y == 0 || y == 15)
          printf(" +");
        else
          printf("  ");
      }
      printf("\n");  
    }
    printf("---------------------------------------------------\n");
}