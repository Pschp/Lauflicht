#include <Arduino.h>
#define VORWAERTS 1
#define RUECKWAERTS 2
#define HELLIGKEIT_LINKS 10
#define HELLIGKEIT_RECHTS 10

int Richtung = VORWAERTS;

int tastVerhaeltnis = 1000;
int maxTastVerhaeltnis = 200;

int Leds[] {5,6,9,10,11};
int AnzahlDerLeds=sizeof(Leds) / sizeof(Leds[0]);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void setup() {
  for (int i = 0; i < AnzahlDerLeds; i++){
    pinMode(Leds[i], OUTPUT);
  }
  Serial.begin(9600);
}

int aktuellerIndex=0;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void loop() {
  digitalWrite(Leds[aktuellerIndex], HIGH);
  if (aktuellerIndex < AnzahlDerLeds -1){
    analogWrite(Leds[aktuellerIndex+1], HELLIGKEIT_LINKS);
  }
  if (aktuellerIndex != 0){
    analogWrite(Leds[aktuellerIndex-1], HELLIGKEIT_RECHTS);
  }
  
  delay(tastVerhaeltnis);
  digitalWrite(Leds[aktuellerIndex], LOW);
  digitalWrite(Leds[aktuellerIndex+1], LOW);
  digitalWrite(Leds[aktuellerIndex-1],LOW);

  if (Richtung==VORWAERTS){
    if (aktuellerIndex == AnzahlDerLeds-1){
      Richtung=RUECKWAERTS;
      aktuellerIndex -=1;
    }
    else{
      aktuellerIndex += 1;
    }
  }
  else if(Richtung==RUECKWAERTS){
    if (aktuellerIndex == 0){
      aktuellerIndex = 1;
      Richtung=VORWAERTS;
    }
    else{
      aktuellerIndex -= 1;
    }

  }
Serial.println(aktuellerIndex);
  

//  for (int i = 0; i < AnzahlDerLeds; i++){
//    digitalWrite(Leds[i], HIGH);
//    delay(tastVerhaeltnis);
//    digitalWrite(Leds[i], LOW);
//  }
}