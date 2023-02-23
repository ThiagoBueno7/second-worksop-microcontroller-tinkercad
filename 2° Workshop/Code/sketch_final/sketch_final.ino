#include<Servo.h>

int potPin = A0;
int potValue;
int redLedPin = 8;
int greenLedPin = 13;
Servo servoMotor;

void setup()
{
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  servoMotor.attach(9);
}

void loop()
{
 potValue = analogRead(potPin);
  
  potValue = map(potValue, 0, 1023, 0 , 90);
  servoMotor.write(potValue);

  Serial.println(potValue);
  
  if(potValue <= 13){
    digitalWrite(greenLedPin, HIGH);
  }
  else if(potValue >= 77){
    digitalWrite(redLedPin, HIGH);
  }
  else if(potValue > 14 && potValue < 80){
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  }
}
