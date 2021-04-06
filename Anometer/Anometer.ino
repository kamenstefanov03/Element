int ledPin = 9;

void setup() {
 Serial.begin(9600);
}

void loop() 
{
    
}



void ReadingValue()
{
  int sensorValue = analogRead(A0);

 analogWrite(ledPin, sensorValue * (51.0 / 1023.0) * 50);
 
 if(sensorValue > 0){
    Serial.println(sensorValue);
    Serial.print(" ");
}
}
