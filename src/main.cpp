#include <Arduino.h>
#include <DHT.h>

#define CAPTEUR 33
#define LED 26
#define DHTTYPE DHT11

#define TIME_TO_SLEEP 5

#define uS_TO_S_FACTOR 1000000ULL

DHT dht(CAPTEUR, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  
  dht.begin();
  
  delay(2000);
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  Serial.print("Humidité: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  Serial.print("Température: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  Serial.println("-------------------");
  
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  
  Serial.println("Passage en mode Deep Sleep pour 5 secondes...");
  Serial.flush(); 
  
  esp_deep_sleep_start();
}

void loop() {

}
