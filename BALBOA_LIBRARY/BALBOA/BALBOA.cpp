/*
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
	// First 4 bits (1000) gives 1.66 kHz output data rate
	// Bit 5 and 6 (10) gives 1000 deg/s full scale
	//accelgyro.writeReg(LSM6::CTRL2_G, 0b10001000);

	// Init encoder click counter
	encoders.init();
} // end of setupHardware

void Balboa::calcGyroOffsets(int samples){
	int32_t totalX = 0, totalY = 0, totalZ = 0;
	for (int i = 0; i < samples; i++)
	{
		accelgyro.readGyro();
		totalX += accelgyro.g.x;
		totalY += accelgyro.g.y;
		totalZ += accelgyro.g.z;
		delay(1); // 1.66 kHz output rate => enough to delay 1 ms for new reading
	}
	
	gx_raw_offset = totalX / samples;
	gy_raw_offset = totalY / samples;
	gz_raw_offset = totalZ / samples;

#if DEBUG
	Serial.println("Raw offsets (x,y,z) are: ");
	Serial.println(gx_raw_offset);
	Serial.println(gy_raw_offset);
	Serial.println(gz_raw_offset);
#endif
} // end of calcGyroOffsets

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

int16_t Balboa::getGyroYRaw(void){
	accelgyro.readGyro();
	return accelgyro.g.y;
} // and of getGyroYRaw

void Balboa::updateAccYg(void){
	ay = (float)(Balboa::getAccYRaw() - ay_raw_offset) * ay_scale;
} // end of updateAccYg

void Balboa::updateAccZg(void){
	az = (float)(Balboa::getAccZRaw() - az_raw_offset) * az_scale;
} // end of updateAccZg

void Balboa::updateGyroXdps(void){
	gx = (float)(Balboa::getGyroXRaw() - gx_raw_offset) * gx_scale;
} // end of updateGyroXdps

void Balboa::updateGyroYdps(void){
	gy = (float)(Balboa::getGyroYRaw() - gy_raw_offset) * gy_scale;
} // end of updateGyroYdps

void Balboa::updateGyro(void){
	Balboa::updateGyroXdps();
	Balboa::updateGyroYdps();
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