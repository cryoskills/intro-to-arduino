/* Cryoskills Introduction to Arduino
Task 3 - PT1000 Analogue Temperature Sensor
Complete Code */

// initialise constants and variables:
const int ResistorPin = 11; // R1 is connected to D11
const int PT1000Pin = A1; // PT1000 is connected to A1
const int R1 = 3300; // R1 is a fixed resistor equal to 3300 Ohms - you may have selected a different resistor which is okay

float analogue_ADC; // Raw ADC reading from the analogue probe
float analogue_voltage; // Volatge of analogue probe (converted from raw ADC reading)
float analogue_res; // Resistance (converted from voltage)
float analogue_temp; // Temperature (converted from resistance)

void setup() {
  pinMode(ResistorPin, OUTPUT); // Sets the resistor as an output
  pinMode(PT1000Pin, INPUT); // Sets the PT1000 as an input
  Serial.begin(9600); // Sets the baud rate (serial communication at 9600 bits of data per second)
}

void loop() {
  digitalWrite(ResistorPin, HIGH); // Set the resistor to high

  analogue_ADC = analogRead(PT1000Pin); // Read the ADC measurement of the PT1000 analogue sensor
  Serial.print("ADC: ");
  Serial.println(analogue_ADC); // Prints the ADC measurement to the serial monitor 

  analogue_voltage = analogue_ADC * (3.3 / 1023.0); // Calculation to convert ADC to voltage
  Serial.print("Voltage: ");
  Serial.println(analogue_voltage); // Prints the analogue voltage

  analogue_res = (analogue_voltage/(3.3 - analogue_voltage)) * R1; // Calculates the analogue resistance
  analogue_temp = (analogue_res - 1000) / 3.986; // Calculates the correpsonding analogue temperature

  Serial.print("Temperature: ");
  Serial.println(analogue_temp); // Prints the analogue temperature

  digitalWrite(ResistorPin, LOW); // Set the resistor to low

  delay(1000); // 1 second delay
}

