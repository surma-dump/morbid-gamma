// Abstaende zwischen Ausloesern in Millisekunden
// Maximum 4294967295 =~ 49 Tage
#define PRESS_INTERVAL 8000
#define PRESS_DURATION 500

#define SERVO_PIN 8
#define LED_PIN 13

#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(0);
  digitalWrite(LED_PIN, LOW);
}


void loop() {
  while(true) {
    servo.write(45);
    digitalWrite(LED_PIN, HIGH);
    delay(PRESS_DURATION);
    servo.write(0);
    digitalWrite(LED_PIN, LOW);
    delay(PRESS_INTERVAL);
  }
}
