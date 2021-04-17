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
  analogWrite(anoLED, AnometerValue * (51.0 / 1023.0) * 50);

  if(AnometerValue > 0)
  {
    BT.println(AnometerValue);
    BT.print("");
  }
  /*if(AnometerValue <= 30)
  {
    BT.println("Weak wind");
  }*/

}

void WeatherPredict()
{
   double SEALEVELPRESSURE = 0, pres, alt = 595, t, z = 0; // pres- measured pressure, t- temperature in Celsius, alt- altitude in meters(here is for Sofia, Bulgaria)
   char summer;
   char winter;
   t = bme.readTemperature();
   pres = bme.readPressure();
   BT.println(SEALEVELPRESSURE);
   SEALEVELPRESSURE = pres*(1-(0.0065*alt)/(t+0.0065*alt+273.15));
   BT.println(SEALEVELPRESSURE);
   double SEALEVELPRESSUREOK = pow(SEALEVELPRESSURE, -5.275);
   BT.println(SEALEVELPRESSUREOK);
   z = 147 - (5*SEALEVELPRESSUREOK/376);
   BT.println(z);
   
   // Below are the results 

   if(z == 1)
   {
    BT.println("Settled Fine");
   }
   else if(z == 2)
   {
    BT.println("Fine Weather");
   }
   else if(z == 3)
   {
    BT.println("Fine Becoming Less Settled");
   }
   else if(z == 4)
   {
    BT.println("");
   }
   else if(z == 5)
   {
    BT.println("");
   }
   else if(z == 6)
   {
    BT.println("");
   }
   else if(z == 7)
   {
    BT.println("");
   }
   else if(z == 8)
   {
    BT.println("");
   }
   else if(z == 9)
   {
    BT.println("");
   }
   else if(z == 10)
   {
    BT.println("");
   }
   else if(z == 11)
   {
    BT.println("");
   }
   else if(z == 12)
   {
    BT.println("");
   }
   else if(z == 13)
   {
    BT.println("");
   }
   else if(z == 14)
   {
    BT.println("");
   }
   else if(z == 15)
   {
    BT.println("");
   }
   else if(z == 16)
   {
    BT.println("");
   }
   else if(z == 17)
   {
    BT.println("");
   }
   else if(z == 18)
   {
    BT.println("");
   }
   else if(z == 19)
   {
    BT.println("");
   }
   else if(z == 20)
   {
    BT.println("");
   }
   else if(z == 21)
   {
    BT.println("");
   }
   else if(z == 22)
   {
    BT.println("");
   }
   else if(z == 23)
   {
    BT.println("");
   }
   else if(z == 24)
   {
    BT.println("");
   }
   else if(z == 25)
   {
    BT.println("");
   }
   else if(z == 26)
   {
    BT.println("");
   }
   else if(z == 27)
   {
    BT.println("");
   }
   else if(z == 28)
   {
    BT.println("");
   }
   else if(z == 29)
   {
    BT.println("");
   }
   else if(z == 30)
   {
    BT.println("");
   }
   else if(z == 31)
   {
    BT.println("");
   }
   else if(z == 32)
   {
    BT.println("");
   }
   else
   {
    BT.println("There is somethimg wrong. Check your BME sensor!");   
   }
}
