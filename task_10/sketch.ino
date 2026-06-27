#include <Servo.h>

Servo servo;

const int SERVO_PIN = 9;
int currentAngle = 90;

void setup() {
  Serial.begin(9600);

  servo.attach(SERVO_PIN);
  servo.write(currentAngle);

  Serial.println("Введите угол от 0 до 180:");
}

void loop() {
  if (Serial.available()) {

    String input = Serial.readStringUntil('\n');
    input.trim();

    bool valid = true;

    if (input.length() == 0) {
      valid = false;
    }

    for (int i = 0; i < input.length(); i++) {
      if (!isDigit(input[i])) {
        valid = false;
        break;
      }
    }

    if (!valid) {
      Serial.println("Ошибка! Введите число от 0 до 180.");
      return;
    }

    int angle = input.toInt();

    if (angle < 0 || angle > 180) {
      Serial.println("Ошибка! Диапазон 0...180.");
      return;
    }

    if (angle != currentAngle) {

      if (angle > currentAngle) {
        for (int pos = currentAngle; pos <= angle; pos++) {
          servo.write(pos);
          delay(15);
        }
      } else {
        for (int pos = currentAngle; pos >= angle; pos--) {
          servo.write(pos);
          delay(15);
        }
      }

      currentAngle = angle;

      Serial.print("Новый угол: ");
      Serial.println(currentAngle);
    }
  }
}
