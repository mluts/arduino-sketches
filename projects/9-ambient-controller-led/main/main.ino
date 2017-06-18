#define LED 10
#define PHOTO_ANALOG 0
#define THRESHOLD 1000

void set_led(bool on) {
  digitalWrite(LED, on ? HIGH : LOW);
}

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  set_led(analogRead(PHOTO_ANALOG) < THRESHOLD);
}
