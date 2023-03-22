#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <boltiot.h>
#include "siren.h"

#define DHTTYPE    DHT11     // DHT 11
#define DHTPIN 2
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

#define SOIL_MOISTURE_PIN A0

#define BULB1  8
#define BULB2  7
#define BULB3  6
#define BULB4  5 
#define BULB5  3

#define PRESISTOR_PIN A1
#define BUZZ1 10
#define BUZZ2 9

#define PIR_PIN 4

#define RGB1   13
#define RGB2   12
#define RGB3   9

#define API_KEY     "2825f857-7633-41db-a71c-2b83bdd26e8d"
#define DEVICE_ID   "BOLT15316359"




String sound_siren(String *data){
 for(int i = 2; i>0;i--){
  digitalWrite(RGB1,HIGH);
  digitalWrite(RGB2,HIGH);
  digitalWrite(RGB3,HIGH);
  one();
  oneA();
  two();
  twoA();
  three();
  threeA();
  four();
  digitalWrite(RGB1,LOW);
  digitalWrite(RGB2,LOW);
  digitalWrite(RGB3,LOW);
 }
  return "True";
  }
  
void switch_bulb(int pin, int state){
  if(state == 1){
    digitalWrite(pin,HIGH); return;
    }
    digitalWrite(pin,LOW);
  }
  
String read_presistor(String *data){
  return String(analogRead(PRESISTOR_PIN));
  return "Hello World!";
  }
String read_pir(){
  return String(digitalRead(PIR_PIN));
  }
String read_temp(String *data){
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  return String(event.temperature);
  }  

String read_humd(String *data){
  sensors_event_t event;
  dht.humidity().getEvent(&event);
  return String(event.relative_humidity);
  }  

String read_smoisture(String *data){
  int output_value= analogRead(SOIL_MOISTURE_PIN);
  output_value = map(output_value,550,0,0,100);
  return String(output_value);
  }  
void setup() {
  Serial.begin(9600);
  dht.begin();
  sensor_t sensor;
  //delayMS = sensor.min_delay / 1000;

  boltiot.begin(Serial);
  boltiot.setCommandString("read_presistor",read_presistor);
  boltiot.setCommandString("read_pir",read_pir);
  boltiot.setCommandString("read_temp",read_temp);
  boltiot.setCommandString("read_humd",read_humd); 
  boltiot.setCommandString("read_smoisture",read_smoisture);  
  boltiot.setCommandString("sound_siren",sound_siren);
  
  
  pinMode(BUZZ1, OUTPUT);
  pinMode(BUZZ2, OUTPUT);
  pinMode(RGB1,OUTPUT);
  pinMode(RGB2,OUTPUT);
  pinMode(RGB3,OUTPUT);
  pinMode(PIR_PIN,INPUT);

  pinMode(BULB1, OUTPUT);
  pinMode(BULB2, OUTPUT);
  pinMode(BULB3, OUTPUT);
  pinMode(BULB4, OUTPUT);
  pinMode(BULB5, OUTPUT);
  
}

void loop() {

  boltiot.handleCommand();
  /**
  sound_siren(10);
 switch_bulb(BULB1,1);
 digitalWrite(BULB1,HIGH);
 delay(1000);
 switch_bulb(BULB2,1);
 delay(1000);
 switch_bulb(BULB3,1);
 delay(1000);
 switch_bulb(BULB4,1);
 delay(1000);
 switch_bulb(BULB5,1);
 delay(1000);
 switch_bulb(BULB5,0);
 delay(1000);
 switch_bulb(BULB4,0);
 delay(1000);
 switch_bulb(BULB3,0);
 delay(1000);
 switch_bulb(BULB2,0);
 delay(1000);
 switch_bulb(BULB1,0);
 delay(1000);
  /**DEBUG PRESISTOR
  Serial.print("BRIGHNESS: ");
  Serial.println(read_presistor());
  delay(5000);
  **/
  /**PIR DEBUG LINES
  Serial.print("PIR VALUE: ");
  Serial.println(read_pir());
  delay(5000);
  **/
/** SOIL MOSITURE DEBUG LINES
  Serial.print("Mositure : ");
  Serial.print(read_smoisture());
  Serial.println("%");
  delay(1000);

  **/
/** DHT11 DEBUG LINES
  Serial.print(F("Temperature: "));
  Serial.print(read_temp());
  Serial.println(F("°C"));

  Serial.print(F("Humidity: "));
  Serial.print(read_humd());
  Serial.println(F("%"));
  delay(2000);
  **/
}
