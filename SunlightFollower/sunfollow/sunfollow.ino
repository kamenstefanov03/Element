#include <Servo.h>

Servo servo1;
Servo servo2;
int ldr1 = A1;
int ldr2 = A2;

int val1, val2;
int inpos = 90;

void setup() 
{
   servo1.attach(8);
   pinMode(ldr1, INPUT);
   pinMode(ldr2, INPUT);
   servo1.write(inpos);
   delay(1000);
}

void loop() 
{
  val1 = analogRead(ldr1);
  val2 = analogRead(ldr2);

  if(val1 > val2) 
  {
    inpos = ++inpos;
  }
  if(val2 > val1) 
  {
    inpos = --inpos;
  }

  
  servo1.write(inpos);
  
  delay(100);

}
