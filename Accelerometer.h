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

    // MAP (NORMALISE) METHODS ------------------------------------------------------------------------------------------------------
    // Maps x, y, and z with default values
    void mapXYZ() {

      bno.getEvent(&event);        // Get event

      // Map respective raw sensor values to between -50 and 50 - Holding the sensor in 0,0,0 should yield output string 0,0,0
      // Change the values to change accuracy and range.
      x = map(event.orientation.x, 0, 360, -50, 50);        // Rotating the ball left to right
      y = map(event.orientation.y, -90, 90, -50, 50);       // Tilting the ball sideways
      z = map(event.orientation.z, -180, 180, -50, 50);     // Moving the ball front and back

    }

    // MODULAR MAP ------------------------------------------------------------------------------------------------------------------
    // Same as mapXYZ but 6 arguments set the min and max range for mapping x, y, and z respectively
    void modMapXYZ(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax) {

      bno.getEvent(&event);        // Get event

      x = map(event.orientation.x, 0, 360, xMin, xMax);        // Rotating the ball left to right
      y = map(event.orientation.y, -90, 90, yMin, yMax);       // Tilting the ball sideways
      z = map(event.orientation.z, -180, 180, zMin, zMax);     // Moving the ball front and back

    }

    // RETURN STRING METHOD --------------------------------------------------------------------------------------------------------
    String createString() {       // (Ideally) put in loop() of Arduino Programme
      
      output = String(x) + "," + String(y) + "," + String(z);  // Create final string to send out over Serial
      return output;

    }
    

    // MODULAR CREATE STRING - CHOOSE WHETHER TO SEND X, Y, and Z VALUES INDIVIDUALLY-------------------------------------------------
    // Three arguments in booleans to choose whether to send x,y, and z values (in that order)
    String modCreateString(bool sendX, bool sendY, bool sendZ) {

      output.remove(0,output.length());  // Flush everything from output

      if (sendX) {
        output = String(x) + ",";
      }
      if(sendY) {
        output += String(y) + ",";
      }
      if(sendZ) {
        output += String(z);
      }

      return output;

    }

    // TEST STRING PRINT ---------------------------------------------------------------------------------------------------------------
    // For testing and calibration purposes - prints x,y,z with labels.
    // NOT RECOMMENDED to be sent to Serial Montor in final run as labels will require removal in the programme accessing the serial monitor.

    String testCreateString() {

      output = "X: " + String(x) + ", Y: " + String(y) + ", Z: " + String(z);  // Create final string to send out over Serial
      return output;

    }

    // END ------------------------------------------------------------------------------------------------------------------------------
    





















};