#include <Arduino.h>
#include <DHT.h>

// Define the pins that we will use
#define CAPTEUR 33
#define LED 26
#define DHTTYPE DHT11

DHT dht(CAPTEUR, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  dht.begin();
}

void loop() {
  // Effectuer une mesure toutes les 5s
  delay(5000);
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  // Afficher l'humidité relative avec un peu de formatage
  Serial.print("Humidité: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  // Afficher la température avec un peu de formatage
  Serial.print("Température: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  Serial.println("-------------------");
}
