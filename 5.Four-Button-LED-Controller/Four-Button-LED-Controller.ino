int ledPins[]    = {4, 3, 2, 5};   // Red, Yellow, Green, Blue
int buttonPins[] = {0, 1, 6, 7};   // Button 1, 2, 3, 4
const int NUM = 4;

String names[] = {"Red", "Yellow", "Green", "Blue"};

bool ledState[NUM]        = {false, false, false, false};
bool lastButtonState[NUM] = {HIGH, HIGH, HIGH, HIGH};
unsigned long lastPressTime[NUM] = {0, 0, 0, 0};
const int debounceDelay = 50;

void setup() {
  for (int i = 0; i < NUM; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  Serial.begin(115200);
  delay(1000);
  Serial.println("Four-Button LED Controller started!");
}

void loop() {
  // Check every button, one after another
  for (int i = 0; i < NUM; i++) {
    bool buttonState = digitalRead(buttonPins[i]);

    if (buttonState == LOW && lastButtonState[i] == HIGH) {
      if (millis() - lastPressTime[i] > debounceDelay) {
        ledState[i] = !ledState[i];
        digitalWrite(ledPins[i], ledState[i]);

        Serial.print(names[i]);
        Serial.println(ledState[i] ? " LED ON" : " LED OFF");

        lastPressTime[i] = millis();
      }
    }

    lastButtonState[i] = buttonState;
  }
}