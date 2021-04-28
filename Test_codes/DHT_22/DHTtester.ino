#include "DHT.h"
#include <ESP8266WiFi.h>

#define DHTPIN D4    
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);   // becoz dht sensor has 1 sec of response time so to be on safe side

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!")); // if reading is not available
    return;
  }
  //float hic = dht.computeHeatIndex(t, h, false);  // it can also measure Heat Index

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  //Serial.println(F("°F  Heat index: "));
  //Serial.print(hic);
  //Serial.print(F("°C "));
  
}
