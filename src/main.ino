#include <Keyboard.h>

//resolution dependant
const int uncertainty = 20; //ammt voltage change for a software change to occur (approx 0.1 mm)
const int triggersens = uncertainty*5;  //approx 0.5mm
const int releasesens = uncertainty*2;  //apprpx 0.2mm
const int actuation = uncertainty*14;    //approx 1.4mm

bool key_1_pressed = false;
bool key_2_pressed = false;
bool key_3_pressed = false;
bool rt_1 = false;   //uses continuous rt
bool rt_2 = false;
bool rt_3 = false;

//calibration data
const int key_1_highest = 1862;
const int key_1_lowest = 1052;
const int key_2_highest = 1919;
const int key_2_lowest = 1036;
const int key_3_highest = 1943;
const int key_3_lowest = 1036;

//keybinds
const char KEY1 = 'c';
const char KEY2 = 'v';
const char KEY3 = 'b';

// analog states
int key_1 = 0;
int key_2 = 0;
int key_3 = 0;
int last_key_1 = 2000;
int last_key_2 = 2000;
int last_key_3 = 2000;

void setup() {
  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  analogReadResolution(12);
  delay(1000);

}

void loop() {

  key_1 = analogRead(26);
  key_2 = analogRead(27);
  key_3 = analogRead(28);

  // Serial.print("key 1: ");
  // Serial.println(key_1);
  // Serial.print("key 2: ");
  // Serial.println(key_2);
  // Serial.print("key 3: ");
  // Serial.println(key_3);

  if (rt_1) {
    if (key_1 < last_key_1 - triggersens || key_1 < key_1_lowest + uncertainty) {
      press_1();
      last_key_1 = key_1;
    }
    if (key_1 > last_key_1 + releasesens) {
      release_1();
      last_key_1 = key_1;
    }
  }
  if (rt_2) {
    if (key_2 < last_key_2 - triggersens || key_2 < key_2_lowest + uncertainty) {
      press_2();
      last_key_2 = key_2;
    }
    if (key_2 > last_key_2 + releasesens) {
      release_2();
      last_key_2 = key_2;
    }
  }
  if (rt_3) {
    if (key_3 < last_key_3 - triggersens || key_3 < key_3_lowest + uncertainty) {
      press_3();
      last_key_3 = key_3;
    }
    if (key_3 > last_key_3 + releasesens) {
      release_3();
      last_key_3 = key_3;
    }
  }
  

  if (key_1 < key_1_highest - actuation && !rt_1) {
    press_1();
    last_key_1 = key_1;
    rt_1 = true;
  }
  if (key_1 > key_1_highest - uncertainty) {
    release_1();
    rt_1 = false;
  }
    if (key_2 < key_1_highest - actuation && !rt_2) {
    press_2();
    last_key_2 = key_2;
    rt_2 = true;
  }
  if (key_2 > key_2_highest - uncertainty) {
    release_2();
    rt_2 = false;
  }
    if (key_3 < key_1_highest - actuation && !rt_3) {
    press_3();
    last_key_3 = key_3;
    rt_3 = true;
  }
  if (key_3 > key_3_highest - uncertainty) {
    release_3();
    rt_3 = false;
  }


  delay(1);

}

void press_1() {
  if (key_1_pressed) {
    Keyboard.press(KEY1);
    key_1_pressed = false;
  }
}
void press_2() {
  if (key_2_pressed) {
    Keyboard.press(KEY2);
    key_2_pressed = false;
  }
}
void press_3() {
  if (key_3_pressed) {
    Keyboard.press(KEY3);
    key_3_pressed = false;
  }
}
void release_1() {
  if (!key_1_pressed) {
    Keyboard.release(KEY1);
    key_1_pressed = true;
  }
}
void release_2() {
  if (!key_2_pressed) {
    Keyboard.release(KEY2);
    key_2_pressed = true;
  }
}
void release_3() {
  if (!key_3_pressed) {
    Keyboard.release(KEY3);
    key_3_pressed = true;
  }
}