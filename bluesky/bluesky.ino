/*

Blue sky

Created for use with "artificial cloud" made from rice paper lantern coated with cotton wool.
Potentiometer 1 adjusts the tone of blue
Potentiometer 2 adjusts the brightness

*/

#include <FastLED.h>
#define NUM_LEDS 60
#define DATA_PIN 6

//Initialise the LED array
CRGB leds[NUM_LEDS];

//Pin connections
const int potPin1 = A2;   // The potentiometer signal pin is connected to Arduino's Analog Pin 2
const int potPin2 = A3;   // The potentiometer signal pin is connected to Arduino's Analog Pin 3

// Global variables
byte potVal1;
byte potVal2;
int potPin1Value = 0;
int potPin2Value = 0;

int LEDPosition=0;

void setup() {
  delay(2000); //Delay for two seconds to power the LEDS before starting the data signal on the Arduino
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  readPot1();
  readPot2();
  blueSky();
}

void blueSky(){
  // Blueish tones only
  potVal1 = map(potPin1Value, 0, 1023 , 130, 180);
  potVal2 = map(potPin2Value, 0, 1023 , 0, 200);
  fill_solid( leds, NUM_LEDS, CHSV(potVal1,255,potVal2));
  FastLED.show(); 
  delay(30); 
}

void readPot1(){
  potPin1Value = analogRead(potPin1);
  //Serial.println(potVal1);
  //delay(1);
}
void readPot2(){
  potPin2Value = analogRead(potPin2);
  //Serial.println(potVal2);
  //delay(1);
}

