/*
  BALBOA.cpp - Library for using Balboa 32U4 with balancing and estimation library
*/

#include <Arduino.h>
#include <FastGPIO.h>
#include "BALBOA.h"

// initialize static variables here
LSM6 Balboa::accelgyro;
Balboa32U4Motors Balboa::motors;
Balboa32U4Encoders Balboa::encoders;


Balboa::Balboa(){
	// initialize some stuff
	gx_scale = gy_scale = gz_scale = GYRO_SCALE_DEFAULT;	
	ax_scale = ay_scale = az_scale = ACCEL_SCALE_DEFAULT;

	maxVoltage = MAX_VOLTAGE_DEFUALT;

	// initialize these floating point constants here so that 
	// floating point division is not carried out every time in the loop
	// floating point multiplication is much faster
	countsToRevsMotor = 1/ENCODER_CPR;
	countsToRevsWheel = 1/(ENCODER_CPR * GEAR_RATIO);
	countsToPositionWheel = countsToRevsWheel * 2 * M_PI * WHEEL_RADIUS;
	countsToWheelSpeed = countsToPositionWheel * 1000;// this accounts for the delta-time in milliseconds
	countsToMotorSpeed = 2 * M_PI / ENCODER_CPR * 1000; // this accounts for the delta-time in milliseconds

	// flags - reserved for potential future use 
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
		Serial.println("Initialized IMU successfully");
#endif
	}
	else
	{
		_imuAvailable = 0;
#if DEBUG
		Serial.println("Failed to detect and initialize IMU!");
#endif
	}

	// Sets IMU default config:
	// - Gyro:  1.66 kHz output rate, +-245 degrees/s full scale
	// - Accel: 1.66 kHz output rate, +-2 g full scale
	accelgyro.enableDefault();

	// Example of setting gyro to non-default configuration:
	// First 4 bits (0101) gives 208 Hz output data rate
	// Bit 5 and 6 (10) gives 1000 deg/s full scale
	//accelgyro.writeReg(LSM6::CTRL2_G, 0b01011000);
	// Scale for +- 1000dps
	//gx_scale = gy_scale = gz_scale = 0.000610865238198;

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
#if ROTATE_XYZ_DIRECTIONS
	return accelgyro.a.z;
#else
	return accelgyro.a.y;
#endif
} // and of getAccYRaw

int16_t Balboa::getAccZRaw(void){
	accelgyro.readAcc();
#if ROTATE_XYZ_DIRECTIONS
	return accelgyro.a.x;
#else
	return accelgyro.a.z;
#endif
} // and of getAccZRaw

int16_t Balboa::getGyroXRaw(void){
	accelgyro.readGyro();
#if ROTATE_XYZ_DIRECTIONS
	return accelgyro.g.y;
#else
	return accelgyro.g.x;
#endif
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
	float tempAvg = 0.0;
	
	if (gxFifoCnt)
	{
		//Serial.println(gxFifoCnt);
		for (int z = 0; z < gxFifoCnt; z++)
		{
			tempAvg += gxFifoBuffer[z];
		}
		
		tempAvg /= gxFifoCnt;
		
		gx = (tempAvg - gx_raw_offset) * gx_scale;
		
		// add some filtering here?
		gx  = (ALFA_GYRO) * gx + (1-ALFA_GYRO) * last_gx;
		last_gx = gx;
		
		gxFifoCnt = 0;
	}
	else
	{
		gx = (gxFifoBuffer[0] - gx_raw_offset) * gx_scale;
	}	
	
	//Balboa::updateGyroXdps();
} // end of updateGyro

void Balboa::updateAccel(void){
	
	float tempAvg = 0.0;
	if (ayFifoCnt)
	{
		for (int z = 0; z < ayFifoCnt; z++)
		{
			tempAvg += ayFifoBuffer[z];
		}
		
		tempAvg /= ayFifoCnt;
		
		ay = (tempAvg - ay_raw_offset) * ay_scale;
		
		ayFifoCnt = 0;
	}
	else
	{
		ay = (ayFifoBuffer[0] - ay_raw_offset) * ay_scale;
	}
	
	tempAvg = 0.0;
	
	if (azFifoCnt)
	{
		for (int z = 0; z < azFifoCnt; z++)
		{
			tempAvg += azFifoBuffer[z];
		}
		
		tempAvg /= azFifoCnt;
		
		az = (tempAvg - az_raw_offset) * az_scale;
		
		azFifoCnt = 0;
	}
	else
	{
		az = (azFifoBuffer[0] - az_raw_offset) * az_scale;
	}	
	
	//Balboa::updateAccYg();
	//Balboa::updateAccZg();
} // end of updateAccel

void Balboa::updateIMU_RAW(void)
{
	gxFifoBuffer[gxFifoCnt] = Balboa::getGyroXRaw();
	if (gxFifoCnt < 19)
	{
		gxFifoCnt++;
	}
	ayFifoBuffer[ayFifoCnt] = Balboa::getAccYRaw();
	if (ayFifoCnt < 19)
	{
		ayFifoCnt++;
	}
	azFifoBuffer[azFifoCnt] = Balboa::getAccZRaw();
	if (azFifoCnt < 19)
	{
		azFifoCnt++;
	}
} // end of updateIMU_RAW


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

	// update wheel position
	x1 = enc1counts * countsToPositionWheel;
	x2 = enc2counts * countsToPositionWheel;

	// only use motor speed if it is of interest
	//mtr1Speed = enc1countsDelta * countsToMotorSpeed / msPassed;
	//mtr2Speed = enc2countsDelta * countsToMotorSpeed / msPassed;

	// update wheel angular speed - probably shouldn't do this here, but instead in estimation library
	//x1_dot = enc1countsDelta * countsToWheelSpeed / msPassed;
	//x2_dot = enc2countsDelta * countsToWheelSpeed / msPassed;

} // end of updateEncoders


void Balboa::updateMotor1(float Vin){
	static const int max_speed = 300;

	// convert to percentage of max, update the actual speed
	// (Clamping to +- max_speed is done by setLeftSpeed)
	motors.setLeftSpeed((Vin / maxVoltage) * max_speed + RL_OFFSET);
} // end of updateMotor1

void Balboa::updateMotor2(float Vin){
	static const int max_speed = 300;

	// convert to percentage of max, update the actual speed
	// (Clamping to +- max_speed is done by setRightSpeed)
	motors.setRightSpeed((Vin / maxVoltage) * max_speed - RL_OFFSET);
} // end of updateMotor1