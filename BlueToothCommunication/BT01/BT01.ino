#include <Wire.h>
#include <SPI.h>
#include <SoftwareSerial.h>
//SoftwareSerial BT(2, 3);

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define LEDY 5
#define LEDN 6
#define LEDtest 4
 
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10
#define SEALEVELPRESSURE_HPA (1010) //this is the Sea level in Sunny Beach
Adafruit_BME280 bme;

char valLED;

void setup() {
  Serial.begin(9600);
  pinMode(LEDY, OUTPUT);
  pinMode(LEDN, OUTPUT);
  pinMode(LEDtest, OUTPUT);
  Serial.println("Connected");   
  Serial.println(F("BME280 Session"));

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
    LightIndicationNo();
  }
}

void loop() {
    printValues();
    LightIndicationYes();
    SendData();
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

void SendData()
{
  
if(Serial.available())
    {
      valLED = Serial.read();
    }
    if(valLED == 'H')
    {
      digitalWrite(LEDtest, HIGH);  
    }
    if(valLED == 'L')
    {
      digitalWrite(LEDtest, LOW);  
    }
   //if (BT.available()) 
   //Serial.write(BT.read()); 
   //if (Serial.available()) 
   //BT.write(Serial.read());
}  
