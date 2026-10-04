#define LED_PIN    5
#define BUTTON_PIN 10

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Button reads HIGH normally, LOW when pressed
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {   // Button pressed
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}