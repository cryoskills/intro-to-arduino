/* Cryoskills Introduction to Arduino
Task 3 - PT1000 Analogue Temperature Sensor
Extension Skeleton Code */

// Make sure the ADC library is included!
#include "Arduino.h" 

// initialise variables that we'll use later
float adc_reading; // raw reading from the analogue probe   
float adc_voltage; // reading converted to voltage  
float adc_resistance; // voltage converted to resistanace 
float adc_temp;    // resistance converted to temp
float V_1; // voltage on one side of the wheatstone bridge
float V_2; // voltage on the other side of the wheatstone bridge

// initialise parameters we already know:
float R_1 = 3300;  // measured R1 resistance
float R_2 = 3300;  // measured R2 resistance
float R_3 = 1000;   // measured R3 resistance
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
  // set pin 11 to output current to our circuit
}

void loop() {
  // switch pin 11 on, so we have the voltage from the controller across our circuit 
  adc.enable(); // enable the ADC
  delay(200); // give the ADC some time to settle
  adc_reading = adc.read(); // take the reading from the ADC
  adc.disable(); // disable the ADC
  digitalWrite(11, LOW); //switch pin 11 off again
  // print the raw ADC reading
 

  // Convert reading to voltage:
  // the range of readings is from 0 to 32768, and the range of voltages we can measure is 0 to 1


  // print out our voltage to serial
  // n.b, remember the gain and think about units


  //convert voltage to resistance:
  // find V_2 using the voltage division rule
  // find V_1 using our adc voltage (which is the difference between V_1 and V_2)
  // also using voltage division rule, and rearranging for the resistance we want
  
  // Convert from resistance to temperature:
  adc_temp = (adc_resistance - 1000) / 3.986;  

  // print temperature reading:

}