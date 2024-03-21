/* Cryoskills Introduction to Arduino
Task 1 - LED Blink
Complete Code */

const int LEDpin = 10; // Set the LED to pin 10

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize LEDpin as an output.
  pinMode(LEDpin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LEDpin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(5000);                 // wait for 5 seconds
  digitalWrite(LEDpin, LOW);   // turn the LED off by making the voltage LOW
  delay(2000);                 // wait for 2 seconds
}