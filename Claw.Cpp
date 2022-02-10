// C++ code
//
#include <Servo.h>

int Claw_Open = 0;

// initiate servo on port 2
Servo servo_2;

// initiate servo on digital port 3
Servo servo_3;

// initiate servo on digital port 4
Servo servo_4;

// initiate servo on digital port 5
Servo servo_5;

// Run at boot up
void setup()
{
  // Set pin mode for Analog 0 to INPUT
  pinMode(A0, INPUT);
  
  // Atach Servo on pin 2
  servo_2.attach(2, 500, 2500);

  // Set pin mode for Analog 1 to INPUT
  pinMode(A1, INPUT);
  
   // Atach Servo on pin 3
  servo_3.attach(3, 500, 2500);

  // Set pin mode for Analog 2 to INPUT
  pinMode(A2, INPUT);
  
   // Atach Servo on pin 4
  servo_4.attach(4, 500, 2500);

  // Set pin mode for Digital 12 to INPUT
  pinMode(12, INPUT);
  
  // Atach servo on pin 5
  servo_5.attach(5, 500, 2500);

}

void loop()
{
  // move servo to Analog 0's input
  servo_2.write(map(analogRead(A0), 0, 1023, 0, 180));
  
  // move servo to Analog 1's input
  servo_3.write(map(analogRead(A1), 0, 1023, 0, 180));
  
  // move servo to Analog 2's input
  servo_4.write(map(analogRead(A2), 0, 1023, 0, 180));
 
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
    // Claw_Open variable is one & digital pin 12 reads high
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
