/* Cryoskills Introduction to Arduino
Task 3 - PT1000 Analogue Temperature Sensor
Extension Complete Code */

// Make sure the ADC library is included!
#include "Arduino.h" 
#include <cryo_adc.h>

// initialise variables that we'll use later
float adc_reading; // raw reading from the analogye probe   
float adc_voltage; // reading converted to voltage  
float adc_resistance; // voltage converted to resistanace 
float adc_temp;    // resistance converted to temp
float V_1; // voltage on one side of the wheatstone bridge
float V_2; // voltage on the other side of the wheatstone bridge

// initialise parameters we already know:
float R_1 = 3270;  // measured R1 resistance
float R_2 = 3260;  // measured R2 resistance
float R_3 = 995;   // measured R3 resistance
float V_in = 3.3;  // input voltage

// create probe object. Specify the pins we are connected to, and think about which gain and averaging values will give us the best result
ADCDifferential adc(
  ADCDifferential::INPUT_PIN_POS::A1_PIN,
  ADCDifferential::INPUT_PIN_NEG::A2_PIN,
  ADCDifferential::GAIN::GAIN_8X,
  ADCDifferential::AVERAGES::AVG_X1024);

void setup() {
  Serial.begin(9600);
  adc.begin(); // Initialise the ADCDifferential object
  pinMode(11, OUTPUT); // set pin 11 to output current to our circuit
}

void loop() {
  digitalWrite(11, HIGH); // switch pin 11 on, so we have the voltage from the controller across our circuit 
  adc.enable(); // enable the ADC
  delay(200); // give the ADC some time to settle
  adc_reading = adc.read(); // take the reading from the ADC
  adc.disable(); // disable the ADC
  digitalWrite(11, LOW); //switch pin 11 off again
  Serial.print("Raw reading: "); // print the raw ADC reading
  Serial.println(adc_reading);

  // Convert reading to voltage:
  // the range of readings is from 0 to 32768, and the range of voltages we can measure is 0 to 1
  adc_voltage = (adc_reading / 32768. * 1);

  // print out our voltage to serial
  // n.b, remember the gain and think about units
  Serial.print("Voltage (mV): ");
  Serial.println(adc_voltage * 1000 / 8);

  //convert voltage to resistance:
  V_2 = V_in * (R_3 / (R_3 + R_1));  // find V_2 using the voltage division rule
  V_1 = V_2 + adc_voltage / 8; // find V_1 using our adc voltage (which is the difference between V_1 and V_2)
  adc_resistance = (V_1 * R_1) / (V_in - V_1); // also using voltage division rule, and rearranging for the resistance we want
  
  // Convert from resistance to temperature:
  adc_temp = (adc_resistance - 1000) / 3.986; 

  // print temperature reading:
  Serial.print("Temp (deg C): ");
  Serial.println(adc_temp);
  Serial.println();
}