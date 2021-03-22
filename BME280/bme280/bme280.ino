
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define LEDY 2
#define LEDN 3
 
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1010) //this is the Sea level in Sunny Beach

Adafruit_BME280 bme;

void setup() {
  pinMode(LEDY, OUTPUT);
  pinMode(LEDN, OUTPUT);   
  Serial.begin(9600);
  Serial.println(F("BME280 test"));

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
    LightIndicationNo();
  }
}

void loop() {
    printValues();
    LightIndicationYes();
    Serial.println();
    delay(1000);
}
void printValues() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
}

void LightIndicationYes() {
   Serial.println();
   digitalWrite(LEDY, HIGH);
        delay(1000);
   digitalWrite(LEDY, LOW);
        delay(1000);
        
}

void LightIndicationNo() {
   digitalWrite(LEDN, HIGH);
        delay(1000);
   digitalWrite(LEDN, LOW);
        delay(1000);
}  



//Temperature = -145.85 *C
//Pressure = 1144.96 hPa
//Approx. Altitude = -1043.01 m
//Humidity = 100.00 %
