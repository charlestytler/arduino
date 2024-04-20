// **********************************************************************************
// Author: Sunit Raut   github.com/SunitRaut
// **********************************************************************************
// License
// **********************************************************************************
// This program is free software; you can redistribute it
// and/or modify it under the terms of the GNU General
// Public License as published by the Free Software
// Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will
// be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A
// PARTICULAR PURPOSE. See the GNU General Public
// License for more details.
//
// Licence can be viewed at
// http://www.gnu.org/licenses/gpl-3.0.txt
//
// Please maintain this license information along with authorship
// and copyright notices in any redistribution of this code
// **********************************************************************************
/*
 * Connect the four control pins to any Arduino pins.
 * This example uses digital pins 4, 5, 6, and 7.
 * You will get analog output at the Analog pin that you connect to Sig pin of CD74HC4067
 * This examples loops through all channels and prints theanalog input at all 16 channels
 */

#include <light_CD74HC4067.h>

#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    8

CRGB leds[NUM_LEDS];

// s0 s1 s2 s3: select pins
CD74HC4067 mux(10, 16, 14, 15); // create a new CD74HC4067 object with its four select lines

const int signal_pin = A0; // Pin Connected to Sig pin of CD74HC4067

void setup()
{
    Serial.begin(9600);
    pinMode(signal_pin, INPUT); // Set as input for reading through signal pin

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

int stored_vals[16] = {};
char buffer[16 * 8];

void loop()
{
    // loop through channels 0 - 15
    for (int i = 0; i < 9; i++) {
        mux.channel(i);
        int val = analogRead(signal_pin); // Read analog value
        // Serial.println("Channel "+String(i)+": "+String(val));  // Print value
        stored_vals[i] = val;
        // delay(500);
    }
    sprintf(buffer,
            "1:%4d 2:%4d 3:%4d 4:%4d 5:%4d 6:%4d 7:%4d 8:%4d 9:%4d 10:%4d",
            stored_vals[0],
            stored_vals[1],
            stored_vals[2],
            stored_vals[3],
            stored_vals[4],
            stored_vals[5],
            stored_vals[6],
            stored_vals[7],
            stored_vals[8],
            stored_vals[9]);
    Serial.println(buffer);
    delay(100);

    leds[0] = CRGB((stored_vals[2]/1024.0f) * 255, 0, 0);
    leds[1] = CRGB(255, (stored_vals[4]/1024.0f) * 255, 0);
    FastLED.show();
}
