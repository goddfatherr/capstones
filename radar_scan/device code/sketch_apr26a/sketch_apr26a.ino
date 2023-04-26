// Include the servo library:
#include <Servo.h>
#include <boltiot.h>
// Create a new servo object:
Servo myservo;
//Credentials
#define API_KEY     "2825f857-7633-41db-a71c-2b83bdd26e8d"
#define DEVICE_ID   "BOLT15316359"
// Map pins
#define servoPin 8
#define echoPin  3
#define trigPin  2
// Create a variable to store the servo position:
int angle = 0;
long duration;
int distance;

//create buffer
int buff[181];

void setup() {
  // Attach the Servo variable to a pin:
  myservo.attach(servoPin);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  boltiot.begin(Serial);
  boltiot.setCommandString("send_buff",send_buff);
}
int measure(){
  digitalWrite(trigPin,LOW);
  delay(2);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration * 0.034/2;
  return distance;
  //Serial.print("Distance: ");
  //Serial.print(distance);
  //Serial.println(" cm");
  }
void scan(){
  // Sweep from 0 to 180 degrees:
  for (angle = 0; angle <= 180; angle += 1) {
    myservo.write(angle);
    buff[angle] = measure();
    //delay(10);
  }

  // And back from 180 to 0 degrees:
  for (angle = 180; angle >= 0; angle -= 1) {
    myservo.write(angle);
    //measure();
    delay(10);
  }
  }

String send_buff(String *data){
  String temp = "";
  scan();
  for(int i = 0; i<180;i++)
  temp = temp + " "+ String(buff[i]);
  return String(temp);
  }    
void loop() {
 //scan();
 boltiot.handleCommand();
}
