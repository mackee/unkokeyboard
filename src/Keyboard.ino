#include "DigiKeyboard.h"
#include "constants.h"

#define USE_HSV
#include <WS2812.h>

WS2812 LED(NEOPIXELS_NUM);
cRGB value;

uint8_t keys[] = {9, 8, 7, 3};
byte keymaps[] = {KEY_U, KEY_N, KEY_K, KEY_O};

void setup() {
  LED.setOutput(NEOPIXEL_PIN);

  for(int i=0;i<NEOPIXELS_NUM;i++) {
    cRGB red = { 64, 0, 0 };
    LED.set_crgb_at(i, red);
  }
  LED.sync();
  delay(500);

  for(int i=0;i<NEOPIXELS_NUM;i++) {
    cRGB green = { 0, 64, 0 };
    LED.set_crgb_at(i, green);
  }
  LED.sync();
  delay(500);

  for(int i=0;i<NEOPIXELS_NUM;i++) {
    cRGB blue = { 0, 0, 64 };
    LED.set_crgb_at(i, blue);
  }
  LED.sync();
  delay(500);

  for(int i=0;i<NEOPIXELS_NUM;i++) {
    cRGB black = { 0, 0, 0 };
    LED.set_crgb_at(i, black);
  }
  LED.sync();
  delay(500);

  for(int i=0;i<KEYS;i++) {
    pinMode(keys[i], INPUT);
    digitalWrite(keys[i], HIGH);
  }
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);

  for(int i=0;i<KEYS;i++) {
    if (digitalRead(keys[i]) == LOW) {
      DigiKeyboard.sendKeyStroke(keymaps[i]);
    }
  }

  showLed();
  DigiKeyboard.delay(100);
}

int h = 0;
int sat = 255;
int val = 255;

void showLed() {
  h += 10;
  h %= 360;

  for(int i=0;i<NEOPIXELS_NUM;i++) {
    cRGB value;
    int hv = (h + (i * 45)) % 360;
    value.SetHSV(hv, sat, 127);
    LED.set_crgb_at(i, value);
  }
  LED.sync();
}
