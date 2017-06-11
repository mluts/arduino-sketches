#define LED_PIN 10
#define ANALOG_MAX 255
#define ANALOG_MIN 0

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define CLAMP(x, min, max) (MAX(MIN(x, max), min))

void fade_in(int time, int step) {
  int steps = ANALOG_MAX / step,
      stepDelay = time / steps;

  for(int i = ANALOG_MIN; i <= ANALOG_MAX; i += step)
  {
    analogWrite(LED_PIN, i);
    delay(stepDelay);
  }
}

void fade_out(int time, int step) {
  int steps = ANALOG_MAX / step,
      stepDelay = time / steps;

  for(int i = ANALOG_MAX; i >= ANALOG_MIN; i -= step)
  {
    analogWrite(LED_PIN, i);
    delay(stepDelay);
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  fade_in(1000, 5);
  delay(250);
  fade_out(1000, 5);
  delay(250);
}
