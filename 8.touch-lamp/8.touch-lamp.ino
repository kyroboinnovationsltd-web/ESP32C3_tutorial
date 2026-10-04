#define TOUCH_PIN 10
#define LED_PIN   5

bool ledState = false;          // Is the lamp on or off?
bool lastTouchState = LOW;      // Touch state from the previous loop

void setup() {
  pinMode(TOUCH_PIN, INPUT);    // The module drives the pin, so no pull-up needed
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
  delay(1000);
  Serial.println("Touch Lamp ready!");
}

void loop() {
  bool touchState = digitalRead(TOUCH_PIN);

  // Detect the moment of touching (LOW -> HIGH)
  if (touchState == HIGH && lastTouchState == LOW) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    Serial.println(ledState ? "Lamp ON" : "Lamp OFF");
  }

  lastTouchState = touchState;
  delay(20);
}
