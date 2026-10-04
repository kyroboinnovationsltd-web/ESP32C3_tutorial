#define POT_PIN 0    // Potentiometer middle pin
#define LED_PIN 5    // LED through a resistor

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
  delay(1000);
  Serial.println("LED Dimmer started!");
}

void loop() {
  int potValue = analogRead(POT_PIN);                 // 0 to 4095
  int brightness = map(potValue, 0, 4095, 0, 255);    // Convert to 0 to 255

  analogWrite(LED_PIN, brightness);                   // Set LED brightness

  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print("  Brightness: ");
  Serial.println(brightness);

  delay(50);
}