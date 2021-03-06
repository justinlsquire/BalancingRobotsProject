﻿/*
  MINSEG.cpp - Library for using MinSeg with balancing and estimation library
*/

#include "Arduino.h"
#include "MINSEG_V2.h"


// initialize static variables here
volatile long Minseg::encCnt;
MPU9250 Minseg::accelgyro;


Minseg::Minseg(){
	
	// initialize some stuff
	gx_scale = GYRO_SCALE_DEFAULT;
	gy_scale = GYRO_SCALE_DEFAULT;
	gz_scale = GYRO_SCALE_DEFAULT;
	
	ax_scale = ACCEL_SCALE_DEFAULT;
	ay_scale = ACCEL_SCALE_DEFAULT;
	az_scale = ACCEL_SCALE_DEFAULT;
	
	maxVoltage = MAX_VOLTAGE_DEFAULT;
	
	wheelRadius = WHEEL_RADIUS_DEFUALT;
	gearRatio = GEAR_RATIO_DEFAULT;
	enc1cpr = ENCODER_CPR_DEFAULT;
	
	mtr1Active = MTR1_ACTIVE_DEFAULT;
	mtr2Active = MTR2_ACTIVE_DEFAULT;
	
	// initialize these floating point constants here so that 
	// floating point division is not carried out every time in the loop
	// floating point multiplication is much faster
	countsToRevsMotor1 = 1/enc1cpr;
	countsToRevsWheel1 = 1/(enc1cpr * gearRatio);
	countsToPositionWheel1 = countsToRevsWheel1 * 2 * M_PI * wheelRadius;
	countsToWheelSpeed1 = countsToPositionWheel1 * 1000;// this accounts for the delta-time in milliseconds
	countsToMtrSpeed1 = 2 * M_PI / enc1cpr * 1000; // this accounts for the delta-time in milliseconds

	// flags - reserved for potential future use 
	hasEncoders = 1;
	hasAccel = 1;
	hasMagnetometer = 0; // Has the hardware, can be implemented later
	
	encDir = 1; // forward by default (original MinSeg M2V5)

} // end of constructor


void Minseg::setupHardware(void){
	// setup LED for debugging and heartbeat 
	pinMode(LED_PIN,OUTPUT);
	digitalWrite(LED_PIN,1);
	
	// setup Motor ports and pins
	pinMode(L_MTR_PWM_PIN1,OUTPUT); // PWM pin for motor driver
	pinMode(L_MTR_PWM_PIN2,OUTPUT); // direction pin for motor driver
	pinMode(R_MTR_PWM_PIN1,OUTPUT); // PWM pin for motor driver
	pinMode(R_MTR_PWM_PIN2,OUTPUT); // direction pin for motor driver
	
	// set initial level to 0
	setMotorPWM(1,0);
	setMotorPWM(2,0);
	
	
	int status;
	// setup IMU object
	
	Wire.begin();
	
	accelgyro.initialize();
	
	status = accelgyro.getDeviceID();
	
	if ((status == 0x71) || (status == 0x73))
	{
		_imuAvailable = 1;
#ifdef DEBUG		
		Serial.println("imu is connected");	
		Serial.println(status);
#endif		
		
		uint8_t tempData;
		
		// set FIFO to not overflow if full
		//tempData = 0b01000000;
		//tempData = 0b00000001;
		//I2Cdev::writeByte(MPU9250_DEFAULT_ADDRESS,MPU9250_RA_CONFIG,tempData);
		
		// set gyro to 3600 Hz bandwidth, Fs = 32 kHz
		tempData = 0b00000011; 
		//I2Cdev::writeByte(MPU9250_DEFAULT_ADDRESS,MPU9250_RA_GYRO_CONFIG,tempData);
		
		// set accelerometer to fastest output rate
		tempData = 0b000001000;
		//I2Cdev::writeByte(MPU9250_DEFAULT_ADDRESS,MPU9250_RA_FF_THR,tempData);
		
		//tempData = 255;
		//I2Cdev::writeByte(MPU9250_DEFAULT_ADDRESS,MPU9250_RA_SMPLRT_DIV,tempData);
		
		//accelgyro.setXGyroFIFOEnabled(true);
		//accelgyro.setAccelFIFOEnabled(true);
		//accelgyro.setFIFOEnabled(true);
		//accelgyro.setFullScaleGyroRange(MPU9250_GYRO_FS_250);
		//accelgyro.setFullScaleAccelRange(MPU9250_ACCEL_FS_2);
		// set up hardware
		//accelgyro.setAccelRange(MPU9250::ACCEL_RANGE_2G);
		//accelgyro.setGyroRange(MPU9250::GYRO_RANGE_250DPS);
		//accelgyro.setDlpfBandwidth()

	}
	else
	{
		_imuAvailable = 0;
#ifdef DEBUG
		Serial.println("imu is NOT connected");
		Serial.println(status);
#endif		
	}
	
	
	
	
	// setup encoder ports and pins, and ISR
	// encoder is on pins 2 and 3
	// set up pullup resistors to prevent floating
	pinMode(ENC1_PIN,INPUT_PULLUP);
	pinMode(ENC2_PIN,INPUT_PULLUP);

	attachInterrupt(digitalPinToInterrupt(ENC1_PIN),Minseg::enc1ISR,CHANGE);
	attachInterrupt(digitalPinToInterrupt(ENC2_PIN),Minseg::enc2ISR,CHANGE);	
	
} // end of setupHardware

