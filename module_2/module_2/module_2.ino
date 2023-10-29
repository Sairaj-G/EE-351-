#include <Servo.h>
#define Threshold 275
#define UnpressedAngle 20
#define PressedAngle 70
#define ServoPin 13

Servo servo;

void setup() {
  servo.attach(ServoPin);
  servo.write(UnpressedAngle);
}

void loop() {
  servo.write(UnpressedAngle);
  delay(1);

  int ldrOne = analogRead(A0);
  int ldrTwo = analogRead(A1);
  int ldrThree = analogRead(A2);

  if(ldrOne <= Threshold) {
      servo.write(PressedAngle);
      delay(50);
  }
  
}
