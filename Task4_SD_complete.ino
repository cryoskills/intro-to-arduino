
/* Cryoskills Introduction to Arduino
Task 4 - Saving digital and analogue temperature measurements to an SD card
Complete Code */

// Add libraries (SD card, temperature sensors, cryo):
#include <SD.h>
#include <SPI.h> 
#include <DS18B20.h>  // open-source library for using the DS temperature sensor: https://github.com/matmunk/DS18B20
#include <OneWire.h>
#include <cryo_sleep.h>
#include <cryo_adc.h>

// Initialise variables:
// SD card variables:
#define cardSelect 4  // set the pin used by the SD card
File logfile;  // file for logging data to

// Real-time clock variables (Task 4.2):
PseudoRTC* my_rtc; // Pointer to the real-time clock

// Digital Temperature variables (Task 4.3):
DS18B20 ds(5); // DS18B20 is connected to pin 5 (D5)
float digital_temp; // DS probe temperature measurement

// Analogue Temperature variables (Task 4.4):
const int ResistorPin = 11; // R1 is connected to D11
const int PT1000Pin = A1; // PT1000 is connected to A1
const int R1 = 3300; // R1 is a fixed resistor equal to 3300 Ohms - you may have selected a different resistor which is okay
float analogue_ADC; // Raw ADC reading from the analogue probe
float analogue_voltage; // Volatge of analogue probe (converted from raw ADC reading)
float analogue_res; // Resistance (converted from voltage)
float analogue_temp; // Temperature (converted from resistance)

// Initialise functions:
void setup_sd();   // set up the SD card to log data to a file
void write_to_sd();  // write data to file
float get_ds18b20_temperature();   // fucntion to get a digital temperature, return it as a float
float get_pt1000_temperature(); // function to get a analogue temperature, return it as a float

// Setup loop (runs once):
void setup() {
  Serial.begin(9600); // open serial connection
  setup_sd(); // Sets up SD card
  cryo_configure_clock(__DATE__,__TIME__); // Configures the RTC
  pinMode(ResistorPin, OUTPUT); // Sets the resistor as an output
  pinMode(PT1000Pin, INPUT); // Sets the PT1000 as an input
}

// Main loop (runs repeatedly):
void loop() {
  // call temperature functions (Task 4.3 and 4.4):
  digital_temp = get_ds18b20_temperature(); // Digital temperature from the function below
  analogue_temp = get_pt1000_temperature(); // Analogue temperature from the function below

  write_to_sd(); 
  delay(1000); // Delay to make sure everything goes smoothly
}

// Get digital temperature function (Task 4.3):
float get_ds18b20_temperature() {
  while (ds.selectNext()) {
    Serial.print("Digital Temperature: ");
    digital_temp = ds.getTempC();
    Serial.print(digital_temp);
    Serial.println(" deg C");
  }
  return digital_temp;
}

// Get analogue temperature function (Task 4.4):
float get_pt1000_temperature(){
  digitalWrite(ResistorPin, HIGH); // Set the resistor to high

  analogue_ADC = analogRead(PT1000Pin); // Read the ADC measurement of the PT1000
  analogue_voltage = analogue_ADC * (3.3 / 1023.0); // Calculation to convert ADC to voltage
  analogue_res = (analogue_voltage/(3.3 - analogue_voltage)) * R1; // Calculates the RTD resistance
  analogue_temp = (analogue_res - 1000) / 3.986; // Calculates the correpsonding RTD temperature

  Serial.print("Analogue Temperature: ");
  Serial.print(analogue_temp); // Prints the analogue temperature
  Serial.println(" deg C");

  digitalWrite(ResistorPin, LOW); // Set the resistor to low
  return analogue_temp;
}

// Set up the SD card for writing:
void setup_sd() {
  Serial.println("setting up SD!");
  if (!SD.begin(cardSelect)) {    //check that SD card is working ok
     Serial.println("Card init. failed!");
  }

// Give the log file a name:
 char filename[10];       
 strcpy(filename, "Log00.txt");
 for (uint8_t i = 0; i < 100; i++) {  // give it the next available filename
   filename[3] = '0' + i/10;
   filename[4] = '0' + i%10;
   if (!SD.exists(filename)) {
     break;
   }
 }

  // Open the file for writing:
  logfile = SD.open(filename, FILE_WRITE);
  Serial.print("Writing to "); 
  Serial.println(filename);

  // Write a header:
  logfile.println("Temperature data from Cryoskills sensor kit, degrees C");
  logfile.println("Timestamp\tDigital probe\tAnalog probe"); // Time and temp x2 header

  pinMode(8, OUTPUT); 
  Serial.println("Ready!");
}

// Write data to the SD card:
void write_to_sd() {
  digitalWrite(8, HIGH);   // set pin 8 to write
  Serial.println("writing!");  // announce that we are writing to the SD card

  // Get time from the RTC, and print to the logfile (Task 4.2):
  my_rtc = cryo_get_rtc(); 
  logfile.printf(
    "%04d-%02d-%02d %02d:%02d:%02d\t", // prints data and time as yyyy-mm-dd hh:mm:ss
    my_rtc->year,
    my_rtc->month,
    my_rtc->day,       
    my_rtc->hour,
    my_rtc->minute,
    my_rtc->second
  );

  // Print temperature measurements to the log file (Tasks 4.3 and 4.4):
  logfile.print(digital_temp);
  logfile.print("\t");
  logfile.print(analogue_temp);
  logfile.print("\t");
  logfile.println();

  logfile.flush();
  digitalWrite(8, LOW);
}