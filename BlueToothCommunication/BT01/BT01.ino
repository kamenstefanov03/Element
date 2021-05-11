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
Adafruit_BME280 bme;

char valLED;

int AnometerValue = analogRead(A0);

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
    Anometer();
    WeatherPredict();
    testLED();
    delay(1000);
  
    
    }
void printValues() {
    BT.print("Temperature = ");
    BT.print(bme.readTemperature());
    BT.println(" *C");

    BT.print("Pressure = ");
    BT.print(bme.readPressure() / 100.0F);
    BT.println(" hPa");

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

void testLED()
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

void Anometer() 
{
  int anoLED = 9;
  int AnometerValue = analogRead(A0);
  analogWrite(anoLED, AnometerValue * (51.0 / 1023.0) * 50);

  if(AnometerValue == 0)
  {
    BT.println("No wind");
  }
  if(AnometerValue > 0 && AnometerValue <= 70)
  {
    BT.println("Weak wind");
  }
  if(AnometerValue >= 70 && AnometerValue <= 160)
  {
    BT.println("Medium wind");
  }
  if(AnometerValue >= 160 && AnometerValue <= 330)
  {
    BT.println("Strong wind");
  }
}

void WeatherPredict()
{
   float SEALEVELPRESSURE = 0, pres, alt = 595, t, z = 0, SEALEVELPRESSURE_mmHg; // pres- measured pressure, t- temperature in Celsius, alt- altitude in meters(here is for Sofia, Bulgaria)
   char summer;
   char winter;
   t = bme.readTemperature();
   pres = bme.readPressure();
   
   SEALEVELPRESSURE = pres*(1-(0.0065*alt)/(t+0.0065*alt+273.15));
   
   SEALEVELPRESSURE_mmHg = SEALEVELPRESSURE / 133.22; //converting Pascals into mmHg: mmHg = hPa /  133, 322
   
   
   z = 147 - (5*SEALEVELPRESSURE_mmHg/376);
   
   
   // Below are the results 

   
}
