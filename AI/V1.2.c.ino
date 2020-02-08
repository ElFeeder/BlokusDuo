int read_byte = 0;
char enemy_move[4];
char my_move[4];
uint8_t board [14][14];

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
uint8_t available_pieces[2][21];



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
        update_board(board, "53e0", 1);
      }
      else if (read_byte == 'A') {
        Serial.print("a8e0");
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
      }
      else if (read_byte == 'A') {
        read_serial_string (enemy_move);
        update_board(board, enemy_move, 2);
        print_serial_string("a8e0");
        update_board(board, "a8e0", 1);
      }
    }
    else if  (read_byte == '4') {  // query 4, respond with move
      read_serial_string (enemy_move);
      update_board(board, enemy_move, 2);
      print_serial_string("0000");
    }
    else if  (read_byte == '7') {  // test query
      read_serial_string (my_move);
      if (check_move (board, my_move , 2))
        update_board(board, my_move, 2);
      print_board(board);
    }
    else if  (read_byte == '8') {  // test query
      read_serial_string (enemy_move);
      update_board(board, enemy_move, 1);
      print_board(board);
    }
    else if  (read_byte == '9') {  // test query
      read_serial_string (my_move);
      update_board(board, my_move, 2);
      print_board(board);
    }
  }
}

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

void update_board(uint8_t board [14][14], char enemy_move[4], int player) {
  int x, xr, x_offset;
  int y, yr, y_offset;
  int p;
  int r;
  int b;
  char c;

  c = enemy_move[0];
  if ('0' <= c && c <= '9') x = c - '0';
  if ('a' <= c && c <= 'e') x = c - 'a' + 10;

  c = enemy_move[1];
  if ('0' <= c && c <= '9') y = c - '0';
  if ('a' <= c && c <= 'e') y = c - 'a' + 10;

  c = enemy_move[2];
  p = c - 'a';

  c = enemy_move[3];
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
          board[y_offset + y][x_offset + x] = player;
      }
    }
  }

  if (r == 1) {
    for (yr = 0, y = 0; yr < 5; yr++, y++) {
      for (xr = 4, x = 0; xr >= 0; xr--, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          board[y_offset + y][x_offset + x] = player;
      }
    }
  }

  if (r == 2) {
    for (xr = 0, y = 0; xr < 5; xr++, y++) {
      for (yr = 4, x = 0; yr >= 0; yr--, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          board[y_offset + y][x_offset + x] = player;
      }
    }
  }

  if (r == 3) {
    for (xr = 0, y = 0; xr < 5; xr++, y++) {
      for (yr = 0, x = 0; yr < 5; yr++, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          board[y_offset + y][x_offset + x] = player;
      }
    }
  }

  if (r == 4) {
    for (yr = 4, y = 0; yr >= 0; yr--, y++) {
      for (xr = 4, x = 0; xr >= 0; xr--, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          board[y_offset + y][x_offset + x] = player;
      }
    }
  }
  if (r == 5) {
    for (yr = 4, y = 0; yr >= 0; yr--, y++) {
      for (xr = 0, x = 0; xr < 5; xr++, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          board[y_offset + y][x_offset + x] = player;
      }
    }
  }
  if (r == 6) {
    for (xr = 4, y = 0; xr >= 0; xr--, y++) {
      for (yr = 0, x = 0; yr < 5; yr++, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          board[y_offset + y][x_offset + x] = player;
      }
    }
  }

  if (r == 7) {
    for (xr = 4, y = 0; xr >= 0; xr--, y++) {
      for (yr = 4, x = 0; yr >= 0; yr--, x++) {
        b = pieces[p][yr][xr];
        if (b == 1)
          board[y_offset + y][x_offset + x] = player;
      }
    }
  }
}
void startup_board(uint8_t board [14][14]) {
  int x;
  int y;

  for (y = 0; y < 14; y++)
    for (x = 0; x < 14; x++)
      board[y][x] = 0;
}

