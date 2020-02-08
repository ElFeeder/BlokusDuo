int read_byte = 0;
char enemy_move[4];
char my_move[4];
uint8_t board [14][14];
int available_pieces[2][21];

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

void setup() {

  Serial.begin(115200);       // open serial port
  while (!Serial) {
  }
  startup_board(board);
  startup_available_pieces(available_pieces);
}

void loop() {

  if (Serial.available() > 0)       // check if there is information in the port
  {
    delay(1);                       // for reasons only know to god, without this delay, the code doesnt work, please dont remove
    read_byte = Serial.read();      // read first byte from recieved string

    if  (read_byte == '0')          // query 0, respond with team id
      Serial.print("1NE");

    else if  (read_byte == '2') {   // query 2, respond with move in given position
      read_byte = Serial.read();
      if (read_byte == '5') {
        Serial.print("53e0");
        available_pieces[0][4] = 0;
        update_board(board, "53e0", 1);
      }
      else if (read_byte == 'A') {
        Serial.print("a8e0");
        available_pieces[0][4] = 0;
        update_board(board, "a8e0", 1);
      }
    }
    else if  (read_byte == '3') {  // query 3, respond with move in given position and evaluates enemy move
      read_byte = Serial.read();
      if (read_byte == '5') {
        read_serial_string (enemy_move);
        update_board(board, enemy_move, 2);
        print_serial_string("53e0");
        update_board(board, "53e0", 1);
        available_pieces[0][4] = 0;
      }
      else if (read_byte == 'A') {
        read_serial_string (enemy_move);
        update_board(board, enemy_move, 2);
        print_serial_string("a8e0");
        update_board(board, "a8e0", 1);
        available_pieces[0][4] = 0;
      }
    }
    else if  (read_byte == '4') {  // query 4, respond with move
      read_serial_string (enemy_move);
      update_board(board, enemy_move, 2);
      basic_test_ai2(board, my_move);
      update_board(board, my_move, 1);
      print_serial_string(my_move);
      print_board(board);
    }
  }
}

// COMS FUNCTIONS ------------------------------------------------------------------------------------------------------------------------------

void read_serial_string (char input_string[]) {
  int n;
  for (n = 0; n < 4; n++)
    input_string[n] = Serial.read();
}

void print_serial_string (char output_string[]) {
  int n;
  for (n = 0; n < 4; n++)
    Serial.print(output_string[n]);
}

// STARTUP FUNCTIONS ------------------------------------------------------------------------------------------------------------------------------

void startup_board(uint8_t board [14][14]) {
  int x;
  int y;

  for (y = 0; y < 14; y++)
    for (x = 0; x < 14; x++)
      board[y][x] = 0;
}

void startup_available_pieces(int available_pieces[2][21]) {
  int x;
  int y;

  for (y = 0; y < 2; y++)
    for (x = 0; x < 21; x++)
      available_pieces[y][x] = 1;
}

// GAME FUNCTIONS ------------------------------------------------------------------------------------------------------------------------------

void copy_board (uint8_t board1 [14][14], uint8_t board2 [14][14]) {
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

}

void update_board(uint8_t external_board [14][14], char external_move[4], int player) {
  int x, xr, x_offset;
  int y, yr, y_offset;
  int p;
  int r;
  int b;
  char c;

  c = external_move[0];
  if ('0' <= c && c <= '9') x = c - '0';
  if ('a' <= c && c <= 'e') x = c - 'a' + 10;

  c = external_move[1];
  if ('0' <= c && c <= '9') y = c - '0';
  if ('a' <= c && c <= 'e') y = c - 'a' + 10;

  c = external_move[2];
  p = c - 'a';

  c = external_move[3];
  r = c - '0';

  x = x - 1;
  y = y - 1;

  x_offset = x - 2;
  y_offset = y - 2;

  if (r == 0) {
    for (yr = 0, y = 0; yr < 5; yr++, y++) {
      for (xr = 0, x = 0; xr < 5; xr++, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          external_board[y_offset + y][x_offset + x] = player;
      }
    }
  }

  if (r == 1) {
    for (yr = 0, y = 0; yr < 5; yr++, y++) {
      for (xr = 4, x = 0; xr >= 0; xr--, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          external_board[y_offset + y][x_offset + x] = player;
      }
    }
  }

  if (r == 2) {
    for (xr = 0, y = 0; xr < 5; xr++, y++) {
      for (yr = 4, x = 0; yr >= 0; yr--, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          external_board[y_offset + y][x_offset + x] = player;
      }
    }
  }

  if (r == 3) {
    for (xr = 0, y = 0; xr < 5; xr++, y++) {
      for (yr = 0, x = 0; yr < 5; yr++, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          external_board[y_offset + y][x_offset + x] = player;
      }
    }
  }

  if (r == 4) {
    for (yr = 4, y = 0; yr >= 0; yr--, y++) {
      for (xr = 4, x = 0; xr >= 0; xr--, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          external_board[y_offset + y][x_offset + x] = player;
      }
    }
  }
  if (r == 5) {
    for (yr = 4, y = 0; yr >= 0; yr--, y++) {
      for (xr = 0, x = 0; xr < 5; xr++, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          external_board[y_offset + y][x_offset + x] = player;
      }
    }
  }
  if (r == 6) {
    for (xr = 4, y = 0; xr >= 0; xr--, y++) {
      for (yr = 0, x = 0; yr < 5; yr++, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          external_board[y_offset + y][x_offset + x] = player;
      }
    }
  }

  if (r == 7) {
    for (xr = 4, y = 0; xr >= 0; xr--, y++) {
      for (yr = 4, x = 0; yr >= 0; yr--, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          external_board[y_offset + y][x_offset + x] = player;
      }
    }
  }
}

