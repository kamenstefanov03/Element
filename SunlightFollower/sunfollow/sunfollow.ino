#include <Servo.h>

Servo servo1;
Servo servo2;
int ldr1 = A1;
int ldr2 = A2;
int ldr3 = A3;
int ldr4 = A4;

int val1, val2, val3, val4;
int inpos = 90;

void setup() 
{
   servo1.attach(8);
   servo2.attach(9);
   pinMode(ldr1, INPUT);
   pinMode(ldr2, INPUT);
   pinMode(ldr3, INPUT);
   pinMode(ldr4, INPUT);
   servo1.write(inpos);
   delay(1000);
   servo2.write(inpos);
   delay(1000);
}

void loop() 
{
  val1 = analogRead(ldr1);
  val2 = analogRead(ldr2);
  val3 = analogRead(ldr3);
  val4 = analogRead(ldr4);

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
