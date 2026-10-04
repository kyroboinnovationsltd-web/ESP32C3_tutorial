#define LED_PIN    5
#define BUTTON_PIN 10

bool ledState = false;          // Is the LED on or off?
bool lastButtonState = HIGH;    // Button state from the previous loop
unsigned long lastPressTime = 0;
const int debounceDelay = 50;   // Ignore bounces shorter than 50 ms

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(115200);
  delay(1000);
  Serial.println("Push Button LED started!");
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  // Detect the moment the button goes from not-pressed to pressed
  if (buttonState == LOW && lastButtonState == HIGH) {
    if (millis() - lastPressTime > debounceDelay) {
      ledState = !ledState;                 // Flip the LED state
      digitalWrite(LED_PIN, ledState);
      Serial.println(ledState ? "LED ON" : "LED OFF");
      lastPressTime = millis();
    }
  }

  lastButtonState = buttonState;
}