#include <Servo.h>

Servo servo1;
Servo servo2;
int ldr1 = A1;
int ldr2 = A2;
int ldr3 = A3;
int ldr4 = A4;

int val1, val2, val3, val4;
int pos;
int num = 2;

void setup() 
{
   servo1.attach(8);
   servo2.attach(9);
   pinMode(ldr1, INPUT);
   pinMode(ldr2, INPUT);
   pinMode(ldr3, INPUT);
   pinMode(ldr4, INPUT);
   servo1.write(pos);
   servo2.write(pos);
}

void loop() 
{
  val1 = analogRead(ldr1);
  val2 = analogRead(ldr2);
  val3 = analogRead(ldr3);
  val4 = analogRead(ldr4);

  if(val1 > val2) 
  {
    pos = pos++;
    delay(1000);
  }
  if(val2 > val1) 
  {
    pos = pos--;
    delay(1000);
  }

  if(val3 > val4) 
  {
    pos = pos++;
    delay(1000);
  }
  if(val4 > val3) 
  {
    pos = pos--;
    delay(1000);
  }
  servo1.write(pos);
  servo2.write(pos);

}
