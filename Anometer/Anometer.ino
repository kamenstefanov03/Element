<<<<<<< Updated upstream
void setup() {
  Serial.begin(9600);

}

void loop() {
  int AnometerValue = analogRead(A0);
  analogWrite(AnometerValue * (51.0 / 1023.0) * 50);

  if(AnometerValue > 0){
    Serial.println(AnometerValue);
    Serial.print("");
  }

}
=======
int ledPin = 9;
void setup() {
  Serial.begin(9600);
}
void loop() {
  int sensorValue = analogRead(A0);
  //Mapping 0-1023 to discrete 0-50-100...250 values for LED
  analogWrite(ledPin, sensorValue * (51.0 / 1024.0) * 50);
  
  if(sensorValue > 0){
     Serial.println(sensorValue);
     Serial.print(" ");
  }
}
>>>>>>> Stashed changes
