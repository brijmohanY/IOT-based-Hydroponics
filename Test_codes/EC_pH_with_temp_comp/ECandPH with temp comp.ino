

#include "DFRobot_PH.h"
#include "DFRobot_EC.h"
#include <EEPROM.h>
#include "DHT.h"

#define PH_PIN A1
#define EC_PIN A2
#define DHTPIN 4    
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
float  voltagePH,voltageEC,phValue,ecValue,temperature = 25;
DFRobot_PH ph;
DFRobot_EC ec;

void setup()
{
    Serial.begin(9600);  
    ph.begin();
    ec.begin();
    dht.begin();
}

void loop()
{
    char cmd[10];
    static unsigned long timepoint = millis();
    if(millis()-timepoint>1000U){                            //time interval: 1s
        timepoint = millis();
        temperature = readTemperature();                   // read your temperature sensor to execute temperature compensation
        voltagePH = analogRead(PH_PIN)/1024.0*5000;          // read the ph voltage
        phValue    = ph.readPH(voltagePH,temperature);       // convert voltage to pH with temperature compensation
        Serial.print("pH:");
        Serial.print(phValue,2);
        voltageEC = analogRead(EC_PIN)/1024.0*5000;
        ecValue    = ec.readEC(voltageEC,temperature);       // convert voltage to EC with temperature compensation
        Serial.print(", EC:");
        Serial.print(ecValue,2);
        Serial.println("ms/cm");
    }
    if(readSerial(cmd)){
        strupr(cmd);
        if(strstr(cmd,"PH")){
            ph.calibration(voltagePH,temperature,cmd);       //PH calibration process by Serail CMD
        }
        if(strstr(cmd,"EC")){
            ec.calibration(voltageEC,temperature,cmd);       //EC calibration process by Serail CMD
        }
    }
}

int i = 0;
bool readSerial(char result[]){
    while(Serial.available() > 0){
        char inChar = Serial.read();
        if(inChar == '\n'){
             result[i] = '\0';
             Serial.flush();
             i=0;
             return true;
        }
        if(inChar != '\r'){
             result[i] = inChar;
             i++;
        }
        delay(1);
    }
    return false;
}

float readTemperature()
{
  //Add code for any TEMP sensor for TEMP compatation here i used DHT-22 but water temp can vary from surrounding
  //its just for example

   float t = dht.readTemperature();
   Serial.println(F("%  Temperature: "));
   Serial.print(t);
   Serial.print(F("°C "));
   return t;
}