#include <DHT.h>

#define DHT_PIN   7        // DHT11 data pin
#define DHT_TYPE  DHT11    // Sensor type
#define LED_PIN   5        // Warning LED through 330 ohm resistor

const float TEMP_LIMIT = 32.0;   // Turn on the warning LED above this (°C)

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  dht.begin();

  Serial.begin(115200);
  delay(1000);
  Serial.println("Temperature & Humidity Monitor ready!");
}

void loop() {
  delay(2000);   // The DHT11 needs about 2 seconds between readings

  float humidity    = dht.readHumidity();
  float temperature = dht.readTemperature();   // Celsius

  // Check if the reading failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT11 sensor! Check the wiring.");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C   Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Warning LED
  if (temperature > TEMP_LIMIT) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Warning: It's too hot!");
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}