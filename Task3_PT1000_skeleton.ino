/* Cryoskills Introduction to Arduino
Task 3 - PT1000 Analogue Temperature Sensor
Skeleton Code */

// initialise constants and variables:
const int ResistorPin = 11; // R1 is connected to D11
const int PT1000Pin = A1; // PT1000 is connected to A1
// R1 is a fixed resistor equal to ... Ohms

float PT1000_ADC; // Raw ADC reading from the analogue probe
float PT1000_voltage; // Volatge of analogue probe (converted from raw ADC reading)
float PT1000_res; // Resistance (converted from voltage)
float PT1000_temp; // Temperature (converted from resistance)

void setup() {
  // Sets the resistor as an output
  // Sets the PT1000 as an input
  Serial.begin(9600); // Sets the baud rate (serial communication at 9600 bits of data per second)
}

void loop() {
  // Sets the resistor to high

  // Reads the ADC measurement of the PT1000 analogue sensor
  // Prints the ADC measurement to the serial monitor 

  // Calculation to convert ADC reading to voltage
  // Prints the analogue voltage

  // Calculates the analogue resistance
  // Calculates the correpsonding analogue temperature
  // Prints the analogue temperature

  // Sets the resistor to low

  delay(1000); // 1 second delay
}

