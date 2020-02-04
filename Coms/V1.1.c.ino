int read_byte = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() == 0)
  {
     read_byte = Serial.read();
     if (read_byte == '0')
     {
       Serial.println("1NE");
     }
  }
}
