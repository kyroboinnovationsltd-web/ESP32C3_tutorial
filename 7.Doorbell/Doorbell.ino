#define BUTTON_PIN 10
#define BUZZER_PIN 6

// Musical notes (frequency in Hz)
#define NOTE_E5 659
#define NOTE_C5 523

bool lastButtonState = HIGH;
unsigned long lastPressTime = 0;
const int debounceDelay = 50;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(115200);
  delay(1000);
  Serial.println("Doorbell ready!");
}

// Play the ding-dong tune
void playDoorbell() {
  tone(BUZZER_PIN, NOTE_E5);   // Ding
  delay(400);
  tone(BUZZER_PIN, NOTE_C5);   // Dong
  delay(600);
  noTone(BUZZER_PIN);          // Stop the sound
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && lastButtonState == HIGH) {
    if (millis() - lastPressTime > debounceDelay) {
      Serial.println("Ding-dong! Someone is at the door.");
      playDoorbell();
      lastPressTime = millis();
    }
  }

  lastButtonState = buttonState;
}