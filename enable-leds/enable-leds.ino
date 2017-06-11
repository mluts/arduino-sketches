const int PINS[] = {8,9,10,11,12};

void setup() {
  for(int i = 0; i < sizeof(PINS)/ sizeof(int); i++)
  {
    int pin = PINS[i];
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}

void loop() {
}