void Minseg::toggleLED(void){
	LED_PORT ^= (1<<LED_PORT_OFFSET);
} // end of toggleLED

void Minseg::setMotorPWM(int mtrNum, int pwmVal){
	int tempMtrOut;
	
	switch(mtrNum)
	{
		case 1:
			// handle the first pin
			if (pwmVal >= 0)
			{
				analogWrite(L_MTR_PWM_PIN1,255);
			}
			else
			{
				tempMtrOut = 255 + pwmVal;
				analogWrite(L_MTR_PWM_PIN1,((uint8_t)(tempMtrOut)));
			}
	
			// handle the second pin
			if (pwmVal >= 0)
			{
				tempMtrOut = 255 - pwmVal;
				analogWrite(L_MTR_PWM_PIN2,((uint8_t)(tempMtrOut)));
			}
			else
			{
				analogWrite(L_MTR_PWM_PIN2,255);
			}			
			break;
		case 2:
			// handle the first pin
			if (pwmVal >= 0)
			{
				analogWrite(R_MTR_PWM_PIN1,255);
			}
			else
			{
				tempMtrOut = 255 + pwmVal;
				analogWrite(R_MTR_PWM_PIN1,((uint8_t)(tempMtrOut)));
			}
			
			// handle the second pin
			if (pwmVal >= 0)
			{
				tempMtrOut = 255 - pwmVal;
				analogWrite(R_MTR_PWM_PIN2,((uint8_t)(tempMtrOut)));
			}
			else
			{
				analogWrite(R_MTR_PWM_PIN2,255);
			}			
			break;
		default:
			break;
		
	} // end of switch(mtrNum)
} // end of setMotorPWM


void Minseg::enc1ISR(void){
	
	// temporary
	LED_PORT ^= (1<<LED_PORT_OFFSET);
	
	// read the whole register
	uint8_t tempReg = ENC_READ_PORT;
	// read the pin to see if it is high or low
	if (tempReg & (1<<ENC1_PORT_OFFSET))
	{
		// low to high transition happened on enc pin 1
		// check enc pin 2
		if (tempReg & (1<<ENC2_PORT_OFFSET))
		{
			// enc pin 2 is high - moving negative direction
			encCnt--;
		}
		else
		{
			// enc pin 2 is low - moving positive direction
			encCnt++;
		}
	} // if (tempReg & (1<<ENC1_PORT_OFFSET))
	else
	{
		// high to low transition happened on enc pin 1
		// check enc pin 2
		if (tempReg & (1<<ENC2_PORT_OFFSET))
		{
			// enc pin 2 is high - moving negative direction
			encCnt++;
		}
		else
		{
			// enc pin 2 is low - moving positive direction
			encCnt--;
		}
	} // else - from if (tempReg & (1<<ENC1_PORT_OFFSET))	
} // end of enc1ISR


