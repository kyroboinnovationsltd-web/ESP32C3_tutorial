#define POT_PIN 0

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  int potValue = analogRead(POT_PIN);   // 0 to 4095
  Serial.println(potValue);
  delay(100);
}
