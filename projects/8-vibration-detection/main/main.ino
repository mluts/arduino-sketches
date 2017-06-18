#define SENSOR 3
#define LED 10

volatile bool vibration_detected = false;

void switch_led(bool state) {
  digitalWrite(LED, state ? HIGH : LOW);
}

void setup() {
  pinMode(SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  attachInterrupt(
    digitalPinToInterrupt(SENSOR),
    detect_vibration,
    CHANGE
  );
}

void loop() {
  if(vibration_detected) {
    vibration_detected = false;
    switch_led(true);
    delay(50);
  }
  switch_led(false);
}

void detect_vibration() {
  vibration_detected = true;
}
