/* Cryoskills Introduction to Arduino
Task 4 - Saving digital and analogue temperature measurements to an SD card
Skeleton Code */

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
PseudoRTC* my_rtc; 

// Digital Temperature variables (Task 4.3):



// Analogue Temperature variables (Task 4.4):





// Initialise functions:
void setup_sd();   // set up the SD card to log data to a file
void write_to_sd();  // write data to file
float get_ds18b20_temperature();   // fucntion to get a digital temperature, return it as a float
float get_pt1000_temperature(); // function to get a analogue temperature, return it as a float

// Setup loop (runs once):
void setup() {
  Serial.begin(9600); // Open serial connection
  setup_sd(); // Sets up SD card
  cryo_configure_clock(__DATE__,__TIME__); // Configures the RTC


}

// Main loop (runs repeatedly):
void loop() {
  // call temperature functions (Task 4.3 and 4.4):

  write_to_sd();
  delay(1000); // delay to make sure everything goes smoothly
}

// Get digital temperature function (Task 4.3):




// Get analogue temperature function (Task 4.4):




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
  logfile.println("Year\t"); // Time and temp x2 header

  pinMode(8, OUTPUT);
  Serial.println("Ready!");
}

// Write data to the SD card:
void write_to_sd() {
  digitalWrite(8, HIGH);   // set pin 8 to write
  Serial.println("writing!");  // announce that we are writing to the SD card

  // Get time from the RTC, and print to the logfile (Task 4.2):
  my_rtc = cryo_get_rtc(); // Get the time from the RTC
  logfile.println(my_rtc->year); // Prints the year to the SD card



  // Print temperature measurements to the log file (Task 4.3 and 4.4):




  logfile.flush();
  digitalWrite(8, LOW);
}