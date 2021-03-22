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
