// libraries 
#include <Servo.h>

// variables
int Claw_Open = 0;
int _Servo2 = 0;
int _Servo3 = 0; 
int _Servo4 = 0;
int _Servo5 = 0;

// initiate servos
Servo servo_2; //bace
Servo servo_3; //elbow
Servo servo_4; //wrist
Servo servo_5; //claw
Servo servo_6; //claw

// Run at boot up
void setup()
{// Set pin modes
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(12, INPUT);
  
  // Atach servos 
  servo_2.attach(2, 500, 2500);
  servo_3.attach(3, 500, 2500);
  servo_4.attach(4, 500, 2500);
  servo_5.attach(5, 500, 2500);
}

void loop()
{//Set motor positions baced off of potentiometer positions
  _Servo2 = analogRead(A0);
  servo_2.write(map(_Servo2, 0, 1023, 0, 180));

  _Servo3 = analogRead(A1);
  servo_3.write(map(_Servo3, 0, 1023, 0, 180));

  _Servo4 = analogRead(A2);
  servo_4.write(map(_Servo4, 0, 1023, 0, 180));
 
  // open and close claw at press of a button (linked to pin 12)
  if (0 == Claw_Open && digitalRead(12) == HIGH) {

    Claw_Open = 1;
    servo_5.write(map(0, 0, 1023, 179, 180));
    servo_6.write(map(0, 0, 1023, 179, -180));
    delay(1000); 
    
  } else {
    if (1 == Claw_Open && digitalRead(12) == HIGH) {
      Claw_Open = 0;
      servo_5.write(map(0, 0, 1023, 1, 180));
      servo_6.write(map(0, 0, 1023, 1, -180));
      delay(1000);
    }
  }
}
