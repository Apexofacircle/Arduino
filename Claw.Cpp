// C++ code
//
#include <Servo.h>

int Claw_Open = 0;

Servo servo_2;

Servo servo_3;

Servo servo_4;

Servo servo_5;

void setup()
{
  pinMode(A0, INPUT);
  servo_2.attach(2, 500, 2500);

  pinMode(A1, INPUT);
  servo_3.attach(3, 500, 2500);

  pinMode(A2, INPUT);
  servo_4.attach(4, 500, 2500);

  pinMode(12, INPUT);
  servo_5.attach(5, 500, 2500);

}

void loop()
{
  servo_2.write(map(analogRead(A0), 0, 1023, 0, 180));
  servo_3.write(map(analogRead(A1), 0, 1023, 0, 180));
  servo_4.write(map(analogRead(A2), 0, 1023, 0, 180));
  if (0 == Claw_Open && digitalRead(12) == HIGH) {
    Claw_Open = 1;
    servo_5.write(map(0, 0, 1023, 179, 180));
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    if (1 == Claw_Open && digitalRead(12) == HIGH) {
      Claw_Open = 0;
      servo_5.write(map(0, 0, 1023, 1, 180));
      delay(1000); // Wait for 1000 millisecond(s)
    }
  }
}