void Minseg::enc2ISR(void){
	
	// temporary
	LED_PORT ^= (1<<LED_PORT_OFFSET);
	
	// read the whole register
	uint8_t tempReg = ENC_READ_PORT;
	// read the pin to see if it is high or low
	if (tempReg & (1<<ENC2_PORT_OFFSET))
	{
		// low to high transition happened on enc pin 1
		// check enc pin 2
		if (tempReg & (1<<ENC1_PORT_OFFSET))
		{
			// enc pin 2 is high - moving negative direction
			encCnt++;
		}
		else
		{
			// enc pin 2 is low - moving positive direction
			encCnt--;
		}
	} // if (tempReg & (1<<ENC1_PORT_OFFSET))
	else
	{
		// high to low transition happened on enc pin 1
		// check enc pin 2
		if (tempReg & (1<<ENC1_PORT_OFFSET))
		{
			// enc pin 2 is high - moving negative direction
			encCnt--;
		}
		else
		{
			// enc pin 2 is low - moving positive direction
			encCnt++;
		}
	} // else - from if (tempReg & (1<<ENC1_PORT_OFFSET))	
} // end of enc2ISR

uint8_t Minseg::imuStatus(void){
	// returns the status of the IMU
	return _imuAvailable;
} // end of imuStatus


int16_t Minseg::getAccYRaw(void){
	return accelgyro.getAccelerationY();
} // and of getAccY

int16_t Minseg::getAccZRaw(void){
	return accelgyro.getAccelerationZ();
} // and of getAccZ

int16_t Minseg::getGyroXRaw(void){
	return accelgyro.getRotationX();
	
} // and of getAccY

int16_t Minseg::getGyroXAvg(void){
	 //this average value is calculated in the updateIMU_RAW function for now
	return gx_avg;
	
} // and of getGyroXAvg

void Minseg::updateAccYg(void){
	ay = (float)(Minseg::getAccYRaw() - ay_raw_offset) * ay_scale;
} // end of updateAccYg

void Minseg::updateAccZg(void){
	az = (float)(Minseg::getAccZRaw() - az_raw_offset) * az_scale;
} // end of updateAccZg

void Minseg::updateGyroXdps(void){
	gx = (float)(Minseg::getGyroXRaw() - gx_raw_offset) * gx_scale;
} // end of updateGyroXdps


float Minseg::getOrientationOffset(void){
	
	orientationOffset = (ALFA_GYRO_AVG)*atan2f(ay,az) + (1-ALFA_GYRO_AVG) * (lastOrientationOffset);
	lastOrientationOffset = orientationOffset;
	
	return orientationOffset;
	
} // end of getOrientationOffset

void Minseg::updateGyro(void){
	//Minseg::updateGyroXdps();
	//Minseg::updateGyroYdps(); // for example - if more gyro values desired
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
} // end of updateGyro

void Minseg::updateAccel(void){
	//Minseg::updateAccYg();
	//Minseg::updateAccZg();
	
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
	
	//Minseg::updateAccXg(); // if this is ever important - needs defined
} // end of updateAccel

void Minseg::updateIMU_FIFO(void)
{
	Serial.println(accelgyro.getFIFOCount());
	// check for FIFO count
	if (accelgyro.getFIFOCount() >= 32)
	{
		// read all the bytes into a big buffer
		accelgyro.getFIFOBytes(imuFifoBuf,32);
		
		int z = 0;
		int y = 0;
		while (z < 32)
		{
			// forget about first two bytes - they are ax
			z++;
			z++;
			// MSB of ay
			ayFifoBuffer[y] = (imuFifoBuf[z]<<8);
			z++;
			// LSB of ay
			ayFifoBuffer[y] |= imuFifoBuf[z];
			z++;
			// MSB of az
			azFifoBuffer[y] = (imuFifoBuf[z]<<8);
			z++;
			// LSB of az
			azFifoBuffer[y] |= imuFifoBuf[z];
			z++;
			// MSB of gx
			gxFifoBuffer[y] = (imuFifoBuf[z]<<8);
			z++;
			// LSB of gx
			gxFifoBuffer[y] |= imuFifoBuf[z];
			z++;
			y++;
		}
		
		// average them
		ayFifoAvg = 0;
		azFifoAvg = 0;
		gxFifoAvg = 0;
		for (int zz = 0; zz < 4; zz++)
		{
			ayFifoAvg += ayFifoBuffer[zz] * 0.125; // divide by 8
			azFifoAvg += azFifoBuffer[zz] * 0.125; // divide by 8
			gxFifoAvg += gxFifoBuffer[zz] * 0.125; // divide by 8
		}
		
		// apply a small filter?
	}
} // end of updateIMU_FIFO

