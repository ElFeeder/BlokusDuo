uint8_t read_byte, readSecondByte;
uint8_t board[14][14];
uint8_t available_pieces[2][21];

char enemy_move[5];
char my_move[5];

typedef struct move {
  int8_t x;
  int8_t y;
  int8_t piece;
  int8_t rotation;
} MOVE;

MOVE move;

uint8_t pieces[21][5][5] = {
  // a
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // b
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // c
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // d
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 1, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // e
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 }
  },
  // f
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // g
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // h
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 0 },
    { 0, 0, 1, 1, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // i
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 0, 1, 1, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // j
  { { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 }
  },
  // k
  { { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // l
  { { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // m
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // n
  { { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // o
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 }
  },
  // p
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // q
  { { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // r
  { { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 0, 1, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // s
  { { 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // t
  { { 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0 }
  },
  // u
  { { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0 }
  }
};

// COMS FUNCTIONS -----------------------------------------------------------------
void read_serial_string(char input_string[]);

void moveToString(MOVE move, char myMove[5]);


// STARTUP FUNCTIONS --------------------------------------------------------------
void startup_board(uint8_t board[14][14], uint8_t available_pieces[2][21]);


// GAME FUNCTIONS -----------------------------------------------------------------
MOVE checkCode(char external_move[4]);

void updateBoard(MOVE move, uint8_t board[14][14], uint8_t player);
void changeBoard(uint8_t piece, int8_t yr, int8_t xr, uint8_t player, uint8_t y, uint8_t x, int8_t xOffset, int8_t yOffset, uint8_t board[14][14]);

uint8_t checkMove(uint8_t board[14][14], uint8_t available_pieces[2][21], MOVE move);
uint8_t iterCheckMove(int8_t xOffset, uint8_t x, int8_t yOffset, uint8_t y, uint8_t board[14][14]);


// TEST FUNCTIONS -----------------------------------------------------------------
MOVE basicAI(uint8_t board[14][14], uint8_t available_pieces[2][21]);



void setup() {

  Serial.begin(115200);       // open serial port
  while (!Serial) {
  }

  startup_board(board, available_pieces);
  available_pieces[0][18] = 0;            // We're always going to start with this play, might as well already remove it
}

void loop() {
  if (Serial.available() > 0)       // check if there is information in the port
  {
    delay(1);                       // for reasons only known to god, without this delay, the code doesnt work, please dont remove
    read_byte = Serial.read();      // read first byte from recieved string

    switch (read_byte) {            // We're always player 1
      case '0':
        Serial.print("1NR");
        break;

      case '2':
        readSecondByte = Serial.read();
        switch (readSecondByte)  {
          case '5':
            Serial.print((char*)"66s0");         // Always the first play
            move = checkCode((char*)"66s0");
            updateBoard(move, board, 1);
            break;

          case 'A':
            Serial.print((char*)"99s0");
            move = checkCode((char*)"99s0");
            updateBoard(move, board, 1);
            break;

          default:
            break;
        }
        break;

      case '3':
        readSecondByte = Serial.read();
        switch (readSecondByte)  {
          case '5':
            read_serial_string(enemy_move);
            move = checkCode(enemy_move);
            updateBoard(move, board, 2);
            available_pieces[1][move.piece] = 0;

            Serial.print((char*)"66s0");           // Always the first play
            move = checkCode((char*)"66s0");
            updateBoard(move, board, 1);
            break;

          case 'A':
            read_serial_string(enemy_move);
            move = checkCode(enemy_move);
            updateBoard(move, board, 2);
            available_pieces[1][move.piece] = 0;

            Serial.print((char*)"99s0");           // Always the first play
            move = checkCode((char*)"99s0");
            updateBoard(move, board, 1);
            break;

          default:
            break;
        }
        break;

      case '4':                             // Regular play
        read_serial_string(enemy_move);
        move = checkCode(enemy_move);
        updateBoard(move, board, 2);
        available_pieces[1][move.piece] = 0;

        move = basicAI(board, available_pieces);
        moveToString(move, my_move);
        Serial.print(my_move);
        updateBoard(move, board, 1);
        available_pieces[0][move.piece] = 0;
        break;

      default:
        break;
    }
  }
}

// COMS FUNCTIONS ------------------------------------------------------------------------------------------------------------------------------

void read_serial_string(char input_string[5]) {
  uint8_t n;

  for (n = 0; n < 4; n++)
    input_string[n] = Serial.read();
}


void moveToString(MOVE move, char myMove[5])  {
  move.x++;         // Compensate for border
  move.y++;

  if (move.x < 10)
    myMove[0] = move.x + '0';
  else
    myMove[0] = move.x + 'a' - 10;

  if (move.y < 10 )
    myMove[1] = move.y + '0';
  else
    myMove[1] = move.y + 'a' - 10;

  myMove[2] = move.piece + 'a';
  myMove[3] = move.rotation + '0';
}


// STARTUP FUNCTIONS ------------------------------------------------------------------------------------------------------------------------------

void startup_board(uint8_t board[14][14], uint8_t available_pieces[2][21]) {
  uint8_t x, y;

  for (y = 0; y < 14; y++)            // Init board
    for (x = 0; x < 14; x++)
      board[y][x] = 0;

  for (y = 0; y < 2; y++)             // Init available
    for (x = 0; x < 21; x++)
      available_pieces[y][x] = 1;
}

// GAME FUNCTIONS ------------------------------------------------------------------------------------------------------------------------------

/*void copy_board(uint8_t board1 [14][14], uint8_t board2 [14][14]) {
  int x, y;
  for (y = 0; y < 14; y++)
    for (x = 0; x < 14; x++)
      board1 [y][x] = board2 [y][x];

  }

  void copy_available_pieces(int available_pieces1[2][21], int available_pieces2[2][21]) {
  int x, y;
  for (y = 0; y < 14; y++)
    for (x = 0; x < 14; x++)
      available_pieces1[y][x] = available_pieces2[y][x];

  }*/

MOVE checkCode(char external_move[5]) {
  MOVE move;
  char c;

  if (strcmp("0000", external_move) == 0) {   // If it's a pass
    move.x = 0;
    move.y = 0;
    move.piece = 0;
    move.rotation = 0;

    return move;
  }

  c = external_move[0];
  if ('0' <= c && c <= '9')
    move.x = c - '0';
  if ('a' <= c && c <= 'e')
    move.x = c - 'a' + 10;

  c = external_move[1];
  if ('0' <= c && c <= '9')
    move.y = c - '0';
  if ('a' <= c && c <= 'e')
    move.y = c - 'a' + 10;

  c = external_move[2];
  move.piece = c - 'a';

  c = external_move[3];
  move.rotation = c - '0';

  return move;
}

void updateBoard(MOVE move, uint8_t board[14][14], uint8_t player)  {
  uint8_t x, y;

  int8_t xOffset, yOffset, xr, yr;


  xOffset = move.x - 3;             // Compensate for borders
  yOffset = move.y - 3;

  // Check if pass
  if (move.x == 0 && move.y == 0 && move.piece == 0 && move.rotation == 0)
    return;


  switch (move.rotation) {          // Ask Abreu about this madness
    case 0:
      for (y = 0, yr = 0; yr < 5; y++, yr++)
        for (x = 0, xr = 0; xr < 5; x++, xr++)
          changeBoard(move.piece, yr, xr, player, y, x, xOffset, yOffset, board);
      break;

    case 1:
      for (y = 0, yr = 0; yr < 5; y++, yr++)
        for (x = 0, xr = 4; xr >= 0; x++, xr--)
          changeBoard(move.piece, yr, xr, player, y, x, xOffset, yOffset, board);
      break;

    case 2:
      for (x = 0, xr = 0; xr < 5; x++, y++)
        for (yr = 4, x = 0; xr >= 0; yr--, x++)
          changeBoard(move.piece, yr, xr, player, y, x, xOffset, yOffset, board);
      break;

    case 3:
      for (y = 0, xr = 0; xr < 5; y++, xr++)
        for (x = 0, yr = 0; yr < 5; x++, yr++)
          changeBoard(move.piece, yr, xr, player, y, x, xOffset, yOffset, board);
      break;

    case 4:
      for (y = 0, yr = 4; yr >= 0; y++, yr--)
        for (x = 0, xr = 4; xr >= 0; x++, xr--)
          changeBoard(move.piece, yr, xr, player, y, x, xOffset, yOffset, board);
      break;

    case 5:
      for (yr = 4, y = 0; yr >= 0; yr--, y++)
        for (xr = 0, x = 0; xr < 5; xr++, x++)
          changeBoard(move.piece, yr, xr, player, y, x, xOffset, yOffset, board);
      break;

    case 6:
      for (xr = 4, y = 0; xr >= 0; xr--, y++)
        for (yr = 0, x = 0; yr < 5; yr++, x++)
          changeBoard(move.piece, yr, xr, player, y, x, xOffset, yOffset, board);
      break;

    case 7:
      for (xr = 4, y = 0; xr >= 0; xr--, y++)
        for (yr = 4, x = 0; yr >= 0; yr--, x++)
          changeBoard(move.piece, yr, xr, player, y, x, xOffset, yOffset, board);
      break;

    default:
      break;
  }
}


void changeBoard(uint8_t piece, int8_t yr, int8_t xr, uint8_t player, uint8_t y, uint8_t x, int8_t xOffset, int8_t yOffset, uint8_t board[14][14]) {
  if (pieces[piece][yr][xr] == 1)
    board[yOffset + y][xOffset + x] = player;
}


uint8_t checkMove(uint8_t board[14][14], uint8_t available_pieces[2][21], MOVE move) {
  int8_t xr, yr;
  int8_t xOffset = move.x - 2, yOffset = move.y - 2;

  uint8_t valid = 0;
  uint8_t x, y;


  if (available_pieces[0][move.piece] == 0)
    return 0;

  switch (move.rotation) {
    case 0:
      for (yr = 0, y = 0; yr < 5; yr++, y++) {
        for (xr = 0, x = 0; xr < 5; xr++, x++) {
          /*Serial.println(move.piece);*/
          if (pieces[move.piece][yr][xr] == 1) {
            valid = iterCheckMove(xOffset, x, yOffset, y, board);
            if (valid == 0)
              return 0;
          }
        }
      }
      break;

    case 1:
      for (yr = 0, y = 0; yr < 5; yr++, y++) {
        for (xr = 4, x = 0; xr >= 0; xr--, x++) {
          if (pieces[move.piece][yr][xr] == 1) {
            valid = iterCheckMove(xOffset, x, yOffset, y, board);
            if (valid == 0)
              return 0;
          }
        }
      }
      break;

    case 2:
      for (xr = 0, y = 0; xr < 5; xr++, y++) {
        for (yr = 4, x = 0; yr >= 0; yr--, x++) {
          if (pieces[move.piece][yr][xr] == 1) {
            valid = iterCheckMove(xOffset, x, yOffset, y, board);
            if (valid == 0)
              return 0;
          }
        }
      }
      break;

    case 3:
      for (xr = 0, y = 0; xr < 5; xr++, y++) {
        for (yr = 0, x = 0; yr < 5; yr++, x++) {
          if (pieces[move.piece][yr][xr] == 1) {
            valid = iterCheckMove(xOffset, x, yOffset, y, board);
            if (valid == 0)
              return 0;
          }
        }
      }
      break;

    case 4:
      for (yr = 4, y = 0; yr >= 0; yr--, y++) {
        for (xr = 4, x = 0; xr >= 0; xr--, x++) {
          if (pieces[move.piece][yr][xr] == 1) {
            valid = iterCheckMove(xOffset, x, yOffset, y, board);
            if (valid == 0)
              return 0;
          }
        }
      }
      break;

    case 5:
      for (yr = 4, y = 0; yr >= 0; yr--, y++) {
        for (xr = 0, x = 0; xr < 5; xr++, x++) {
          if (pieces[move.piece][yr][xr] == 1) {
            valid = iterCheckMove(xOffset, x, yOffset, y, board);
            if (valid == 0)
              return 0;
          }
        }
      }
      break;

    case 6:
      for (xr = 4, y = 0; xr >= 0; xr--, y++) {
        for (yr = 0, x = 0; yr < 5; yr++, x++) {
          if (pieces[move.piece][yr][xr] == 1) {
            valid = iterCheckMove(xOffset, x, yOffset, y, board);
            if (valid == 0)
              return 0;
          }
        }
      }
      break;

    case 7:
      for (xr = 4, y = 0; xr >= 0; xr--, y++) {
        for (yr = 4, x = 0; yr >= 0; yr--, x++) {
          if (pieces[move.piece][yr][xr] == 1) {
            valid = iterCheckMove(xOffset, x, yOffset, y, board);
            if (valid == 0)
              return 0;
          }
        }
      }
      break;

    default:
      break;
  }
  
  return (valid == 0 ? 0 : 1);      // If we reach this point, the move is valid
}

uint8_t iterCheckMove(int8_t xOffset, uint8_t x, int8_t yOffset, uint8_t y, uint8_t board[14][14]) {
  int8_t xx, yy;

  xx = xOffset + x;
  yy = yOffset + y;
  if (board[yOffset + y][xOffset + x] != 0 || yOffset + y < 0 || 15 < yOffset + y || xOffset + x < 0 || 15 < xOffset + x)     // Already occupied grid
    return 0;
  if (board[yy][xx - 1] == 1 || board[yy][xx + 1] == 1 || board[yy - 1][xx] == 1 || board[yy + 1][xx] == 1 )                  // New piece can't share the edge
    return 0;
  if (board[yy - 1][xx - 1] == 1 || board[yy + 1][xx - 1] == 1 || board[yy - 1][xx + 1] == 1 || board[yy + 1][xx + 1] == 1)   // Must share vertex
    return 1;

  return 0;
}


// TEST FUNCTIONS ------------------------------------------------------------------------------------------------------------------------------

MOVE basicAI(uint8_t board[14][14], uint8_t available_pieces[2][21]) {
  MOVE move;

  for (move.piece = 20; move.piece >= 0; move.piece--)
    for (move.rotation = 0; move.rotation < 8; move.rotation++)
      for (move.x = 13; move.x >= 0; move.x--)
        for (move.y = 13; move.y >= 0; move.y--)
          if (checkMove(board, available_pieces, move) == 1)  {  // Check if it's a valid move
            Serial.println(move.x);
            Serial.println(move.y);
            Serial.println(move.piece);
            Serial.println(move.rotation);
          
            return move;
          }


  move.x = 0;             // Fill struct move with 0000 (automatic pass turn)
  move.y = 0;
  move.piece = 0;
  move.rotation = 0;

  return move;
}

/*void print_board(uint8_t board [14][14]) {
  int x;
  int y;

  Serial.println(" ");
  for (y = 0; y < 14; y++) {
    for (x = 0; x < 14; x++) {
      if (board[y][x] == 0)
        Serial.print(" 0 ");
      if (board[y][x] == 1)
        Serial.print(" 1 ");
      if (board[y][x] == 2)
        Serial.print(" 2 ");
    }
    Serial.println(" ");
  }
  }

  void print_pieces(int available_pieces [2][21]) {
  int x;
  int y;

  Serial.println(" ");
  for (y = 0; y < 2; y++) {
    for (x = 0; x < 21; x++) {
      if (available_pieces[y][x] == 0)
        Serial.print(" 0 ");
      if (available_pieces[y][x] == 1)
        Serial.print(" 1 ");
    }
    Serial.println(" ");
  }
  }*/

// DEV ZONE ---------------------------------------------------------------------------------------

/*void basic_test_ai2(uint8_t external_board [14][14], char final_play[4]) {

  int x;
  int y;
  int p;
  int r;
  int max_val = -100;
  int eval;
  char play[4];

  final_play [0] = '0';
  final_play [1] = '0';
  final_play [2] = '0';
  final_play [3] = '0';

  for (y = 14; y >= 0 ; y--)
    for (x = 14; x >= 0 ; x--)
      for (p = 21; p >= 0; p--)
        for (r = 0; r < 7; r++) {

          if (x < 10 )
            play [0] = x + '0';
          else
            play [0] = x + 'a' - 10;

          if (y < 10 )
            play [1] = y + '0';
          else
            play [1] = y + 'a' - 10;

          play [2] = p + 'a';
          play [3] = r + '0';

          if (check_move (external_board, available_pieces, play, 1))
          {
            eval = evaluate_play (external_board, play);
            if (max_val < eval) {
              final_play [0] = play [0];
              final_play [1] = play [1];
              final_play [2] = play [2];
              final_play [3] = play [3];
              max_val = eval;
            }
          }

        }
  }

  int minimax_ai(uint8_t external_board [14][14], int external_available_pieces[2][21], char final_play[4], int depth, int player) {

  int min_val;
  int max_val;
  int eval;
  int x;
  int y;
  int p;
  int r;
  char play[4];
  char best_play[4];
  uint8_t internal_board [14][14];
  int internal_available_pieces[2][21];

  copy_board(internal_board, external_board);
  copy_available_pieces(internal_available_pieces, external_available_pieces);

  if (depth == 0)
  {
    return 10;
  }

  else if (player == 1) {
    max_val = -100000;
    for (y = 0; y < 14; y++) {
      for (x = 0; x < 14; x++)
        for (p = 0; p < 21; p++)
          for (r = 0; r < 7; r++) {
            if (x < 10 )
              play [0] = x + '0';
            else
              play [0] = x + 'a' - 10;

            if (y < 10 )
              play [1] = y + '0';
            else
              play [1] = y + 'a' - 10;

            play [2] = p + 'a';
            play [3] = r + '0';
            if (check_move (internal_board, internal_available_pieces, play, 1))
            {
              checkCode(internal_board, play, 1);
              internal_available_pieces[0][p] = 0;
              eval = minimax_ai(internal_board, internal_available_pieces, play, depth - 1, 2);
              if (eval > max_val)
              {
                eval = max_val;
                best_play [0] = play[0];
                best_play [1] = play[1];
                best_play [2] = play[2];
                best_play [3] = play[3];
              }
            }
          }
    }
    final_play [0] = best_play[0];
    final_play [1] = best_play[1];
    final_play [2] = best_play[2];
    final_play [3] = best_play[3];
    return max_val;
  }
  else if (player == 2) {
    min_val = 100000;
    for (y = 0; y < 14; y++) {
      for (x = 0; x < 14; x++)
        for (p = 0; p < 21; p++)
          for (r = 0; r < 7; r++) {

            if (x < 10 )
              play [0] = x + '0';
            else
              play [0] = x + 'a' - 10;

            if (y < 10 )
              play [1] = y + '0';
            else
              play [1] = y + 'a' - 10;

            play [2] = p + 'a';
            play [3] = r + '0';
            if (check_move (internal_board, internal_available_pieces, play, 2))
            {
              checkCode(internal_board, play, 2);
              internal_available_pieces[1][p] = 0;
              eval = minimax_ai(internal_board, internal_available_pieces, play, depth - 1, 1);
              if (eval < min_val)
                eval = min_val;
            }
          }
    }
    return min_val;
  }
  }

  int evaluate_play (uint8_t external_board [14][14], char play[4]) {
  int x, y;
  int points_p1 = 0, points_p2 = 0;

  for (y = 0; y < 14; y++) {
    for (x = 0; x < 14; x++) {
      if (external_board[y][x] == 1)
        points_p1++;
      if (external_board[y][x] == 2)
        points_p2++;
    }
  }
  return points_p1 - points_p2;
  }*/
