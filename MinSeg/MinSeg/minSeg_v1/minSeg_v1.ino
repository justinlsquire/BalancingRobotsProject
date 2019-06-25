// This library must be installed through libraries manager
#include <TimerOne.h>

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"



// define macros here



// define variables here
MPU6050 accelgyro;

int16_t ax, ay, az; // raw values for accelerometer
int16_t gx, gy, gz; // raw values for gyro

uint8_t imuFeedbackAvailable = 0; // initialize false


// define functions here
void controllerUpdate(void)
{
  // get sensor data
    // IMU
    // read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // these methods (and a few others) are also available
    //accelgyro.getAcceleration(&ax, &ay, &az);
    //accelgyro.getRotation(&gx, &gy, &gz);    

    // encoder

  // Calculate feedback control law

  // Check voltage and scale

  // update motor command
} // end of controllerupdate




void setupMotor(void)
{
  pinMode(5,OUTPUT); // PWM pin for motor driver
  pinMode(4,OUTPUT); // direction pin for motor driver

  // set at 0 initially
  digitalWrite(4,LOW);
  analogWrite(5,0);
  
} // end of setupMotor


void setupEncoder(void)
{
  // encoder is on pins 2 and 3
  // set up pullup resistors to prevent floating
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(2),enc1ISR,CHANGE);
  attachInterrupt(digitalPinToInterrupt(3),enc2ISR,CHANGE);
  
} // end of setupEncoder

void enc1ISR(void)
{
  
} // end of enc1ISR

void enc2ISR(void)
{
  
} // end of enc2ISR



uint8_t setupIMU(void)
{
  uint8_t imuWorking = 0; // initialize false
   
  Wire.begin();
  accelgyro.setDLPFMode(5);
  accelgyro.initialize();

  // test connection
  imuWorking = accelgyro.testConnection();

  return(imuWorking);
} // end of setupIMU



void setup(void)
{
  // set up motor pins and ports
  setupMotor();

  // set up encoder pins and ports
  setupEncoder();

  // set up IMU stuff
  setupIMU();

  // set up LED
  if (setupIMU())
  {
    // set global flag true (it was initialized false)
    imuFeedbackAvailable = 1;
    
  }
  
  

  // set up timer for controller 
  Timer1.initialize(50000);
  Timer1.attachInterrupt(controllerUpdate); // controllerUpdate to run every 50 ms

  // Set up serial port
  Serial.begin(115200);
} // end of setup




void loop(void)
{
  //unsigned long blinkCopy;  // holds a copy of the blinkCount

  // to read a variable which the interrupt code writes, we
  // must temporarily disable interrupts, to be sure it will
  // not change while we are reading.  To minimize the time
  // with interrupts off, just quickly make a copy, and then
  // use the copy while allowing the interrupt to keep working.
  noInterrupts();
  // update copy variables
  interrupts();

  // write out serial data
  
}
