/* Cryoskills Introduction to Arduino
Task 3 - PT1000 Analogue Temperature Sensor
Complete Code */

// initialise constants and variables:
const int ResistorPin = 11; // R1 is connected to D11
const int PT1000Pin = A1; // PT1000 is connected to A1
const int R1 = 3300; // R1 is a fixed resistor equal to 3300 Ohms

float RTD_ADC; // Raw ADC reading from the analogue probe
float RTD_Voltage; // ADC reading converted to voltage
float RTD_Resistance; // Voltage converted to resistance
float RTD_Temp; // Resistance converted to temperature

void setup() {
  pinMode(ResistorPin, OUTPUT); // Sets the resistor as an output
  pinMode(PT1000Pin, INPUT); // Sets the PT1000 as an input
  Serial.begin(9600); // Sets the baud rate (serial communication at 9600 bits of data per second)
}

void loop() {
  digitalWrite(ResistorPin, HIGH); // Set the resistor to high

  RTD_ADC = analogRead(PT1000Pin); // Read the ADC measurement of the PT1000
  Serial.print("ADC: ");
  Serial.println(RTD_ADC); // Prints the ADC measurement to the serial monitor 

  RTD_Voltage = RTD_ADC * (3.3 / 1023.0); // Calculation to convert ADC to voltage
  Serial.print("Voltage: ");
  Serial.println(RTD_Voltage); // Prints the RTD voltage

  RTD_Resistance = (RTD_Voltage/(3.3 - RTD_Voltage)) * R1; // Calculates the RTD resistance
  RTD_Temp = (RTD_Resistance - 1000) / 3.986; // Calculates the correpsonding RTD temperature

  Serial.print("Temperature: ");
  Serial.println(RTD_Temp); // Prints the RTD temperature

  digitalWrite(ResistorPin, LOW); // Set the resistor to low

  delay(1000); // 1 second delay
}

