#include "DigiKeyboard.h"
#define MOD_SHIFT_LEFT      (1<<1)  //00000010
#define MOD_GUI_LEFT        (1<<3)  //00001000
#define MOD_CONTROL_LEFT    1
#define KEY_ENTER   40
#define KEY_C       6
#define KEY_M       16
#define KEY_D       7

int ledPinGreen = 1;
int ledPinRed = 0;
int analogInPin2 = 1; // analogRead(1) is on P2

// Variables will change:
bool toggleMode = LOW;
bool currentState = LOW;
bool ledGreen = HIGH;
bool ledRed = LOW;
bool doOnce = LOW;

void setup() {
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
}
void loop() {
 
  if(analogRead(analogInPin2)>100){
    currentState = HIGH;
    if (currentState != toggleMode){
      if (ledRed == LOW){
        ledGreen = LOW;
        ledRed = HIGH;
        doOnce = HIGH;
      }
      else{
        ledGreen = HIGH;
        ledRed = LOW;
        doOnce = HIGH;
      }
    }
    toggleMode = HIGH;
  } else{
    toggleMode = LOW;
  }

  //digitalWrite(ledPinGreen, testState);
  if (doOnce == HIGH){
    digitalWrite(ledPinGreen, ledGreen);
    digitalWrite(ledPinRed, ledRed);

  // put your setup code here, to run once:
  DigiKeyboard.sendKeyStroke(KEY_M, MOD_CONTROL_LEFT + MOD_SHIFT_LEFT);
  
    doOnce = LOW;    
  } 
}
