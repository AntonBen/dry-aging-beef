
#include "DHT.h"

#define DHTPIN 14

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int RELAY_PIN = 16;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(RELAY_PIN, OUTPUT);

  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();


  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  if (h < 50) {
    digitalWrite(RELAY_PIN, HIGH);
  }

  if (h > 70) {
    digitalWrite(RELAY_PIN, LOW);
  }

  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(hic);
  Serial.print(F("°C "));
  delay(2000);
}