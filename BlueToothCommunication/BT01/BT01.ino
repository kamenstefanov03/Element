#include "SoftwareSerial.h"
SoftwareSerial BT(2, 3);
void setup() 
{ 
 Serial.begin(9600); 
 BT.begin(38400);    
 Serial.println("Connected"); 
} 
void loop() 
{ 
 //from bluetooth to Terminal. 
 if (BT.available()) 
   Serial.write(BT.read()); 
 //from termial to bluetooth 
 if (Serial.available()) 
   BT.write(Serial.read());
}
