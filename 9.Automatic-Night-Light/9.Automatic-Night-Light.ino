#define LDR_PIN 1    
#define LED_PIN 5    

// Adjust these to suit your room (check the light level in the Serial Monitor)
const int DARK_LEVEL  = 150;   // Turn the light ON below this
const int LIGHT_LEVEL = 250;   // Turn the light OFF above this

bool lightOn = false;          // Is the night light on or off?

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(115200);
  delay(1000);
  Serial.println("Automatic Night Light ready!");
}

void loop() {
  int lightValue = analogRead(LDR_PIN);   // 0 (dark) to 4095 (bright)

  // Dark: turn the light ON
  if (!lightOn && lightValue < DARK_LEVEL) {
    lightOn = true;
    digitalWrite(LED_PIN, HIGH);
    Serial.println("It's dark - Night light ON");
  }
  // Bright: turn the light OFF
  else if (lightOn && lightValue > LIGHT_LEVEL) {
    lightOn = false;
    digitalWrite(LED_PIN, LOW);
    Serial.println("It's bright - Night light OFF");
  }

  Serial.print("Light level: ");
  Serial.println(lightValue);
  delay(200);
}