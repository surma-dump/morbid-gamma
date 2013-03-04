// Duration between trigger presses
// Maximum: 4294967295 ms =~ 50 days
#define TRIGGER_INTERVAL 0
#define TRIGGER_DURATION 500
// Number of degrees to turn
#define ANGULAR_DISTANCE 25
#define INVERT 1
#define ACTIVE_ZONE_START 15

#define SERVO_PIN 12
#define LED_PIN 13

#define UNTRIGGER_POS (ACTIVE_ZONE_START + (INVERT?ANGULAR_DISTANCE:0))
#define TRIGGER_POS (ACTIVE_ZONE_START + (INVERT?0:ANGULAR_DISTANCE))

#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(UNTRIGGER_POS);
  digitalWrite(LED_PIN, LOW);
}


void loop() {
  // Stopping mechanism
  while(TRIGGER_INTERVAL == 0);
  while(true) {
    servo.write(TRIGGER_POS);
    digitalWrite(LED_PIN, HIGH);
    delay(TRIGGER_DURATION);
    servo.write(UNTRIGGER_POS);
    digitalWrite(LED_PIN, LOW);
    delay(TRIGGER_INTERVAL);
  }
}
