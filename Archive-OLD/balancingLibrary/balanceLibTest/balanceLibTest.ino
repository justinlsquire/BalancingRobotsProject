// This library must be installed through libraries manager
//#include <TimerOne.h>

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
//#include "I2Cdev.h"
//#include "MPU6050.h"
//#include "Wire.h"
#include "src/balanceLibrary/balanceLibrary.h" // platform independent balancing and estimation library
#include "src/balanceLibrary/minSeg.h" // platform dependent hardware library and functions for MinSeg

#define CONTROL_PERIOD 50000 // in microseconds

// timer variables
unsigned long controlTimer = 0;
float dt = 0.0;
unsigned long dtInt = 0;



// define functions here
void controllerUpdate(void)
{
  // get sensor data
    // IMU
    // read raw accel/gyro measurements from device


    // get time since last measurement
    dt = (micros()-dtInt) * 0.000001;
    // reset it
    dtInt = micros();
    

    // update Euler integrated angle
    

    // encoder

  // Calculate feedback control law

} // end of controllerupdate




















void setup(void)
{
  // Set up serial port
  Serial.begin(115200);

  // Set up LED
  setupLED();

  // delay for a bit to distinguish LED
  delay(1000);
  
  // set up motor pins and ports
  setupMotor();

  // set up encoder pins and ports
  //setupEncoder();

  // set up IMU stuff
  //setupIMU();

  // set up LED
  //if (setupIMU())
  //{
    // set global flag true (it was initialized false)
    //imuFeedbackAvailable = 1;

    // calibrate gyro
    //calibrateIMU();

    // toggle LED
    
  //} // end of if(setupIMU())
  

  delay(1000);

  // set up timer for controller 
  //Timer1.initialize(150000);
  //Timer1.attachInterrupt(controllerUpdate); // controllerUpdate to run every 50 ms

} // end of setup




void loop(void)
{
  //unsigned long blinkCopy;  // holds a copy of the blinkCount

  // to read a variable which the interrupt code writes, we
  // must temporarily disable interrupts, to be sure it will
  // not change while we are reading.  To minimize the time
  // with interrupts off, just quickly make a copy, and then
  // use the copy while allowing the interrupt to keep working.
  //noInterrupts();
  // update copy variables
 // encCntCopy = encCnt;
 // interrupts();

  // write out serial data

  if ((micros() - controlTimer) >= CONTROL_PERIOD)
  {
    // reset timer
    controlTimer = micros();
    // call service routine
    controllerUpdate();
  }

//  Serial.print(encCnt);
//  Serial.print(',');
//  Serial.print(mtrOut);
//  Serial.print(',');
//  Serial.println(gx);

  //Serial.println(eX);
  //Serial.println(gXfilt);
  //Serial.println(vOut);
  //Serial.println(gx_offset);
  
}
