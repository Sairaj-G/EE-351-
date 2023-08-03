//Module 1 - task 1

#define OutputPin 13

void setup()
{
  pinMode(OutputPin, OUTPUT);
}

void loop()
{
  digitalWrite(OutputPin, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(OutputPin, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
