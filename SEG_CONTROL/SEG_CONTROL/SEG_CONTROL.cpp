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
	// do PID only for now - but in the future, do checks to see which is selected
	
	// calculate difference between setpoint and actual value
	float error;
	error = 0.0 - ex;
	integralTerm += error * actualDt * Ki;
	// check for anti-windup here
	
	
	// calculate controller output for PID
	Vout = Kp * error + Kd * gx + integralTerm;
	
} // end of updateController