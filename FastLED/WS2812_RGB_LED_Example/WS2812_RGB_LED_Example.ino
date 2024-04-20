#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    8

CRGB leds[NUM_LEDS];

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  FastLED.setBrightness(150);
  
  leds[7] = CRGB(0, 150, 0);
  FastLED.show();
  delay(500);

  leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);  
  leds[1] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[3] = CRGB(150, 0, 255);
  FastLED.show();
  delay(500);
  leds[4] = CRGB(255, 191, 0);
  FastLED.show();
  leds[5] = CRGB(255, 191, 0);
  FastLED.show();
  delay(500);
  leds[6] = CRGB(85, 60, 180);
  FastLED.show();
  delay(500);

}

void loop() {


}