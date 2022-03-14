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
{
  // Set pin modes
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
{
  //Set motor positions baced off of potentiometer positions
  _Servo2 = analogRead(A0);
  servo_2.write(map(_Servo2, 0, 1023, 0, 180));

  _Servo3 = analogRead(A1);
  servo_3.write(map(_Servo3, 0, 1023, 0, 180));

  _Servo4 = analogRead(A2);
  servo_4.write(map(_Servo4, 0, 1023, 0, 180));
 
  // If Claw_Open variable is zero & digital pin 12 reads high
  if (0 == Claw_Open && digitalRead(12) == HIGH) {
    
    // set Claw_Open variable to 1
    Claw_Open = 1;
    
    // Move servo to specified rotation
    servo_5.write(map(0, 0, 1023, 179, 180));
    
    // delay 
    delay(1000); // Wait for 1000 millisecond(s)
    
    // If Claw_Open variable is zero & digital pin 12 reads high is not true
  } else {
    if (1 == Claw_Open && digitalRead(12) == HIGH) {
      
      // Set Claw_Open variable to zero
      Claw_Open = 0;
     
      // Move servo to specified rotation
      servo_5.write(map(0, 0, 1023, 1, 180));
      
      //Delay
      delay(1000); // Wait for 1000 millisecond(s)
    }
  }
}
