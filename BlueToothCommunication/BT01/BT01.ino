#include <Wire.h>
#include <SPI.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3);

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
  BT.begin(9600);
  pinMode(LEDY, OUTPUT);
  pinMode(LEDN, OUTPUT);
  pinMode(LEDtest, OUTPUT);
  BT.println("Connected");   
  BT.println(F("BME280 Session"));

  if (!bme.begin()) {
    BT.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
    LightIndicationNo();
  }
}

void loop() {
    printValues();
    LightIndicationYes();
    BT.println();
    SendData();
    delay(1000);
    
    }
void printValues() {
    BT.print("Temperature = ");
    BT.print(bme.readTemperature());
    BT.println(" *C");

    BT.print("Pressure = ");
    BT.print(bme.readPressure() / 100.0F);
    BT.println(" hPa");

    BT.print("Approx. Altitude = ");
    BT.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    BT.println(" m");

    BT.print("Humidity = ");
    BT.print(bme.readHumidity());
    BT.println(" %");

    BT.println();
}

void LightIndicationYes() {
   BT.println();
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
if(BT.available())
    {
      valLED = BT.read();
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
