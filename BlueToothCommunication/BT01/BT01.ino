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
  if(AnometerValue <= 30)
  {
    BT.println("Weak wind");
  }
  if(AnometerValue >= 30 && AnometerValue <= 120)
  {
    BT.println("Medium wind");
  }
  if(AnometerValue >= 120 && AnometerValue <= 170)
  {
    BT.println("Strong wind");
  }
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
    BT.println("Fairly Fine Showery Later");
   }
   else if(z == 5)
   {
    BT.println("Showery Becoming more unsettled");
   }
   else if(z == 6)
   {
    BT.println("Unsettled, Rain later");
   }
   else if(z == 7)
   {
    BT.println("Rain at times, worse later.");
   }
   else if(z == 8)
   {
    BT.println("Rain at times, becoming very unsettled");
   }
   else if(z == 9)
   {
    BT.println("Very Unsettled, Rain");
   }
   else if(z == 10)
   {
    BT.println("Settled Fine");
   }
   else if(z == 11)
   {
    BT.println("Fine Weather");
   }
   else if(z == 12)
   {
    BT.println("Fine, Possibly showers");
   }
   else if(z == 13)
   {
    BT.println("Fairly Fine, Showers likely");
   }
   else if(z == 14)
   {
    BT.println("Showery Bright Intervals");
   }
   else if(z == 15)
   {
    BT.println("Changeable some rain");
   }
   else if(z == 16)
   {
    BT.println("Unsettled, rain at times");
   }
   else if(z == 17)
   {
    BT.println("Rain at Frequent Intervals");
   }
   else if(z == 18)
   {
    BT.println("Very Unsettled, Rain");
   }
   else if(z == 19)
   {
    BT.println("Stormy, much rain");
   }
   else if(z == 20)
   {
    BT.println("Settled Fine");
   }
   else if(z == 21)
   {
    BT.println("Fine Weather");
   }
   else if(z == 22)
   {
    BT.println("Becoming Fine");
   }
   else if(z == 23)
   {
    BT.println("Fairly Fine, Improving");
   }
   else if(z == 24)
   {
    BT.println("Fairly Fine, Possibly showers, early");
   }
   else if(z == 25)
   {
    BT.println("Showery Early, Improving");
   }
   else if(z == 26)
   {
    BT.println("Changeable Mending");
   }
   else if(z == 27)
   {
    BT.println("Rather Unsettled Clearing Later");
   }
   else if(z == 28)
   {
    BT.println("Unsettled, Probably Improving");
   }
   else if(z == 29)
   {
    BT.println("Unsettled, short fine Intervals");
   }
   else if(z == 30)
   {
    BT.println("Very Unsettled, Finer at times");
   }
   else if(z == 31)
   {
    BT.println("Stormy, possibly improving");
   }
   else if(z == 32)
   {
    BT.println("Stormy, much rain");
   }
   else
   {
    BT.println("There is somethimg wrong. Check your BME sensor!");   
   }
}
