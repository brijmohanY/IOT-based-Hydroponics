#include "DFRobot_EC.h"
#include <EEPROM.h>
#include "DHT.h"

float voltage,ecValue,temperature = 25;
DFRobot_EC ec;
#define EC_PIN A0
#define DHTPIN D4    
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);  
  ec.begin();
}

void loop()
{
    static unsigned long timepoint = millis();
    if(millis()-timepoint>1000U)  //time interval: 1s
    {
      timepoint = millis();
      voltage = analogRead(EC_PIN)/1024.0*5000;   // read the voltage
      //temperature = readTemperature();          // temperature compensation
      ecValue =  ec.readEC(voltage,temperature);  // convert voltage to EC with temperature compensation
      Serial.print("temperature:");
      Serial.print(temperature,1);
      Serial.print("^C  EC:");
      Serial.print(ecValue,2);
      Serial.println("ms/cm");
    }
    ec.calibration(voltage,temperature);          // calibration process by Serail CMD
}

float readTemperature()
{
  //Add code for any TEMP sensor for TEMP compatation here i used DHT-22 but water temp can vary from surrounding
  //its just for example
//
//   float t = dht.readTemperature();
//   Serial.println(F("%  Temperature: "));
//   Serial.print(t);
//   Serial.print(F("°C "));
//   return t;
}
