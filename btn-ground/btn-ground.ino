const int BTN_PIN = 10,
          LED_PIN = 13;

void setup()
{
  pinMode(BTN_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  delay(250);
  digitalWrite(LED_PIN, HIGH);
  delay(250);
  digitalWrite(LED_PIN, LOW);
  /* digitalWrite(LED_PIN, digitalRead(BTN_PIN)); */
}
