const int RED_LED = 8;
const int GREEN_LED = 9;
const int LDR_PIN = A0;

const int THRESHOLD = 512;
const unsigned long OPEN_TIME = 5000;

bool doorOpen = false;
unsigned long openStart = 0;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.println("Start");
  Serial.begin(9600);

  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);

  Serial.println("Door closed");
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);

  if (!doorOpen && ldrValue > THRESHOLD) {

    doorOpen = true;
    openStart = millis();

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    Serial.println("Door opened");
  }

  if (doorOpen) {

    if (millis() - openStart >= OPEN_TIME) {

      ldrValue = analogRead(LDR_PIN);

      if (ldrValue > THRESHOLD) {

        openStart = millis();

      } else {

        doorOpen = false;

        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);

        Serial.println("Door closed");
      }
    }
  }
}