int check_move (uint8_t external_board [14][14], int external_available_pieces[2][21], char play[4], int player) {

  int x, xx, xr, x_offset;
  int y, yy, yr, y_offset;
  int p;
  int r;
  int b;
  char c;
  int corner_flag;

  c = play[0];
  if ('0' <= c && c <= '9') x = c - '0';
  if ('a' <= c && c <= 'e') x = c - 'a' + 10;

  c = play[1];
  if ('0' <= c && c <= '9') y = c - '0';
  if ('a' <= c && c <= 'e') y = c - 'a' + 10;

  c = play[2];
  p = c - 'a';

  c = play[3];
  r = c - '0';

  x = x - 1;
  y = y - 1;

  x_offset = x - 2;
  y_offset = y - 2;

  corner_flag = 0;

  // Check availability

  if (external_available_pieces[player - 1][p] == 0) {
    return 0;
  }

  if (r == 0) {
    for (yr = 0, y = 0; yr < 5; yr++, y++) {
      for (xr = 0, x = 0; xr < 5; xr++, x++) {
        b = pieces[p][yr][xr];
        if (b == 1) {
          xx = x_offset + x;
          yy = y_offset + y;
          if (external_board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (external_board[yy][xx - 1] == player || external_board[yy][xx + 1] == player || external_board[yy - 1][xx] == player || external_board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if ( (external_board[yy - 1][xx - 1] == player || external_board[yy + 1][xx - 1] == player || external_board[yy - 1][xx + 1] == player || external_board[yy + 1][xx + 1] == player) && xx - 1 >= 0 && xx + 1 < 14 && yy - 1 >= -1 && yy + 1 < 14) // must share the vertex
            corner_flag = 1;
        }
      }
    }
  }

  if (r == 1) {
    for (yr = 0, y = 0; yr < 5; yr++, y++) {
      for (xr = 4, x = 0; xr >= 0; xr--, x++) {
        b = pieces[p][yr][xr];
        if (b == 1) {
          xx = x_offset + x;
          yy = y_offset + y;
          if (external_board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (external_board[yy][xx - 1] == player || external_board[yy][xx + 1] == player || external_board[yy - 1][xx] == player || external_board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if ( (external_board[yy - 1][xx - 1] == player || external_board[yy + 1][xx - 1] == player || external_board[yy - 1][xx + 1] == player || external_board[yy + 1][xx + 1] == player) && xx - 1 >= 0 && xx + 1 < 14 && yy - 1 >= -1 && yy + 1 < 14) // must share the vertex
            corner_flag = 1;
        }
      }
    }
  }

  if (r == 2) {
    for (xr = 0, y = 0; xr < 5; xr++, y++) {
      for (yr = 4, x = 0; yr >= 0; yr--, x++) {
        b = pieces[p][yr][xr];
        if (b == 1) {
          xx = x_offset + x;
          yy = y_offset + y;
          if (external_board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (external_board[yy][xx - 1] == player || external_board[yy][xx + 1] == player || external_board[yy - 1][xx] == player || external_board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if ( (external_board[yy - 1][xx - 1] == player || external_board[yy + 1][xx - 1] == player || external_board[yy - 1][xx + 1] == player || external_board[yy + 1][xx + 1] == player) && xx - 1 >= 0 && xx + 1 < 14 && yy - 1 >= -1 && yy + 1 < 14) // must share the vertex
            corner_flag = 1;
        }
      }
    }
  }

  if (r == 3) {
    for (xr = 0, y = 0; xr < 5; xr++, y++) {
      for (yr = 0, x = 0; yr < 5; yr++, x++) {
        b = pieces[p][yr][xr];
        if (b == 1) {
          xx = x_offset + x;
          yy = y_offset + y;
          if (external_board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (external_board[yy][xx - 1] == player || external_board[yy][xx + 1] == player || external_board[yy - 1][xx] == player || external_board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if ( (external_board[yy - 1][xx - 1] == player || external_board[yy + 1][xx - 1] == player || external_board[yy - 1][xx + 1] == player || external_board[yy + 1][xx + 1] == player) && xx - 1 >= 0 && xx + 1 < 14 && yy - 1 >= -1 && yy + 1 < 14) // must share the vertex
            corner_flag = 1;
        }
      }
    }
  }

  if (r == 4) {
    for (yr = 4, y = 0; yr >= 0; yr--, y++) {
      for (xr = 4, x = 0; xr >= 0; xr--, x++) {
        b = pieces[p][yr][xr];
        if (b == 1) {
          xx = x_offset + x;
          yy = y_offset + y;
          if (external_board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (external_board[yy][xx - 1] == player || external_board[yy][xx + 1] == player || external_board[yy - 1][xx] == player || external_board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if ( (external_board[yy - 1][xx - 1] == player || external_board[yy + 1][xx - 1] == player || external_board[yy - 1][xx + 1] == player || external_board[yy + 1][xx + 1] == player) && xx - 1 >= 0 && xx + 1 < 14 && yy - 1 >= -1 && yy + 1 < 14) // must share the vertex
            corner_flag = 1;
        }
      }
    }
  }
  if (r == 5) {
    for (yr = 4, y = 0; yr >= 0; yr--, y++) {
      for (xr = 0, x = 0; xr < 5; xr++, x++) {
        b = pieces[p][yr][xr];
        if (b == 1) {
          xx = x_offset + x;
          yy = y_offset + y;
          if (external_board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (external_board[yy][xx - 1] == player || external_board[yy][xx + 1] == player || external_board[yy - 1][xx] == player || external_board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if ( (external_board[yy - 1][xx - 1] == player || external_board[yy + 1][xx - 1] == player || external_board[yy - 1][xx + 1] == player || external_board[yy + 1][xx + 1] == player) && xx - 1 >= 0 && xx + 1 < 14 && yy - 1 >= -1 && yy + 1 < 14) // must share the vertex
            corner_flag = 1;
        }
      }
    }
  }
  if (r == 6) {
    for (xr = 4, y = 0; xr >= 0; xr--, y++) {
      for (yr = 0, x = 0; yr < 5; yr++, x++) {
        b = pieces[p][yr][xr];
        if (b == 1) {
          xx = x_offset + x;
          yy = y_offset + y;
          if (external_board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (external_board[yy][xx - 1] == player || external_board[yy][xx + 1] == player || external_board[yy - 1][xx] == player || external_board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if ( (external_board[yy - 1][xx - 1] == player || external_board[yy + 1][xx - 1] == player || external_board[yy - 1][xx + 1] == player || external_board[yy + 1][xx + 1] == player) && xx - 1 >= 0 && xx + 1 < 14 && yy - 1 >= -1 && yy + 1 < 14) // must share the vertex
            corner_flag = 1;
        }
      }
    }
  }

  if (r == 7) {
    for (xr = 4, y = 0; xr >= 0; xr--, y++) {
      for (yr = 4, x = 0; yr >= 0; yr--, x++) {
        b = pieces[p][yr][xr];
        if (b == 1) {
          xx = x_offset + x;
          yy = y_offset + y;
          if (board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (external_board[yy][xx - 1] == player || external_board[yy][xx + 1] == player || external_board[yy - 1][xx] == player || external_board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if ( (external_board[yy - 1][xx - 1] == player || external_board[yy + 1][xx - 1] == player || external_board[yy - 1][xx + 1] == player || external_board[yy + 1][xx + 1] == player) && xx - 1 >= 0 && xx + 1 < 14 && yy - 1 >= -1 && yy + 1 < 14) // must share the vertex
            corner_flag = 1;
        }
      }
    }
  }
  if (corner_flag == 1)
    return 1;
  return 0;
}

// TEST FUNCTIONS ------------------------------------------------------------------------------------------------------------------------------

void basic_test_ai(uint8_t board [14][14], char play[4]) {

  int x;
  int y;
  int p;
  int r;
  for (y = 0; y < 14; y++)
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

          if (check_move (board, available_pieces, play, 1))
          {
            available_pieces[0][p] = 0;
            return;
          }
          else
          {
            play [0] = '0';
            play [1] = '0';
            play [2] = '0';
            play [3] = '0';
          }
        }
}

void print_board(uint8_t board [14][14]) {
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
}

// DEV ZONE ---------------------------------------------------------------------------------------

void basic_test_ai2(uint8_t external_board [14][14], char final_play[4]) {

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
              update_board(internal_board, play, 1);
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
              update_board(internal_board, play, 2);
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
}
