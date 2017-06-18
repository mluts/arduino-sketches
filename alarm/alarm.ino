#define BUZZ 10
#define TONE_BASE 2000
#define TONE_SCALE 1000
#define DEG_TO_RAD(v) (v * PI / 180.0)
#define TONE_DELAY 2

void play_sin() {
  for(int i = 0; i < 180; i++)
  {
    tone(
      BUZZ,
      TONE_BASE + TONE_SCALE * sin(DEG_TO_RAD(i))
    );
    delay(TONE_DELAY);
  }
}

void setup() {
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  play_sin();
}
