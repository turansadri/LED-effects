/*

Theater chase

Potentiometer 1 adjusts the color
Potentiometer 2 controls the strobe speed

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
  theaterChase();
}


void theaterChase() {
  
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 20; q++) {

      potPin1Value = analogRead(potPin1);
      int hue = map(potPin1Value, 0, 1023 , 0, 255);
      int sat = 127;
      if (hue == 0){
        sat = 0;
      }
      potPin2Value = analogRead(potPin2);
      int wait = map(potPin2Value, 0, 1023 , 200, 10);

      for (int i=0; i < 60; i=i+20) {
        leds[i+q] = CHSV(hue,sat,180);
      }
      FastLED.show();
     
      delay(wait);

      for (int i=0; i < 60; i=i+20) {
        leds[i+q] = CRGB::Black;
      } 
    }
  }
}

void readPot1(){
  potPin1Value = analogRead(potPin1);
  //Serial.println(potVal1);
  //delay(1);
}
void readPot2(){
  potPin2Value = analogRead(potPin2);
  Serial.println(potVal2);
  delay(1);
}

