/*
  MINSEG.h - Library for using MinSeg with balancing and estimation library
*/
#ifndef MINSEG_h
#define MINSEG_h

#include "Arduino.h"
// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

// define macros here
#define MTR_DIR_PIN 4
#define MTR_PWM_PIN 5
#define MTR_DIR_PORT PORTG
#define MTR_DIR_OFFSET 5 // PG5 - digital pin 4

#define ENC1_PIN 2
#define ENC2_PIN 3
#define ENC_READ_PORT PINE
#define ENC1_PORT_OFFSET 4 // PE4 - digital pin 2
#define ENC2_PORT_OFFSET 5 // PE5 - digital pin 3

#define LED_PIN 13 // digital pin 13
#define LED_PORT PORTB // PB7
#define LED_PORT_OFFSET 7 // PB7 - digital pin 13

class Minseg
{
  public:
	static volatile long encCnt; // declare
	MPU6050 accelgyro;
	// everything else is hard-coded
	// only thing we need to set up for now is the led pin
    Minseg();
	void setupHardware();
	void toggleLED();
	void setMotorPWM(int pwmVal);
	static void enc1ISR();
	static void enc2ISR();
  private:
    int _pwmVal;
	//static long encCnt;
	
	
};

#endif