void Minseg::clearIMU_FIFO(void)
{
	accelgyro.resetFIFO();
} // end of clearIMU_FIFO

void Minseg::updateIMU_RAW(void)
{
	gxFifoBuffer[gxFifoCnt] = Minseg::getGyroXRaw();
	
	// update moving average gyro as well
	gx_avg = (ALFA_GYRO_AVG) * (float)(gxFifoBuffer[gxFifoCnt]) + (1-ALFA_GYRO_AVG) * (float)(last_gx_avg);
	last_gx_avg = gx_avg;	
	
	if (gxFifoCnt < 19)
	{
		gxFifoCnt++;
	}
	
	ayFifoBuffer[ayFifoCnt] = Minseg::getAccYRaw();
	if (ayFifoCnt < 19)
	{
		ayFifoCnt++;
	}
	azFifoBuffer[azFifoCnt] = Minseg::getAccZRaw();
	if (azFifoCnt < 19)
	{
		azFifoCnt++;
	}		
} // end of updateIMU_RAW

void Minseg::updateEncoders(void){
	// get current time
	unsigned long msTime = millis();
	
	
	// get time difference
	unsigned long msPassed = msTime - _msLastEncoderUpdate;
	// update last time
	_msLastEncoderUpdate = msTime;
	
	// get counts since last time
	int16_t encCountsDelta = encCnt;
	// reset the delta counter 
	encCnt = 0;
	// add to the total count
	enc1counts += encCountsDelta;
	// update wheel position
	x1 = enc1counts * countsToPositionWheel1;
	
	x1 *= encDir; // change sign based on hardware needs
	
	// only use motor speed if it is of interest
	//mtr1Speed = encCountsDelta * countsToMtrSpeed1 / msPassed;
	
	// update wheel angular speed - probably shouldn't do this here, but instead in estimation library
	//x1_dot = encCountsDelta * countsToWheelSpeed1 / msPassed;
	
} // end of updateEncoders


void Minseg::updateMotor1(float Vin){
	
	// reverse here for compatibility with other robots
	Vin = -Vin;	
	
	// convert to percentage of max
	
	if(!mtrsActive)
	{
		Vin = 0;
	}	
		
	// simplified - do better job in the future of checking 
	int16_t tempDuty;
	
	if (mtr1Active)
	{	
		tempDuty = (int16_t)(Vin/maxVoltage * 255.0) + FRICTION_COMPENSATION;
		
		tempDuty += mtrDiff;
	
		if (tempDuty > 255)
		{
			tempDuty = 255;
		}
		else if (tempDuty < (-255))
		{
			tempDuty = -255;
		}
	} // if (mtr1Active)
	else
	{
		tempDuty = 0;
	}
	// update the actual PWM
	Minseg::setMotorPWM(1,tempDuty);
	
} // end of updateMotor1


void Minseg::updateMotor2(float Vin){
	
	// reverse here for compatibility with other robots
	Vin = -Vin;
	
	// convert to percentage of max
	
	// check for motor being active
	if(!mtrsActive)
	{
		Vin = 0;
	}
	
	
	// simplified - do better job in the future of checking
	int16_t tempDuty;
	
	if (mtr2Active)
	{
		tempDuty = (int16_t)(Vin/maxVoltage * 255.0) + FRICTION_COMPENSATION;
		
		tempDuty -= mtrDiff;
		
		if (tempDuty > 255)
		{
			tempDuty = 255;
		}
		else if (tempDuty < (-255))
		{
			tempDuty = -255;
		}
	} // if (mtr1Active)
	else
	{
		tempDuty = 0;
	}
	// update the actual PWM
	Minseg::setMotorPWM(2,tempDuty);
	
} // end of updateMotor2


void Minseg::beginTurn(uint8_t direction, int amount)
{
	if (direction == RIGHT)
	{
		mtrDiff = amount;
	}
	if (direction == LEFT)
	{
		mtrDiff = -amount;
	}
} // end of beginTurn

void Minseg::endTurn(void)
{
	mtrDiff = 0;
} // end of endTurn