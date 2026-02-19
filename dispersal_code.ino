// Pins
const int PUMP_A = 2;   // ITM 1 input
const int PUMP_B = 3;   // ITM 2 input
const int AGIT = 4;     // PWM
const int SERVO_PIN = 5; // PWM
const int SOL = 13 ;     // MOSFET gate

#include <Servo.h>
Servo latch;

void setup(){
  pinMode(PUMP_A, OUTPUT);
  pinMode(PUMP_B, OUTPUT);2
  pinMode(AGIT, OUTPUT);
  pinMode(SOL, OUTPUT);
  latch.attach(SERVO_PIN);
  latch.write(0); // closed
}

void act_washdown(bool on_status, int angle){
    if on_status{
        latch.write(angle);
    }
    else {
        latch.write(0);
    }
}

void loop(){
  // Demo cycle
  digitalWrite(PUMP_B, HIGH);
  delay(5000);
  digitalWrite(PUMP_B, LOW);

  analogWrite(AGIT, 160); // ~63% duty for 3 s
  delay(3000);
  analogWrite(AGIT, 0);

  latch.write(90); // open
  delay(1000);
  latch.write(0);  // close

  digitalWrite(SOL, HIGH); // open solenoid
  delay(5000);
  digitalWrite(SOL, LOW);

  digitalWrite(PUMP_B, HIGH);
  delay(5000);
  digitalWrite(PUMP_B, LOW);
  delay(3000);
}