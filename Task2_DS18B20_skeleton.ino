/* Cryoskills Introduction to Arduino
Task 2 - DS18B20 Digital Temperature Sensor
Skeleton Code */

// Include libraries:


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
  // get temperature value from the DS probe and print to serial  
  while (ds.selectNext()) {
    Serial.print("Temperature: ");
    Serial.print(ds.getTempC());
    Serial.println(" deg C");
  }
  
  // if temperature is greater than 22 degrees C
  // turn on the LED
  // if temperature is less than 22 degrees C
  // turn the LED off

  delay(1000); // wait 1 second
}
 
// get temperature value from DS probe as a function here:
// YOUR CODE HERE...