int ledPins[] = {4, 3, 2, 5};   // LED pins in order (left to right)
int numLeds = 4;                // Number of LEDs
int speed = 150;                // Delay in ms (smaller = faster)

void setup() {
  // Set all LED pins as outputs using a for loop
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  Serial.begin(115200);
  delay(1000);
  Serial.println("LED Chaser started!");
}

void loop() {
  // Run forward: LED 1 -> LED 4
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(speed);
    digitalWrite(ledPins[i], LOW);
  }

  // Run backward: LED 3 -> LED 2 (skip the ends to avoid double blinks)
  for (int i = numLeds - 2; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(speed);
    digitalWrite(ledPins[i], LOW);
  }
}