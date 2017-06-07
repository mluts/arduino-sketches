const int LED_PIN = 10,
      INPUT_PIN = 9,
      READ_THROTTLE = 10;

bool on = false,
     buttonWasReleased = false,
     buttonWasPressed = false;

int lastRead = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(INPUT_PIN, INPUT);
}

void switchLED() {
  on = !on;
  digitalWrite(LED_PIN, on ? HIGH : LOW);
}

bool buttonIsPressed() {
  return digitalRead(INPUT_PIN) == HIGH;
}

void readButton() {
  bool pressed = buttonIsPressed();

  if(!pressed && !buttonWasReleased) {
    buttonWasReleased = true;
  } else if(pressed && buttonWasReleased && !buttonWasPressed) {
    buttonWasPressed = true;
  }
}

void loop() {
  readButton();

  if(buttonWasPressed && buttonWasReleased) {
    buttonWasPressed = buttonWasReleased = false;
    switchLED();
  }
}
