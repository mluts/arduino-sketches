const int PINS[] = {8,9,10,11,12};

void setup() {
  for(int i = 0; i < sizeof(PINS)/ sizeof(int); i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
}

void loop() {
}
