/*
  MINSEG.cpp - Library for using MinSeg with balancing and estimation library
*/

#include "Arduino.h"
#include "SEG_CONTROL.h"


// initialize static variables here


// class constructor
segControl::segControl(){
	
	// default initializations
	
	// complementary/exponential filter settings
	alphaComplementary = ALPHA_COMPLEMENTARY_DEFAULT;
	alphaWheelSpeed = ALPHA_WHEEL_SPEED_DEFAULT;
	
	// initialize PID stuff
	Kp = KP_DEFAULT;
	Ki = KI_DEFAULT;
	Kd = KD_DEFAULT;
	N = N_DEFAULT;
	deadZone = DEADZONE_DEFAULT;
	integralMax = INTEGRAL_MAX_DEFAULT;
	
	// initialize SS stuff
	Kf[0] = KF_DEFAULT_0;
	Kf[1] = KF_DEFAULT_1;
	Kf[2] = KF_DEFAULT_2;
	Kf[3] = KF_DEFAULT_3;
	
	controlType = CONTROL_TYPE_DEFAULT;
	estimatorType = ESTIMATOR_TYPE_DEFAULT;
	
	
	
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
	atanAngle = atan2f(ay,az) - orientationOffsetX;
	
	if (angleInitialized)
	{	
		ex = (alphaComplementary) * (ex + gx * actualDtEstimator) + (1-alphaComplementary) * (atanAngle);
	}
	else
	{
		// perhaps do a count in here to get good angles before proceeding
		ex = atanAngle;
		angleInitialized = 1;
	}
		
} // end of updateEulerEstimate

void segControl::updateEstimator(void){
	// update time between estimator calculations
	actualDtEstimator = ((float)(micros() - lastEstimatorMicros)) * 0.000001; // convert to seconds
	lastEstimatorMicros = micros();
		
	switch (estimatorType)
	{
		case ESTIMATOR_COMPLEMENTARY:
			segControl::updateEulerEstimate();
			break;
		case ESTIMATOR_KALMAN:
			// nothing yet - but could be a good opportunity for full Kalman filter with a good system model
			break;
		case ESTIMATOR_NUMERICAL:
			// update the numerical estimates
			
			// update estimate for euler x
			segControl::updateEulerEstimate();
			
			// only wheel speed needs this - everything else is measured or calculated for the state
			x1_dot = (alphaWheelSpeed) * ((x1 - lastx1) / actualDtEstimator) + (1-alphaWheelSpeed) * lastx1_dot;
			// update previous values
			lastx1 = x1;
			lastx1_dot = x1_dot;
			break;
		default:
			break;
	} // end of switch(estimatorType)
} // end of updateEstimator

void segControl::updateController(void){
	// update time between control calculations
	actualDt = ((float)(micros() - lastControlMicros)) * 0.000001; // convert to seconds
	lastControlMicros = micros();

	switch(controlType)
	{
		case CONTROLLER_PID:
			if (angleInitialized)
			{
				// calculate difference between setpoint and actual value
				float error;
				error = 0.0 - ex; // use 0 degrees as the setpoint for now
				// update integral term
				integralTerm += error * actualDt * Ki;
				// check for anti-windup here
				if (integralTerm > integralMax)
				{
					integralTerm = integralMax;
				}
				else if (integralTerm < (-integralMax))
				{
					integralTerm = -integralMax;
				}
		
		
		
				// calculate controller output for PID
				Vout = Kp * error - Kd * gx + integralTerm;
				// use the gyro as the derivative term for now, since for
				// balancing at a setpoint zero, the gyro represents the rate
				// of change of both the angle and the error

				// in the future - add actual filtered derivative?
		
				// check for dead-zone
				if ((Vout > (-deadZone)) && (Vout < deadZone))
				{
					Vout = 0.0;
				}
		
				// saturation will be handled on the robot side
				// because the voltage may be different

				// check for out of range condition
				if ((ex > CONTROLLER_SHUTOFF_ANGLE) || (ex < (-CONTROLLER_SHUTOFF_ANGLE)))
				{
					// Kill output
					Vout = 0.0;
					// reset integral stuff
					integralTerm = 0.0;
				}
			} // if (angleInitialized)
			else
			{
				Vout = 0.0;
			}		
			break;
		case CONTROLLER_SS:
			if (angleInitialized)
			{
				// get the state estimates (numerical observer for now)
				
			
				
				// calculate controller output for State Space 
				// added negative sign around it, because at least for the MinSeg, 
				// this produces the correct motor direction
				
				// also, the body angle (ex) and the body angle rate (gx) are negated
				// here due to the sign convention being opposite of that from the 
				// system model
				Vout = -(Kf[0] * x1 + Kf[1] * x1_dot + Kf[2] * (-ex) + Kf[3] * (-gx));
								
				// check for dead-zone
				if ((Vout > (-deadZone)) && (Vout < deadZone))
				{
					Vout = 0.0;
				}
				
				// saturation will be handled on the robot side
				// because the voltage may be different for each robot

				// check for out of range condition
				if ((ex > CONTROLLER_SHUTOFF_ANGLE) || (ex < (-CONTROLLER_SHUTOFF_ANGLE)))
				{
					// Kill output
					Vout = 0.0;
				}
			} // if (angleInitialized)
			else
			{
				Vout = 0.0;
			}		
			break;
		default:
			break;
	} // end of switch(controlType)
	

	
} // end of updateController