#define LED_PIN 8

void setup() {
  pinMode(LED_PIN, OUTPUT);   // Set the LED pin as an output
  Serial.begin(115200);       // Start Serial Monitor
  delay(1000);
  Serial.println("ESP32-C3 Blink started!");
}

void loop() {
  digitalWrite(LED_PIN, LOW);   // LED ON (active-low)
  Serial.println("LED ON");
  delay(1000);                  // Wait 1 second

  digitalWrite(LED_PIN, HIGH);  // LED OFF
  Serial.println("LED OFF");
  delay(1000);                  // Wait 1 second
}
