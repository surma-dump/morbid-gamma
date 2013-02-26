// Duration between trigger presses
// Maximum: 4294967295 ms =~ 50 days
#define TRIGGER_INTERVAL 8000
#define TRIGGER_DURATION 500
// Number of degrees to turn
#define ANGULAR_DISTANCE 15
#define INVERT 0

#define SERVO_PIN 8
#define LED_PIN 13

#define UNTRIGGER_POS (INVERT?ANGULAR_DISTANCE:0)
#define TRIGGER_POS (INVERT?0:ANGULAR_DISTANCE)

#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(UNTRIGGER_POS);
  digitalWrite(LED_PIN, LOW);
}


void loop() {
  while(true) {
    servo.write(TRIGGER_POS);
    digitalWrite(LED_PIN, HIGH);
    delay(TRIGGER_DURATION);
    servo.write(UNTRIGGER_POS);
    digitalWrite(LED_PIN, LOW);
    delay(TRIGGER_INTERVAL);
  }
}