void startup_available_pieces(uint8_t available_pieces[2][21]) {
  int x;
  int y;

  for (y = 0; y < 2; y++)
    for (x = 0; x < 21; x++)
      available_pieces[y][x] = 1;
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

int check_move (uint8_t board [14][14], char play[4], int player) {

  int x, xx, xr, x_offset;
  int y, yy, yr, y_offset;
  int p;
  int r;
  int b;
  char c;

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

  // Check availability
  if (pieces[player][c] == 0) {
    return 0;
  }

  if (r == 0) {
    for (yr = 0, y = 0; yr < 5; yr++, y++) {
      for (xr = 0, x = 0; xr < 5; xr++, x++) {
        b = pieces[p][yr][xr];
        if (b == 1) {
          xx = x_offset + x;
          yy = y_offset + y;
          if (board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (board[yy][xx - 1] == player || board[yy][xx + 1] == player || board[yy - 1][xx] == player || board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if (board[yy - 1][xx - 1] == player || board[yy + 1][xx - 1] == player || board[yy - 1][xx + 1] == player || board[yy + 1][xx + 1] == player) // must share the vertex
            return 1;
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
          if (board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (board[yy][xx - 1] == player || board[yy][xx + 1] == player || board[yy - 1][xx] == player || board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if (board[yy - 1][xx - 1] == player || board[yy + 1][xx - 1] == player || board[yy - 1][xx + 1] == player || board[yy + 1][xx + 1] == player) // must share the vertex
            return 1;
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
          if (board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (board[yy][xx - 1] == player || board[yy][xx + 1] == player || board[yy - 1][xx] == player || board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if (board[yy - 1][xx - 1] == player || board[yy + 1][xx - 1] == player || board[yy - 1][xx + 1] == player || board[yy + 1][xx + 1] == player) // must share the vertex
            return 1;
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
          if (board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (board[yy][xx - 1] == player || board[yy][xx + 1] == player || board[yy - 1][xx] == player || board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if (board[yy - 1][xx - 1] == player || board[yy + 1][xx - 1] == player || board[yy - 1][xx + 1] == player || board[yy + 1][xx + 1] == player) // must share the vertex
            return 1;
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
          if (board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (board[yy][xx - 1] == player || board[yy][xx + 1] == player || board[yy - 1][xx] == player || board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if (board[yy - 1][xx - 1] == player || board[yy + 1][xx - 1] == player || board[yy - 1][xx + 1] == player || board[yy + 1][xx + 1] == player) // must share the vertex
            return 1;
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
          if (board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (board[yy][xx - 1] == player || board[yy][xx + 1] == player || board[yy - 1][xx] == player || board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if (board[yy - 1][xx - 1] == player || board[yy + 1][xx - 1] == player || board[yy - 1][xx + 1] == player || board[yy + 1][xx + 1] == player) // must share the vertex
            return 1;
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
          if (board[y_offset + y][x_offset + x] != 0 || y_offset + y < 0 || 15 < y_offset + y || x_offset + x < 0 || 15 < x_offset + x ) // No piece on already occupied grid
            return 0;
          else if (board[yy][xx - 1] == player || board[yy][xx + 1] == player || board[yy - 1][xx] == player || board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if (board[yy - 1][xx - 1] == player || board[yy + 1][xx - 1] == player || board[yy - 1][xx + 1] == player || board[yy + 1][xx + 1] == player) // must share the vertex
            return 1;
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
          else if (board[yy][xx - 1] == player || board[yy][xx + 1] == player || board[yy - 1][xx] == player || board[yy + 1][xx] == player ) // New piece can't share the edge
            return 0;
          else if (board[yy - 1][xx - 1] == player || board[yy + 1][xx - 1] == player || board[yy - 1][xx + 1] == player || board[yy + 1][xx + 1] == player) // must share the vertex
            return 1;
        }
      }
    }
  }
  return 0;
}
