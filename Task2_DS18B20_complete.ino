/* Cryoskills Introduction to Arduino
Task 2 - DS18B20 Digital Temperature Sensor
Complete Code */

// Include libraries:
#include <OneWire.h>
#include <DS18B20.h>

// initalise the digital temperature probe:
DS18B20 ds(5); // DS18B20 is connected to pin 5 (D5)

// initialise variables:
float digital_temp; // DS probe temperature measurement, value is a float

// initialise functions:
float get_ds18b20_temperature();   // fucntion to get a digital temperature, return it as a float

void setup() {
  Serial.begin(9600); // sets baud rate (serial communication at 9600 bits of data per second)
}

void loop() {
  digital_temp = get_ds18b20_temperature(); // Call temperature function below to get reading
  
  if (digital_temp > 22 ) { // if temperature is greater than 22 degrees C
    digitalWrite(LED_BUILTIN, HIGH);  // turn on the built-in LED
  } else { // if temperature is less than 22 degrees C
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off
  } 

  delay(500); // wait half a second
}
 
// get temperature value from DS probe as a function
float get_ds18b20_temperature(){
  while (ds.selectNext()) {
    Serial.print("Temperature: ");
    digital_temp = ds.getTempC();
    Serial.print(digital_temp);
    Serial.println(" deg C");
  }
  return digital_temp;
}