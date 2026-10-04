#define RED_LED    4
#define YELLOW_LED 3
#define GREEN_LED  2

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(115200);
  delay(1000);
  Serial.println("Traffic Light started!");
}

// Turn on one LED and switch off the others
void setLights(bool red, bool yellow, bool green) {
  digitalWrite(RED_LED, red);
  digitalWrite(YELLOW_LED, yellow);
  digitalWrite(GREEN_LED, green);
}

void loop() {
  setLights(HIGH, LOW, LOW);    // RED - Stop
  Serial.println("RED - Stop");
  delay(5000);

  setLights(LOW, LOW, HIGH);    // GREEN - Go
  Serial.println("GREEN - Go");
  delay(5000);

  setLights(LOW, HIGH, LOW);    // YELLOW - Get ready to stop
  Serial.println("YELLOW - Slow down");
  delay(2000);
}