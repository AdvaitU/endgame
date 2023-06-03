#include "Accelerometer.h"

Accelerometer acc;          // Create object of the Accelerometer class

// SETUP --------------------------------------------------------------------------------------------------------------------

void setup(void) {

  Serial.begin(9600);         // Begin communication with sensor
  acc.setUpAccelerometer();   // Accelerometer Setup function
}

// LOOP -------------------------------------------------------------------------------------------------------------------

void loop(void) {
  
  // Test String print for Calibration
  //acc.mapXYZ();
  //Serial.println(acc.testCreateString());

  // // Default Mapping
  // acc.mapXYZ();                 // Map the raw sensor values
  // Serial.println(acc.createString());     // Print string to Serial Monitor

  // // Modular Map Examples
  // acc.modMapXYZ(0,100,0,100,0,100);             // Same as mapXYZ but 6 arguments set the min and max range for mapping x, y, and z respectively
  // Serial.println(acc.modCreateString(1,0,1));   // Three arguments in booleans to choose whether to send x,y, and z values (in that order)

  // My requirement
  acc.modMapXYZ(0,100,0,100,0,100);
  Serial.println(acc.modCreateString(1,0,1));

  // Delay in milliseconds
  delay(100);                             // Latency adjustment

}

