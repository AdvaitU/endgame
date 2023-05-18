#include "Accelerometer.h"

Accelerometer acc;          // Create object of the Accelerometer class

// SETUP --------------------------------------------------------------------------------------------------------------------

void setup(void) {

  Serial.begin(9600);         // Begin communication with sensor
  acc.setUpAccelerometer();   // Accelerometer Setup function
}

// LOOP -------------------------------------------------------------------------------------------------------------------

void loop(void) {

  Serial.println(acc.createString());     // Print string to Serial Monitor
  delay(100);                             // Latency adjustment

}

