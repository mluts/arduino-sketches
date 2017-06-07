const int LED_PIN = 10,
      MAX_DELAY = 500,
      MIN_DELAY = 50,
      STEP = 50;

int currentDelay = MIN_DELAY;
bool rising = currentDelay < MAX_DELAY;

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

void led_on() {
  digitalWrite(LED_PIN, HIGH);
}

void led_off() {
  digitalWrite(LED_PIN, LOW);
}

void led_configure() {
  pinMode(LED_PIN, OUTPUT);
}

void delay_on() {
  delay(currentDelay);
}

void delay_off() {
  delay(currentDelay);

  if(rising) {
    currentDelay *= 1.3;
  } else {
    currentDelay *= 0.6;
  }
  currentDelay = MAX(currentDelay, MIN_DELAY);
  currentDelay = MIN(currentDelay, MAX_DELAY);

  if(currentDelay == MIN_DELAY) {
    rising = true;
  } else if(currentDelay == MAX_DELAY) {
    rising = false;
  }
}

void setup() {
  led_configure();
}

void loop() {
  led_on();
  delay_on();
  led_off();
  delay_off();
}
