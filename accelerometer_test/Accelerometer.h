#include <Wire.h>                  // For communication with I2C device - the BNO055 sensor
#include <Adafruit_Sensor.h>       // Adafruit Unified Sensor Library - https://github.com/adafruit/Adafruit_Sensor 
#include <Adafruit_BNO055.h>       // Adafruit BNO055 Library - https://github.com/adafruit/Adafruit_BNO055 
#include <utility/imumaths.h>      // For vector calculations in BNO055 Library - https://github.com/adafruit/Adafruit_BNO055/blob/master/utility/imumaths.h 

// ACCELEROMETER CLASS DECLARATION ---------------------------------------------------------------------------------------------

class Accelerometer {             

// PRIVATE ----------------------------------------------------------------  
  private:

    int x;              // To store tilt along the x-axis (Roll)
    int y;              // To store tilt along the x-axis (Pitch)
    int z;              // To store tilt along the x-axis (Yaw)
    String output;      // String that save the output string in comma separated format i.e. "x,y,z" - Print this to console/serial monitor

    Adafruit_BNO055 bno = Adafruit_BNO055(55);   // BNO055 Object from Adafruit BNO055 Library
    sensors_event_t event;                       // Adafruit Unified Sensor Library Event struct to save event data

// PUBLIC ----------------------------------------------------------------  
  
  public:      

    // GETTERS -----------------------------------------------------------
    int getX() {         // Get x
      return x;
    }

    int getY() {         // Get y
      return y;
    }

    int getZ() {         // Get z
      return z;
    }

    // METHODS ------------------------------------------------------------------------
    void setUpAccelerometer() {   // Put in setup() of Arduino Programme
      
      if(!bno.begin())            // Initialise the sensor
      {
        //Serial.print("No BNO055 was detected. Please check your connections");  // Test print statement
        while(1);
      }

      bno.setExtCrystalUse(true);  // Use external crystal for timing
      //delay(1000);

    }

    // MAP (NORMALISE) METHOD ----------------------------------------------------------
    void mapXYZ() {

      bno.getEvent(&event);        // Get event

      // Map respective raw sensor values to between -50 and 50 - Holding the sensor in 0,0,0 should yield output string 0,0,0
      // Change the values to change accuracy and range.
      x = map(event.orientation.x, 0, 360, -50, 50);        // Rotating the ball left to right
      y = map(event.orientation.y, -90, 90, -50, 50);       // Tilting the ball sideways
      z = map(event.orientation.z, -180, 180, -50, 50);     // Moving the ball front and back

    }

    // RETURN STRING METHOD --------------------------------------------------------------
    String createString() {       // (Ideally) put in loop() of Arduino Programme
      
      mapXYZ();                 // Map the raw sensor values
      output = String(x) + "," + String(y) + "," + String(z);  // Create final string to send out over Serial
      return output;

    }

};