// module 1 - task 2

int ledPins[] = {4,7,6,5,8,9,10,11};
#define InputOne 12
#define InputTwo 13
#define Buzzer 3

void setup(){
  
  for (int i = 0; i < 8; i++){
    pinMode(ledPins[i], OUTPUT);
  }
  
  pinMode(InputOne, INPUT);
  pinMode(InputTwo, INPUT);
  pinMode(Buzzer, OUTPUT);
  
}

void loop(){
  
  int randomNum = random(10);
  int correctAns = 3 - randomNum%3;
  
  displayRandom(randomNum);
  displayCounter(0);
  
  delay(2000);
  
  for(int i=1;i<10;i++){
    
    int inputOne = digitalRead(InputOne);
    int inputTwo = digitalRead(InputTwo);
    
    displayCounter(i);
   
    if(2*inputOne + inputTwo == correctAns){
      buzzOnce();     
      break;
    }
    else if(inputOne > 0 || inputTwo > 0){
      buzzThrice();
    }
    delay(1000);
  }  
 
    
}
void displayCounter(int digit){
  for (int i = 0; i < 4; i++){
    digitalWrite( ledPins[i], (digit >> i) & 1 ? HIGH : LOW );
  }
}

void displayRandom(int digit){
  for (int i = 4; i < 8; i++){
    digitalWrite( ledPins[i], (digit >> (i-4)) & 1 ? HIGH : LOW );
  }
}

void buzzOnce(){
  digitalWrite(3,127);
  delay(200);
}

void buzzThrice(){
  digitalWrite(3,20);
  //delay(100);
  digitalWrite(3,40);
  //delay(100); 
  digitalWrite(3,60);
  //delay(100);
  digitalWrite(3,0);
  delay(200);
}
