#define TEMPERATURE_PIN 0
#define BUZZ 10
#define ANALOG_TO_V(v) ((v * 5.0) / 1024)
#define V_TO_T(v) (v / 0.01)
#define TEMPERATURE_THRESHOLD 27

#define TONE_BASE 2000
#define TONE_SCALE 1000
#define DEGREE_TO_TONE(rad) (TONE_BASE + (rad * TONE_SCALE) / (PI / 180))
#define DEGREE_TO_RAD(v) (v * PI / 180)

#define SERIAL_PRINT_THRESHOLD 500

int last_serial_print = 0;

void play_sin() {
  for(int i = 0; i < 180; i++)
  {
    tone(BUZZ, TONE_BASE + TONE_SCALE * DEGREE_TO_RAD(i));
    delay(2);
  }
  for(int i = 180; i > 0; i--)
  {
    tone(BUZZ, TONE_BASE + TONE_SCALE * DEGREE_TO_RAD(i));
    delay(2);
  }
}

float read_temperature() {
  int value = analogRead(TEMPERATURE_PIN);
  return V_TO_T(ANALOG_TO_V(value));
}

void print_temperature(float t) {
  int time = millis();

  if(time < (last_serial_print + SERIAL_PRINT_THRESHOLD)) {
    return;
  }

  last_serial_print = time;

  Serial.print("t: ");
  Serial.print(t);
  Serial.println("C");
}

void setup() {
  pinMode(BUZZ, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float t = read_temperature();

  if(t > TEMPERATURE_THRESHOLD) {
    play_sin();
  } else {
    noTone(BUZZ);
  }

  print_temperature(t);
}
