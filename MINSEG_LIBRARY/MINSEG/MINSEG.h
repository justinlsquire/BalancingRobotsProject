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

// debug flag
#define DEBUG 1


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


// SCALING FACTORS
#define GYRO_SCALE_DEFAULT 0.0001332312406 // converts to rad/s
#define ACCEL_SCALE_DEFAULT 0.00006103515625 // converts to g


#define MAX_VOLTAGE_DEFAULT 6.0

class Minseg
{
  public:
	static volatile long encCnt; // declare
	static MPU6050 accelgyro;
	
	// displacement related
	float wheelRadius; // radius (in meters) of wheel(s) used
	float gearRatio; // total gear ratio from motor output to wheel output
	float x1; // displacement of motor 1 (left/default)
	float x2; // displacement of motor 2 (right)
	
	// IMU related
	uint8_t hasAccel; // flag for whether or not it has accelerometer
	uint8_t hasMagnetometer; // flag for whether or not it has magnetometer

	// gyro
	int16_t gx_raw, gy_raw, gz_raw; // raw (integer) values of gyro
	int16_t gx_raw_offset, gy_raw_offset, gz_raw_offset; // raw (integer) offset values of gyro
	float gx_scale, gy_scale, gz_scale; // scale factors for converting raw gyro values to g* (rad/s)
	float gx, gy, gz; // gyro values (in rad/s)

	// accelerometer
	int16_t ax_raw, ay_raw, az_raw; // raw (integer) values of accelerometer
	int16_t ax_raw_offset, ay_raw_offset, az_raw_offset; // raw (integer) offset values of accelerometer
	float ax_scale, ay_scale, az_scale; // scale factor for converting a*_raw to a* (in g);
	float ax, ay, az; // acceleration values (in g)

	// magnetometer
	int16_t mx_raw, my_raw, mz_raw; // raw (integer) values of magnetometer
	int16_t mx_raw_offset, my_raw_offset, mz_raw_offset; // raw (integer) offset values of magnetometer
	float mx_scale, my_scale, mz_scale; // scale factor for converting m*_raw to m* (gauss)
	float mx, my, mz;
	
	// motor related
	
	float maxVoltage; // max motor voltage
	uint8_t hasEncoders; // flag - 0 = no encoder(s), 1 = encoder(s)
	
	// # 1 (Right) Motor
	uint8_t mtr1Active; // 0 = inactive, 1 = active
	uint8_t mtr1Direction; // 0 = normal, 1 = inverted
	uint8_t mtr1DutyCycle; // duty cycle of motor for pwm
	float mtr1Speed; // angular speed of motor in rad/s
    long enc1counts; // counts (+ or -) of the encoder pulses
    uint16_t enc1cpr; // counts per revolution of motor
    uint8_t enc1Direction; // 0 = normal, 1 = inverted	
	float mtr1Voltage;
		
	// # 2 (Left) Motor
	uint8_t mtr2Active; // 0 = inactive, 1 = active
	uint8_t mtr2Direction; // 0 = normal, 1 = inverted
	uint8_t mtr2DutyCycle; // duty cycle of motor for pwm
	float mtr2Speed; // angular speed of motor in rad/s			
    long enc2counts; // counts (+ or -) of the encoder pulses
    uint16_t enc2cpr; // counts per revolution of motor
    uint8_t enc2Direction; // 0 = normal, 1 = inverted	
	float mtr2Voltage;
	
	
	
	
	// everything else is hard-coded
	// only thing we need to set up for now is the led pin
    Minseg();
	void setupHardware();
	void toggleLED();
	void setMotorPWM(int pwmVal);
	static void enc1ISR();
	static void enc2ISR();
	uint8_t imuStatus();
	
	// only adding a few of these, but they can be expanded 
	// to include way more
	int16_t getGyroXRaw();
	int16_t getAccYRaw();
	int16_t getAccZRaw();
	
	// get the scaled values of the raw values
	void updateGyroXdps();
	void updateAccYg();
	void updateAccZg();
	void updateGyro(); // for doing all at once
	void updateAccel(); // for doing all at once
	void updateEncoders();
	
	void updateMotor1(float Vin);
	
  private:
    int _pwmVal;
	uint8_t _imuAvailable;
	//static long encCnt;
	
	
};

#endif