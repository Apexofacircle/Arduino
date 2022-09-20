
#include <Servo.h>
bool V;
Servo servo_2;

void setup()
{
  V = 1;
  servo_2.attach(2, 500, 2500);
  pinMode(9, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  servo_2.write(0);
}

void loop()
{
  if (digitalRead(9) == HIGH && V) {
    digitalWrite(LED_BUILTIN, LOW);
    servo_2.write(90);
    V = 0;
  } 
  
  if(digitalRead(9) == LOW && !V){
    digitalWrite(LED_BUILTIN, HIGH);
    servo_2.write(0);
    V = 0;
  }
  delay(10); // Delay a little bit to improve simulation performance
}
