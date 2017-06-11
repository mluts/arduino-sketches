#define CAR_GREEN 7
#define CAR_YELLOW 6
#define CAR_RED 5
#define PED_GREEN 4
#define PED_RED 3

#define BTN 8
#define BTN_PRESSED_LEVEL LOW
#define BTN_READ_THRESHOLD 50
#define LVL(val) (val ? HIGH : LOW)

enum color {
  RED, GREEN, YELLOW, NONE
};

struct button {
  int pin;
  bool was_pressed;
  bool was_released;
  bool active;
  int last_read;
} button = { BTN, false, false, 0 };

struct traffic_light {
  enum color car_color;
  enum color ped_color;
} traffic_light = { GREEN, RED };

void read_button() {
  int time = millis();

  if(time < (button.last_read + BTN_READ_THRESHOLD)) {
    return;
  } else {
    button.last_read = time;
  }

  bool button_pressed = digitalRead(BTN) == BTN_PRESSED_LEVEL;

  if(button_pressed && !button.was_pressed && !button.was_released) {
    button.was_pressed = true;
  } else if(!button_pressed && button.was_pressed && !button.was_released) {
    button.was_released = true;
    button.active = true;
  }
}

void reset_button() {
  button.was_pressed = false;
  button.was_released = false;
  button.active = false;
}

void render_traffic_light() {
  digitalWrite(CAR_GREEN, LVL(traffic_light.car_color == GREEN));
  digitalWrite(CAR_YELLOW, LVL(traffic_light.car_color == YELLOW));
  digitalWrite(CAR_RED, LVL(traffic_light.car_color == RED));

  digitalWrite(PED_RED, LVL(traffic_light.ped_color == RED));
  digitalWrite(PED_GREEN, LVL(traffic_light.ped_color == GREEN));
}

void allow_pedestrians_to_pass() {
  traffic_light.car_color = YELLOW;
  traffic_light.ped_color = RED;
  render_traffic_light();
  delay(2000);

  traffic_light.car_color = RED;
  render_traffic_light();
  delay(1000);

  traffic_light.ped_color = GREEN;
  render_traffic_light();
  delay(3000);

  for(int i = 0; i < 5; i++)
  {
    traffic_light.ped_color = NONE;
    render_traffic_light();
    delay(250);

    traffic_light.ped_color = GREEN;
    render_traffic_light();
    delay(250);
  }

  traffic_light.ped_color = RED;
  render_traffic_light();
  delay(500);

  traffic_light.car_color = YELLOW;
  render_traffic_light();
  delay(1000);

  traffic_light.car_color = GREEN;
  render_traffic_light();
}

void setup()
{
  pinMode(CAR_GREEN,  OUTPUT);
  pinMode(CAR_YELLOW, OUTPUT);
  pinMode(CAR_RED,    OUTPUT);
  pinMode(PED_GREEN,  OUTPUT);
  pinMode(PED_RED,    OUTPUT);
  pinMode(BTN,        INPUT);

  render_traffic_light();
}

void loop()
{
  read_button();

  if(button.active) {
    reset_button();

    allow_pedestrians_to_pass();
  }

  render_traffic_light();
}
