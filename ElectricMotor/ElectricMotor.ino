/* 
This is the pattern used for an electromagnetic motor I posted on Thingiverse.
// https://www.thingiverse.com/thing:2905906

Video here:
// https://youtu.be/nSAchBjz5uI

For use with the Adafruit Motor Shield v2

// http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
//Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);

int del = 0;

//connect 10K trimpot to analogpin 3 to control frequency of pattern.
int analogPin = 3;

//add var for analogpinread and possibly tweaking
int val = 0; 

void setup() {
  Serial.begin(9600);// set up Serial library at 9600 bps

  AFMS.begin();  // create with the default frequency 1.6KHz

  myMotor1->setSpeed(250);
  myMotor3->setSpeed(250);
  myMotor4->setSpeed(250);
}

void loop() {

  val = analogRead(analogPin);
  //Serial.println(val); 
  del = val;

  myMotor1->run(FORWARD);
  myMotor3->run(RELEASE);
  myMotor4->run(RELEASE);

  delay(del);
  
  myMotor1->run(RELEASE);
  myMotor3->run(BACKWARD);
  myMotor4->run(RELEASE);

  delay(del);

  myMotor1->run(RELEASE);
  myMotor3->run(RELEASE);
  myMotor4->run(FORWARD);

  delay(del);

}

