#define BUZZ 10
#define RAD(n) (n * (PI / 180.0))
#define PITCH_CONST 1.059463094359
#define PITCH 440
#define BASE_OCTAVE 4
#define TEMPO 90

#define LED1 8
#define LED2 9

const float B = 60.0 * 1000 / TEMPO;

bool sound_on = true,
     led1_on = false,
     led2_on = false;

float time_played = 0;

enum note {
  C, Cs,
  D, Ds,
  E,
  F, Fs,
  G, Gs,
  A, As,
  H,
  NONE
};

struct note_sound {
  enum note note;
  int octave;
  int time;
  bool led1;
  bool led2;
};

int beats_played() {
  return int(time_played / B);
}

float note_frequency(enum note n, int octave) {
  int distance;

  switch(n) {
    case C:
      distance = -9;
      break;
    case Cs:
      distance = -8;
      break;
    case D:
      distance = -7;
      break;
    case Ds:
      distance = -6;
      break;
    case E:
      distance = -5;
      break;
    case F:
      distance = -4;
      break;
    case Fs:
      distance = -3;
      break;
    case G:
      distance = -2;
      break;
    case Gs:
      distance = -1;
      break;
    case A:
      distance = 0;
      break;
    case As:
      distance = 1;
      break;
    case H:
      distance = 2;
      break;
  }

  distance += (octave - BASE_OCTAVE) * 12;

  return PITCH * pow(PITCH_CONST, distance);
}

void setup() {
  pinMode(BUZZ, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

struct note_sound intro[] = {
  {A, 3, B/2, 1, 0},
  {C, 4, B/2, 1, 0},
  {E, 4, B/2, 1, 0},
  {A, 4, B/2, 1, 0},

  {H, 4, B/2, 0, 1},
  {E, 4, B/2, 0, 1},
  {C, 4, B/2, 0, 1},
  {H, 4, B/2, 0, 1},

  {C, 5, B/2, 1, 1},
  {E, 4, B/2, 1, 1},
  {C, 4, B/2, 1, 1},
  {C, 5, B/2, 1, 1},

  {Fs, 4, B/2},
  {D, 4, B/2},
  {A, 3, B/2},
  {Fs, 4, B/2},

  {E, 4, B/2, 1, 0},
  {C, 4, B/2, 0, 1},
  {A, 3, B/2, 1, 0},
  {C, 4, B/2, 0, 1},

  {NONE, 4, B/2, 0, 1},
  {E, 4, B/2, 1, 0},
  {C, 4, B/2, 1, 0},
  {A, 3, B/2, 0, 0},

  {H, 3, B/2, 1, 1},
  {C, 4, B/2, 0, 0},

  {C, 4, B, 1, 1},

  {H, 4, -1}
};

struct note_sound pre_intro_repeat[] = {
  {NONE, 4, B/2, 0, 0},
  {A, 2, B/2, 1, 0},
  {F, 3, B/2, 0, 1},
  {E, 3, B/2, 1, 0},
  {H, 4, -1}
};

struct note_sound bridge1[] {
  {NONE, 4, B},

  {A, 2, B/2, 1, 0},
  {H, 2, B/2, 0, 1},

  {C, 3, B/2, 1, 1},
  {E, 3, B/2, 1, 1},
  {G, 3, B/2, 0, 0},
  {E, 4, B/2, 0, 0},

  {Fs, 4, B/2, 1, 1},
  {D, 4, B/2, 1, 1},
  {A, 3, B/2, 0, 0},
  {Fs, 4, B/2, 0, 0},

  {E, 4, B/2, 1, 1},
  {C, 4, B/2, 1, 1},
  {A, 3, B/2, 0, 0},
  {E, 4, B/2, 0, 0},

  {H, 3, B/4, 1, 0},
  {C, 4, B/4, 0, 1},
  {A, 3, B/4, 1, 0},
  {E, 3, B/4, 0, 0},
  {H, 4, -1}
};

struct note_sound bridge2[] {
  {A, 2, B/2, 1, 0},
  {H, 2, B/2, 0, 1},

  {C, 3, B/2, 1, 1},
  {E, 3, B/2, 1, 1},
  {G, 3, B/2, 0, 0},
  {E, 4, B/2, 0, 0},

  {G, 4, B/2, 1, 1},
  {H, 3, B/2, 1, 1},
  {G, 3, B/2, 0, 0},
  {G, 4, B/2, 0, 0},

  {G, 4, B/4, 1, 0},
  {Fs, 4, B/4, 0, 1},
  {Fs, 4, B/4, 1, 0},
  {NONE, 4, B/4, 0, 1},

  {Fs, 4, B, 1, 1},
  {H, 4, -1}
};

struct note_sound bridge3[] {
  {A, 2, B/2, 1, 0},
  {H, 2, B/2, 0, 1},

  {C, 3, B/2, 1, 1},
  {E, 3, B/2, 1, 1},
  {G, 3, B/2, 0, 0},
  {E, 4, B/2, 0, 0},

  {Fs, 4, B/2, 1, 1},
  {D, 4, B/2, 1, 1},
  {A, 3, B/2, 0, 0},
  {Fs, 4, B/2, 0, 0},

  {E, 4, B/2, 1, 1},
  {E, 4, B/2, 0, 0},
  {E, 4, B*2, 1, 1},
  {NONE, 4, B, 0, 0},

  {H, 4, -1}
};

void render_leds() {
  if(beats_played() % 2 == 0) {
    led1_on = true;
    led2_on = false;
  } else {
    led1_on = false;
    led2_on = true;
  }

  digitalWrite(LED1, led1_on ? HIGH : LOW);
  digitalWrite(LED2, led2_on ? HIGH : LOW);
}

void render_note_leds(bool led1, bool led2) {
  digitalWrite(LED1, led1 ? HIGH : LOW);
  digitalWrite(LED2, led2 ? HIGH : LOW);
}

void play_note(enum note n, int octave, int time) {
  if(n == NONE) {
    noTone(BUZZ);
    delay(time);
  } else {
    float frequency = note_frequency(n, octave);
    tone(BUZZ, frequency);
    delay(time);
    noTone(BUZZ);
  }
}

void play_notes(struct note_sound ns[]) {
  for(int i = 0; i < ns[i].time > 0; i++) {
    render_note_leds(ns[i].led1, ns[i].led2);
    play_note(
      ns[i].note,
      ns[i].octave,
      ns[i].time
    );
  }
}

void loop() {
  play_notes(intro);
  play_notes(pre_intro_repeat);
  play_notes(intro);
  play_notes(bridge1);
  play_notes(bridge2);
  play_notes(bridge1);
  play_notes(bridge3);
}
