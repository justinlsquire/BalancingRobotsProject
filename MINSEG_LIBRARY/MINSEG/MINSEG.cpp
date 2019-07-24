/*
  MINSEG.cpp - Library for using MinSeg with balancing and estimation library
*/

#include "Arduino.h"
#include "MINSEG.h"
#include "ctrlTest.h"


// initialize static variables here
volatile long Minseg::encCnt;
MPU6050 Minseg::accelgyro;


Minseg::Minseg(){
	
	// define pinModes for circuit operation
	
} // end of constructor


void Minseg::setupHardware(void){
	// setup LED for debugging and heartbeat 
	pinMode(LED_PIN,OUTPUT);
	digitalWrite(LED_PIN,1);
	
	// setup Motor ports and pins
	pinMode(MTR_PWM_PIN,OUTPUT); // PWM pin for motor driver
	pinMode(MTR_DIR_PIN,OUTPUT); // direction pin for motor driver

	// set at 0 initially
	digitalWrite(MTR_DIR_PIN,LOW);
	analogWrite(MTR_PWM_PIN,0);	
	
	
	// setup IMU object
	// begin wire (i2c) 
	Wire.begin();
	
	if (accelgyro.testConnection())
	{
		accelgyro.setDLPFMode(5);
		accelgyro.initialize();
		_imuAvailable = 1;
#ifdef DEBUG		
		Serial.println("imu is connected");	
#endif		
	}
	else
	{
		_imuAvailable = 0;
#ifdef DEBUG
		Serial.println("imu is NOT connected");
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

void Minseg::setMotorPWM(int pwmVal){
	uint8_t tempMtrOut;
	
	// update motor command
	if (pwmVal < 0)
	{
		// set direction 0
		MTR_DIR_PORT &= ~(1<<MTR_DIR_OFFSET);
		tempMtrOut = -pwmVal;
	}
	else
	{
		// set direction 1
		MTR_DIR_PORT |= (1<<MTR_DIR_OFFSET);
		tempMtrOut = 255-pwmVal;
	}

	// write PWM
	analogWrite(MTR_PWM_PIN,tempMtrOut);	
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

float Minseg::getAccYg(void){
	return (float)(Minseg::getAccYRaw() - Minseg::ay_raw_offset) * ay_scale;
}

void Minseg::updateController(){
	mtr1Voltage = controllerCalcTest(gy);
} // end of updateController