﻿/*
  BALBOA.h - Library for using Balboa 32U4 with balancing and estimation library

  Directions are defined as follows, when the robot is "standing up" (balancing):
	X: Wheel axis
	Y: Horizontal axis, perpendicular to wheel axis
	Z: Vertical axis (Positve direction down towards the ground)
*/
#ifndef BALBOA_h
#define BALBOA_h

#include <Balboa32U4.h>
#include <LSM6.h>
#include "Wire.h"


// define macros here
#define LED_PIN 13

// radius (in meters) of wheel(s) used
#define WHEEL_RADIUS 0.04  // in meters
// total gear ratio: motor revolutions per wheel revolution
#define GEAR_RATIO 2.88235294118 // 49:17 exact ratio
// Encoder counts per revolution of motor
#define ENCODER_CPR 358.32  // Using 12 CPR encoder with 29.86:1 builtin motor gearbox

// SCALING FACTORS (from datasheet)
// For Full Scale +-245 degs/s, gyro sens is typically 8.75 mdeg/LSB
#define GYRO_SCALE_DEFAULT  0.00015271631  // converts to rad/s
// For Full Scale +-2 g, accelerom. sens is typically 0.061 mg/LSB
#define ACCEL_SCALE_DEFAULT 0.000061       // converts to g

#define MAX_VOLTAGE_DEFUALT 6.0


// Whether to rotate all directions when reading from gyro and accelerometer
// (e.g. when calling GetGyroXRaw(), actually read y direction)
// This is neccessary to obtain the directions defined at the top of this file,
// which should be consistent with the MinSeg default
#define ROTATE_XYZ_DIRECTIONS 1

#define ALFA_GYRO 0.9 // amount given to new value

#define RL_OFFSET 0//-3 // number of points to add/subtract from right, compared to left


class Balboa
{
  public:
	static LSM6 accelgyro;
	static Balboa32U4Encoders encoders;
	static Balboa32U4Motors motors;
	
	// displacement related
	float x1; // displacement of motor 1 (left/default)
	float x2; // displacement of motor 2 (right)
	float x1_dot; // speed of motor 1 (left/default)
	float x2_dot; // speed of motor 2 (right)
	
	// IMU related
	uint8_t hasAccel; // flag for whether or not it has accelerometer
	uint8_t hasMagnetometer; // flag for whether or not it has magnetometer

	// gyro
	int16_t gx_raw, gy_raw, gz_raw; // raw (integer) values of gyro
	int16_t gx_raw_offset, gy_raw_offset, gz_raw_offset; // raw (integer) offset values of gyro
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
	float mtr1Speed; // angular speed of motor in rad/s
    long enc1counts; // counts (+ or -) of the encoder pulses
    uint8_t enc1Direction; // 0 = normal, 1 = inverted	
	float mtr1Voltage;
		
	// # 2 (Left) Motor
	uint8_t mtr2Active; // 0 = inactive, 1 = active
	uint8_t mtr2Direction; // 0 = normal, 1 = inverted
	float mtr2Speed; // angular speed of motor in rad/s			
    long enc2counts; // counts (+ or -) of the encoder pulses
    uint8_t enc2Direction; // 0 = normal, 1 = inverted	
	float mtr2Voltage;
	
	
	
	
	// everything else is hard-coded
    Balboa();
	void setupHardware();
	void toggleLED();
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
	
	void updateIMU_RAW();
	
	void updateEncoders();
	
	void updateMotor1(float Vin);
	void updateMotor2(float Vin);
	
  private:
	uint8_t _imuAvailable;
	// Time (in ms) of last encoder count reading
	uint32_t _msLastEncoderUpdate;

	// Precalculated multiplication factors (based on gear ratio, encoder cpr, etc.):
	float countsToRevsWheel;     // Conversion from counts to wheel revolutions 
	float countsToRevsMotor;     // Conversion from counts to motor revolutions
	float countsToPositionWheel; // Conversion from counts to wheel displacement
	float countsToWheelSpeed;    // Conversion from counts/ms counts to wheel speed
	float countsToMotorSpeed;    // Conversion from counts/ms counts to motor speed
};

#endif