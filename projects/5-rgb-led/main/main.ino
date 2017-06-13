#define R 9
#define G 10
#define B 11

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  /* rgb(random(0, 255), random(0, 255), random(0, 255)); */
  rgb(0xff, 0xff, 0xff);
  delay(250);
}

void rgb(int r, int g, int b) {
  analogWrite(R, r);
  analogWrite(G, g);
  analogWrite(B, b);
}
