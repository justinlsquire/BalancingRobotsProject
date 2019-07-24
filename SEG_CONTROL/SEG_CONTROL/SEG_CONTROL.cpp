/*
  MINSEG.cpp - Library for using MinSeg with balancing and estimation library
*/

#include "Arduino.h"
#include "SEG_CONTROL.h"
#include "MINSEG.h"


// initialize static variables here


// class constructor
segControl::segControl(){
	
} // end of constructor


void segControl::setupController(void){
	// pre-calculate all the time variables needed to figure out
	// controller update rate, etc.
	// calculate update time in seconds (from Hz)
	segControl::dt = 1/((float)(updateRate));
	// convert seconds to microseconds
	segControl::updateDtMicros = (long)(dt * 1000000); 
} // end of setupController

void getSensorData(void){
	//switch()
} // end of getSensorData
