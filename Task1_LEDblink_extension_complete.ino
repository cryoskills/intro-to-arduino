/* Cryoskills Introduction to Arduino
Task 1 - LED Blink
Extension Code */

const int LEDpin_red = 10; // Set the red LED to pin 10
const int LEDpin_yellow = 11; // Set the yellow LED to pin 11
const int LEDpin_green = 12; // Set the green LED to pin 12

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize LEDpins as outputs
  pinMode(LEDpin_red, OUTPUT);
  pinMode(LEDpin_yellow, OUTPUT);
  pinMode(LEDpin_green, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LEDpin_red, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(5000);                     // red LED on for 5 seconds
  digitalWrite(LEDpin_red, LOW);   // turn the LED off by making the voltage LOW

  digitalWrite(LEDpin_yellow, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                        // yellow LED on for a second
  digitalWrite(LEDpin_yellow, LOW);   // turn the LED off by making the voltage LOW

  digitalWrite(LEDpin_green, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(10000);                      // green LED on for 10 seconds
  digitalWrite(LEDpin_green, LOW);   // turn the LED off by making the voltage LOW
}