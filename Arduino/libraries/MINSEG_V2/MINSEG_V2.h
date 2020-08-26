﻿/*
  MINSEG.h - Library for using MinSeg with balancing and estimation library
*/
#ifndef MINSEG_V2_h
#define MINSEG_V2_h

#include "Arduino.h"
// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
//#include "MPU6050.h"
#include "MPU9250.h"
#include "Wire.h"


// define macros here

// debug flag
#define DEBUG 1


#define L_MTR_PWM_PIN1 6
#define L_MTR_PWM_PIN2 7
#define R_MTR_PWM_PIN1 9
#define R_MTR_PWM_PIN2 10

#define ENC1_PIN 2
#define ENC2_PIN 3
#define ENC_READ_PORT PINE
#define ENC1_PORT_OFFSET 4 // PE4 - digital pin 2
#define ENC2_PORT_OFFSET 5 // PE5 - digital pin 3

#define LED_PIN 13 // digital pin 13
#define LED_PORT PORTB // PB7
#define LED_PORT_OFFSET 7 // PB7 - digital pin 13

#define RIGHT 1
#define LEFT 2


// SCALING FACTORS
// default 250 deg/s setting is 131 LSB/(deg/s) - divide by 131 and then multiply by 2 * pi / 360 to get rad/s
#define GYRO_SCALE_DEFAULT 0.0001332312406 // converts to rad/s
#define ACCEL_SCALE_DEFAULT 0.00006103515625 // converts to g


// found great info at this website about NXT motor parameters
// http://www.philohome.com/nxtmotor/nxtmotor.htm
// http://web.archive.org/web/20111010092210/http://web.mac.com/ryo_watanabe/iWeb/Ryo's%20Holiday/NXT%20Motor.html
//
#define WHEEL_RADIUS_DEFUALT 0.022098 // in meters
#define GEAR_RATIO_DEFAULT 50 // 48:1
#define ENCODER_CPR_DEFAULT 28  // Using 15 CPR encoder

#define FRICTION_COMPENSATION 10 // added boost (from Simulink model) to compensate for Coulomb friction
#define MAX_VOLTAGE_DEFAULT 7.5 // based on MinSeg stock hardware with 6x1.5V AA batteries

#define MTR1_ACTIVE_DEFAULT 1 // active / on by default
#define MTR2_ACTIVE_DEFAULT 1 // active / on by default

#define ALFA_GYRO 0.9 // amount given to new value

#define ALFA_GYRO_AVG 0.05 // amount given to new value

class Minseg
{
  public:
	static volatile long encCnt; // declare
	static MPU9250 accelgyro;
	
	// displacement related
	float wheelRadius; // radius (in meters) of wheel(s) used
	float gearRatio; // total gear ratio from motor output to wheel output
	float x1; // displacement of motor 1 (left/default)
	float x2; // displacement of motor 2 (right)
	float x1_dot; // speed of motor 1 (left/default)
	float x2_dot; // speed of motor 2 (right)
	
	// IMU related
	uint8_t hasAccel; // flag for whether or not it has accelerometer
	uint8_t hasMagnetometer; // flag for whether or not it has magnetometer
	
	// FIFO buffer
	uint8_t imuFifoBuf[64]; // should be data for 8 samples of everything

	// gyro
	int16_t gx_raw, gy_raw, gz_raw; // raw (integer) values of gyro
	int16_t gx_raw_offset, gy_raw_offset, gz_raw_offset; // raw (integer) offset values of gyro
	int16_t gx_avg;
	int16_t last_gx_avg;
	float gx_scale, gy_scale, gz_scale; // scale factors for converting raw gyro values to g* (rad/s)
	float gx, gy, gz; // gyro values (in rad/s)
	float last_gx,last_gy,last_gz;
	int16_t gxFifoBuffer[20];
	int16_t gxFifoAvg;
	uint8_t gxFifoCnt;

	// accelerometer
	int16_t ax_raw, ay_raw, az_raw; // raw (integer) values of accelerometer
	int16_t ax_raw_offset, ay_raw_offset, az_raw_offset; // raw (integer) offset values of accelerometer
	float ax_scale, ay_scale, az_scale; // scale factor for converting a*_raw to a* (in g);
	float ax, ay, az; // acceleration values (in g)
	int16_t ayFifoBuffer[20];
	int16_t ayFifoAvg;
	uint8_t ayFifoCnt;
	int16_t azFifoBuffer[20];
	int16_t azFifoAvg;
	uint8_t azFifoCnt;
	
	// angle
	float orientationOffset;
	float lastOrientationOffset;

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
	float countsToRevsWheel1; // multiplication factor that is calculated once (to avoid slow floating point division)
	float countsToRevsMotor1; // multiplication factor that is calculated once (to avoid slow floating point division)
	float countsToPositionWheel1; // multiplication factor that is calculated once (to avoid slow floating point division)
	float countsToWheelSpeed1; // multiplication factor that is calculated once (to avoid slow floating point division)
	float countsToMtrSpeed1; // multiplication factor that is calculated once (to avoid slow floating point division)
    uint8_t enc1Direction; // 0 = normal, 1 = inverted	
	float mtr1Voltage;
		
	// # 2 (Left) Motor
	uint8_t mtr2Active; // 0 = inactive, 1 = active
	uint8_t mtr2Direction; // 0 = normal, 1 = inverted
	uint8_t mtr2DutyCycle; // duty cycle of motor for pwm
	float mtr2Speed; // angular speed of motor in rad/s			
    long enc2counts; // counts (+ or -) of the encoder pulses
    uint16_t enc2cpr; // counts per revolution of motor
	float countsToRevsWheel2; // multiplication factor that is calculated once (to avoid slow floating point division)
	float countsToRevsMotor2; // multiplication factor that is calculated once (to avoid slow floating point division)
	float countsToPositionWheel2; // multiplication factor that is calculated once (to avoid slow floating point division)
	float countsToWheelSpeed2; // multiplication factor that is calculated once (to avoid slow floating point division)
	float countsToMtrSpeed2; // multiplication factor that is calculated once (to avoid slow floating point division)	
    uint8_t enc2Direction; // 0 = normal, 1 = inverted	
	float mtr2Voltage;
	
	uint8_t mtrsActive;
	
	// motor difference for turning
	int mtrDiff;
	
	// everything else is hard-coded
	// only thing we need to set up for now is the led pin
    Minseg();
	void setupHardware();
	void toggleLED();
	void setMotorPWM(int motor, int pwmVal);
	static void enc1ISR();
	static void enc2ISR();
	uint8_t imuStatus();
	
	// only adding a few of these, but they can be expanded 
	// to include way more
	int16_t getGyroXRaw();
	int16_t getAccYRaw();
	int16_t getAccZRaw();
	
	int16_t getGyroXAvg(); 
	
	float getOrientationOffset();
	
	// get the scaled values of the raw values
	void updateGyroXdps();
	void updateAccYg();
	void updateAccZg();
	void updateGyro(); // for doing all at once
	void updateAccel(); // for doing all at once
	void updateEncoders();
	
	void updateIMU_RAW();
	
	void updateIMU_FIFO();
	void clearIMU_FIFO();
	
	void updateMotor1(float Vin);
	void updateMotor2(float Vin);
	
	void beginTurn(uint8_t direction, int amount);
	void endTurn();
	
  private:
    int _pwmVal;
	uint8_t _imuAvailable;
	// time (in ms) of last encoder count reading
	long _msLastEncoderUpdate;
	//static long encCnt;
	
	
};

#endif