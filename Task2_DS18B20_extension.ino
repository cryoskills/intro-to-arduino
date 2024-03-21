/* Cryoskills Introduction to Arduino
Task 2 - DS18B20 Digital Temperature Sensor
Extension Code */

//Include libraries
#include <OneWire.h>
#include <DS18B20.h>

// initalise the digital temperature probe:
DS18B20 ds(5); // DS18B20 is connected to pin 5 (D5)

// initialise variables:
float ds_temp; // DS probe temperature measurement, value is a float
unsigned long myTime = 0; // Defines the time variables

// initialise functions:
float get_ds_temp();   // get a digital temperature reading from the function, return it as a float

void setup() {
  Serial.begin(9600); // sets baud rate (serial communication at 9600 bits of data per second)
  ds.setResolution(9); // set the DS resolution to 9-bit
}

void loop() {
  ds_temp = get_ds_temp(); // Temperature from the function below
  
  if (ds_temp > 22 ) { // Temperature is greater than 22 degrees C
    digitalWrite(LED_BUILTIN, HIGH);  // turn on the built-in LED
  } else { // Temperature is less than 22 degrees C
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off
  } 

  float resolution = ds.getResolution(); // reads the DS probe resolution
  Serial.print("Resolution: ");
  Serial.println(resolution); // prints the resolution

  Serial.print("Time: "); // Print text
  myTime = millis();      // Function returns the number of milliseconds since the board began running the current program.
  Serial.println(myTime); // prints time since program started

  delay(500); // wait half a second
}
 
// get temperature value from DS probe as a function
float get_ds_temp(){
  while (ds.selectNext()) {
    Serial.print("Temperature: ");
    ds_temp = ds.getTempC();
    Serial.print(ds_temp);
    Serial.println(" deg C");
  }
  return ds_temp;
}