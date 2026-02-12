#include <ESP8266WiFi.h>
#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi Connected");
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  int pulse = analogRead(A0);

  Serial.print("Temperature: ");
  Serial.println(temp);

  Serial.print("Pulse Raw: ");
  Serial.println(pulse);

  delay(5000);
}
