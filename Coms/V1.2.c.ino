int read_byte = 0;
char enemy_move[4];

void setup() {

  Serial.begin(115200);       // open serial port
  while (!Serial) {
  }

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
      if (read_byte == '5')
        Serial.print("53e0");
      else if (read_byte == 'A')
        Serial.print("a8e0");
    }
    else if  (read_byte == '3') {  // query 3, respond with move in given position and evaluates enemy move
      read_byte = Serial.read();
      if (read_byte == '5') {
        read_serial_string (enemy_move);
        print_serial_string("53e0");
      }
      else if (read_byte == 'A') {
        read_serial_string (enemy_move);
        print_serial_string("a8e0");
      }
    }
    else if  (read_byte == '4') {  // query 4, respond with move
      read_serial_string (enemy_move);
      print_serial_string("0000");
    }
  }
}

void read_serial_string (char input_string[]) {
  int n;
  for (int n = 0; n < 4; n++)
    input_string[n] = Serial.read();
}

void print_serial_string (char output_string[]) {
  int n;
  for (int n = 0; n < 4; n++)
    Serial.print(output_string[n]);
}
