/*

Sunset

*/

#include <FastLED.h>
#define NUM_LEDS 60
#define DATA_PIN 6

//Initialise the LED array
CRGB leds[NUM_LEDS];

void setup() {
  delay(2000); //Delay for two seconds to power the LEDS before starting the data signal on the Arduino
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  sunSet();
}


void sunSet(){
  int i = 0;
  for(i=0; i<20; i++) {   //for the first 100 LEDs
    leds[i] = CRGB(150, 20, 0);   //set LEDs red-ish in cloud one
  }
  for(i=21; i<30; i++) {  //for LEDs 101 to 150
    leds[i] = CRGB(150, 90, 0);   //set LEDs red-ish in cloud one
  }
  for(i=31; i<40; i++) {  //for LEDs 151 to 250
    leds[i] = CRGB(150, 50, 0);
  }
  for(i=41; i<50; i++) {  //for LEDs 251 to 260
    leds[i] = CRGB(150, 50, 0);
  }
  for(i=51; i<NUM_LEDS; i++) {  //for LEDs 251 to 260
    leds[i] = CRGB(150, 20, 0);
  }
  FastLED.show(); //show all the colors that were set in cloud one
}

