#include "Arduino.h"
//int buzz;
#define buzz 10
void one() {         //This function produces the 1st siren sound with ON/OFF led transition.
  // Whoop up
  for(int hz = 440; hz < 1000; hz+=25){
    tone(buzz, hz, 50);
    delay(5);
    for(int i=3;i<=7;i++)
    digitalWrite(i,HIGH);
  }
  // Whoop down
  for(int hz = 1000; hz > 440; hz-=25){
    tone(buzz, hz, 50);
    delay(5);
    for(int i=3;i<=7;i++)
    {
      digitalWrite(i,LOW);
      digitalWrite(i+5,HIGH);
      }
  }
  }




  
void oneA() {                //This function produces differnt transition on 1st siren.
  
  // Whoop up
  for(int hz = 440; hz < 1000; hz+=25){
    tone(buzz, hz, 50);
    delay(5);
  }
 
  // Whoop down
  for(int hz = 1000; hz > 440; hz-=25){
    tone(buzz, hz, 50);
    delay(5);
  }
  }
void two() {                   //This function produces the 2nd siren sound with progressive led transition.
  // Whoop up
  for(int hz = 440; hz < 1000; hz+=25){
    tone(buzz, hz, 50);
    delay(5);
  }
  // Whoop down
  for(int hz = 1000; hz > 440; hz-=25){
    tone(buzz, hz, 50);
    delay(5);
  }
  }
void twoA() {                  //This function produces differnt transition on 2nd siren.
  // Whoop up
  for(int hz = 440; hz < 1000; hz+=25){
    tone(buzz, hz, 50);
    delay(5);
  }
    
  // Whoop down
  for(int hz = 1000; hz > 440; hz-=25){
    tone(buzz, hz, 50);
    delay(5);
  }
  }
  void three() {              //This function produces the 3rd siren(AMBULANCE) sound with led transition.
  tone(buzz,440,200);
    delay(300);
  for(int i=3;i<=6;i++)
  digitalWrite(i,HIGH);
  noTone(buzz);
  tone(buzz,494,500);
  delay(300);
  for(int i=3;i<=6;i++){
  digitalWrite(i,LOW);
  digitalWrite(i+6,HIGH);
  }
  noTone(buzz);
  tone(buzz,523,300);
   delay(200);
  digitalWrite(7,HIGH);
  delay(50);
  digitalWrite(8,HIGH);
  delay(50);
  noTone(buzz);
}
  void threeA() {              //This function produces differnt transition on 3rd siren.
  tone(buzz,440,200);
    delay(100);
  noTone(buzz);
  for(int i=3;i<=4;i++){
  digitalWrite(i,HIGH);
  digitalWrite(i+8,HIGH);}
  tone(buzz,494,500);
  delay(300);
  noTone(buzz);
  for(int i=3;i<=4;i++){
  digitalWrite(i,LOW);
  digitalWrite(i+8,LOW);
  }
  tone(buzz,523,300);
   delay(300);
  noTone(buzz);
}
void four() {                             //This function produces the 4th siren(POLICE) sound with led transition.
for(int i=3;i<=11;i+=2)
digitalWrite(i,HIGH);
  for(int hz = 440; hz < 1000; hz++){
    tone(buzz, hz, 50);
    delay(5);
  }
for(int i=3;i<=11;i+=2)
digitalWrite(i,LOW);
 for(int i=4;i<=12;i+=2)
digitalWrite(i,HIGH);
  for(int hz = 1000; hz > 440; hz--){
    tone(buzz, hz, 50);
    delay(5);
    }
  }
