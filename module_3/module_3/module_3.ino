# include <Servo.h>
#define triggerPin 8 
#define echoPin 9  //PWM(Pulse Width Modulated)
#define velocity1 3
#define velocity2 10
#define obstacleThreshold 20

Servo servo;


//       motor inputs:  
//       input_2 - 6
//       input_1 - 7
//       input_4 - 1
//       input_3 - 2
//       enable_1  -> 5 // right (considering sensor)
//       enable_2  -> 3 // left
//       servoPin -> 4
void setup() {
    
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(velocity2, OUTPUT);
    pinMode(velocity1, OUTPUT);
    
//    Serial.begin(9600);
    analogWrite(velocity1, 80);
    analogWrite(velocity2, 255);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(3, OUTPUT);
    servo.attach(4); 
}

// motor driver inputs
// input 1 and input 2 drive right motor
// input 3 and input 4 drive left motot
// output 1 and output 

void forward() {
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(1, HIGH);
}

void backward() {
  turnRight();
  turnRight();
}

void turnLeft() {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(2, LOW);
    digitalWrite(1, HIGH);
    delay(340);
}

void turnRight() {
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(1, LOW);
    delay(340);
}

void halt(){
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(2, LOW);
  digitalWrite(1, LOW);
}

void loop() {

    // Ultrasonic Sensor

    long distance = checkDistance();
    


    analogWrite(3, 100); //`100
    analogWrite(5, 255); // 255

    if(distance >= obstacleThreshold){
      forward();
//      Serial.println("Forward");
//      Serial.println(distance);
    }
//    else if(leftDistance() >= obstacleThreshold){
//      turnLeft();
//      Serial.println("Left");
//    }
    else if(rightDistance() >= obstacleThreshold){
      turnRight();
//      Serial.println("FRight");
    }else{
      halt();
//      Serial.println("Halt");
    }

}

long checkDistance(){
  long duration, cm;
    
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    
    cm = microsecondsToCentimeters(duration);

    return cm;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

long leftDistance(){
  servo.write(-120);
//  delay(1500);
  long distance = checkDistance();
  servo.write(0);
  return distance;
}

long rightDistance(){
  servo.write(120);
//  delay(1500);
  long distance = checkDistance();
  servo.write(0);
  return distance;
}
