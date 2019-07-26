﻿/*
  BALBOA.cpp - Library for using Balboa 32U4 with balancing and estimation library
*/

#include "Arduino.h"
#include "FastGPIO.h"
#include "BALBOA.h"


// initialize static variables here
volatile long Balboa::encCnt;
LSM6 Balboa::accelgyro;
Balboa32U4Motors Balboa::motors;
Balboa32U4Encoders Balboa::encoders;


Balboa::Balboa(){
	
	// initialize some stuff
	gx_scale = GYRO_SCALE_DEFAULT;
	gy_scale = GYRO_SCALE_DEFAULT;
	gz_scale = GYRO_SCALE_DEFAULT;
	
	ax_scale = ACCEL_SCALE_DEFAULT;
	ay_scale = ACCEL_SCALE_DEFAULT;
	az_scale = ACCEL_SCALE_DEFAULT;
	
	maxVoltage = MAX_VOLTAGE_DEFUALT;

	wheelRadius = WHEEL_RADIUS_DEFUALT;
	gearRatio = GEAR_RATIO_DEFAULT;
	enc1cpr = ENCODER_CPR_DEFAULT;
	enc2cpr = ENCODER_CPR_DEFAULT;

	hasEncoders = 1;
	hasAccel = 1;
	hasMagnetometer = 0; // Has the hardware, can be implemented later

	_msLastEncoderUpdate = 0;
} // end of constructor


void Balboa::setupHardware(void){
	Wire.begin();
	if (accelgyro.init())
	{
		_imuAvailable = 1;
#if DEBUG
		//Serial.println("Initialized IMU successfully");
#endif
	}
	else
	{
		_imuAvailable = 0;
#if DEBUG
		//Serial.println("Failed to detect and initialize IMU!");
#endif
	}

	// Sets IMU default config:
	// - Gyro:  1.66 kHz output rate, +-245 degrees/s full scale
	// - Accel: 1.66 kHz output rate, +-2 g full scale
	accelgyro.enableDefault();

	// Init encoder click counter
	encoders.init();
} // end of setupHardware

void Balboa::toggleLED(void){
	FastGPIO::Pin<LED_PIN>::setOutputToggle();
} // end of toggleLED


uint8_t Balboa::imuStatus(void){
	// returns the status of the IMU
	return _imuAvailable;
} // end of imuStatus


/*
	Currently all of these read the IMU every time
	Can be combined to a single read, should performance be needed
*/

int16_t Balboa::getAccYRaw(void){
	accelgyro.readAcc();
	return accelgyro.a.y;
} // and of getAccYRaw

int16_t Balboa::getAccZRaw(void){
	accelgyro.readAcc();
	return accelgyro.a.z;
} // and of getAccZRaw

int16_t Balboa::getGyroXRaw(void){
	accelgyro.readGyro();
	return accelgyro.g.x;
} // and of getGyroXRaw

void Balboa::updateAccYg(void){
	ay = (float)(Balboa::getAccYRaw() - ay_raw_offset) * ay_scale;
} // end of updateAccYg

void Balboa::updateAccZg(void){
	az = (float)(Balboa::getAccZRaw() - az_raw_offset) * az_scale;
} // end of updateAccZg

void Balboa::updateGyroXdps(void){
	gx = (float)(Balboa::getGyroXRaw() - gx_raw_offset) * gx_scale;
} // end of updateGyroXdps

void Balboa::updateGyro(void){
	Balboa::updateGyroXdps();
	//Minseg::updateGyroYdps(); // for example - if more gyro values desired
} // end of updateGyro

void Balboa::updateAccel(void){
	Balboa::updateAccYg();
	Balboa::updateAccZg();
	//Minseg::updateAccXg(); // if this is ever important - needs defined
} // end of updateAccel

void Balboa::updateEncoders(void){
	// get current time
	unsigned long msTime = millis();
	
	// get time difference
	unsigned long msPassed = msTime - _msLastEncoderUpdate;
	_msLastEncoderUpdate = msTime;

	// Update counts with Balboa lib
	int16_t enc1countsDelta = encoders.getCountsAndResetLeft();
	int16_t enc2countsDelta = encoders.getCountsAndResetRight();
	enc1counts += enc1countsDelta;
	enc2counts += enc2countsDelta;

	// convert counts to revolutions
	float enc1RevsDelta = gearRatio * enc1countsDelta / enc1cpr;
	float enc2RevsDelta = gearRatio * enc2countsDelta / enc2cpr;
	float enc1Revs = gearRatio * enc1counts / enc1cpr;
	float enc2Revs = gearRatio * enc2counts / enc2cpr;

	// divide revolutions by time difference
	mtr1Speed = (enc1RevsDelta / msPassed) * 1000 * 2 * M_PI;// / msPassed;
	mtr2Speed = (enc2RevsDelta / msPassed) * 1000 * 2 * M_PI;// / msPassed;
	
	// convert total revs to total distance by using wheel raidus
	x1 = enc1Revs * 2 * wheelRadius * PI;
	x2 = enc2Revs * 2 * wheelRadius * PI;
} // end of updateEncoders


void Balboa::updateMotor1(float Vin){
	static const int max_speed = 300;

	// If wanting to use mtr1Active, mtr1Speed, etc.
	// then set these here

	// convert to percentage of max, update the actual speed
	// (Clamping to +- max_speed is done by setLeftSpeed)
	motors.setLeftSpeed((Vin / maxVoltage) * max_speed);
} // end of updateMotor1

void Balboa::updateMotor2(float Vin){
	static const int max_speed = 300;

	// If wanting to use mtr1Active, mtr1Speed, etc.
	// then set these here

	// convert to percentage of max, update the actual speed
	// (Clamping to +- max_speed is done by setRightSpeed)
	motors.setRightSpeed((Vin / maxVoltage) * max_speed);
} // end of updateMotor1