#include <Servo.h>

Servo servo1;
Servo servo2;
int ldr1 = A1;
int ldr2 = A2;
int ldr3 = A3;
int ldr4 = A4;

int val1, val2, val3, val4;
int pos1;
int pos2;
int num = 2;

void setup() 
{
   servo1.attach(8);
   servo2.attach(9);
   pinMode(ldr1, INPUT);
   pinMode(ldr2, INPUT);
   pinMode(ldr3, INPUT);
   pinMode(ldr4, INPUT);
   servo1.write(pos1);
   servo2.write(pos2);
}

void loop() 
{
  val1 = analogRead(ldr1);
  val2 = analogRead(ldr2);
  val3 = analogRead(ldr3);
  val4 = analogRead(ldr4);

  if(val1 > val2) 
  {
    pos1 = pos1++;
  }
  if(val2 > val1) 
  {
    pos1 = pos1--;
  }

  if(val3 > val4) 
  {
    pos2 = pos2++;
  }
  if(val4 > val3) 
  {
    pos2 = pos2--;
  }
  servo1.write(pos1);
  servo2.write(pos2);

}
