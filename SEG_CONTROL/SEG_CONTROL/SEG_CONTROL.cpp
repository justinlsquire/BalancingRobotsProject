/*
  MINSEG.cpp - Library for using MinSeg with balancing and estimation library
*/

#include "Arduino.h"
#include "SEG_CONTROL.h"
#include "MINSEG.h"


// initialize static variables here


// class constructor
segControl::segControl(){
	
	// default initializations
	alphaComplementary = ALPHA_COMPLEMENTARY_DEFAULT;
	
} // end of constructor


void segControl::setupController(void){
	// pre-calculate all the time variables needed to figure out
	// controller update rate, etc.
	// calculate update time in seconds (from Hz)
	segControl::dt = 1/((float)(updateRate));
	// convert seconds to microseconds
	segControl::updateDtMicros = (long)(dt * 1000000); 
} // end of setupController


void segControl::updateEulerEstimate(void){
	// only complementary for now 
	float atanAngle;
	atanAngle = atan2(ax,az);
	ex += (alphaComplementary) * (gx * actualDt) + (1-alphaComplementary) * (atanAngle);
} // end of updateEulerEstimate

void segControl::updateController(void){
	// update time between control calculations
	actualDt = ((float)(micros() - lastControlMicros)) * 0.000001; // convert to seconds
	lastControlMicros = micros();

	// do PID only for now - but in the future, do checks to see which is selected
	
	// calculate difference between setpoint and actual value
	float error;
	error = 0.0 - ex; // use 0 degrees as the setpoint for now
	// update integral term
	integralTerm += error * actualDt * Ki;
	// check for anti-windup here
	
	
	// calculate controller output for PID
	Vout = Kp * error + Kd * gx + integralTerm;
	// use the gyro as the derivative term for now, since for
	// balancing at a setpoint zero, the gyro represents the rate
	// of change of both the angle and the error

	// in the future - add actual filtered derivative
	
} // end of updateController