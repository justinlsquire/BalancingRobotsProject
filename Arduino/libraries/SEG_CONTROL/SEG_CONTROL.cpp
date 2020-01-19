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
		ex = (alphaComplementary) * (ex + gx * actualDtEstimator) + (1-alphaComplementary) * (atanAngle);
		
		// wait until it is close to the balance point to start
		if ((ex > (-.05)) && (ex < 0.05))
		{
			angleInitialized = 1;
		}
		exIntegral += ex * actualDtEstimator;
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
				//Vout1 = Kp * error - Kd * gx + integralTerm;
				
				
				float dTerm;
				
				//dTerm = (error - lastErr) / actualDt;
				
				if ((gx > (-GYRO_DEADBAND)) && (gx < GYRO_DEADBAND))
				{
					dTerm = 0;
				}
				else
				{
					dTerm = -gx;
				}
				
				
				//wheelIntegralX1 += (ex-x1) * actualDt;
				wheelIntegralX1 += (x1) * actualDt;
				
				
				
				Serial.println(x1);
				//Serial.println(wheelIntegralX1);
				
				
				/*
				if (wheelIntegralX1 > 6)
				{
					wheelIntegralX1 = 6;
				}
				else if (wheelIntegralX1 < (-6))
				{
					wheelIntegralX1 = -6;
				}
				//wheelIntegralX1 = 0.3 * x1;
				*/
				
				Vout1 = Kp * error + Kd * dTerm + integralTerm;// + 5.0 * x1_dot;// - wheelIntegralX1;// - x1 * 2;
				//Vout1 -= wheelIntegralX1;// * (0.01);
				//Vout1 += 0.5 * (x1_dot + dTerm);
				//Vout1 += 1.5 * wheelIntegralX1;
				//Vout1 += 0.5 * wheelIntegralX1;
				Vout1 += 0.5 * x1;
				Vout1 += 0.3 * (x1_dot+dTerm);
				
				// use the gyro as the derivative term for now, since for
				// balancing at a setpoint zero, the gyro represents the rate
				// of change of both the angle and the error

				// in the future - add actual filtered derivative?
				
				lastErr = error;
		
				// check for dead-zone
				if ((Vout1 > (-deadZone)) && (Vout1 < deadZone))
				{
					Vout1 = 0.0;
				}
		
				// saturation will be handled on the robot side
				// because the voltage may be different

				// check for out of range condition
				if ((ex > CONTROLLER_SHUTOFF_ANGLE) || (ex < (-CONTROLLER_SHUTOFF_ANGLE)))
				{
					// Kill output
					Vout1 = 0.0;
					// reset integral stuff
					integralTerm = 0.0;
					// set flag
					mtrsActive = 0;
				}
				else
				{
					mtrsActive = 1;
				}
			} // if (angleInitialized)
			else
			{
				Vout1 = 0.0;
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
				
				
				// collect terms as in Simulink model 
				float x_;
				float xdot_;
				float alpha_;
				float alphadot_;
				
				x_ = ex - x1;
				xdot_ = gx - x1_dot;
				alpha_ = ex;
				alphadot_ = gx;
				
				//Vout1 = -(Kf[0] * x1 + Kf[1] * x1_dot + Kf[2] * (-ex) + Kf[3] * (-gx));
				Vout1 = (Kf[0] * x_ + Kf[1] * xdot_ + Kf[2] * alpha_ + Kf[3] * alphadot_);
				
				
				// add integral action
				//Vout1 += (0.01 * exIntegral);
				
				//Vout1 *= 1.5;
				
				// apply control output filter?
				
								
				// check for dead-zone
				if ((Vout1 > (-deadZone)) && (Vout1 < deadZone))
				{
					Vout1 = 0.0;
				}
				
				// saturation will be handled on the robot side
				// because the voltage may be different for each robot

				// check for out of range condition
				if ((ex > CONTROLLER_SHUTOFF_ANGLE) || (ex < (-CONTROLLER_SHUTOFF_ANGLE)))
				{
					// Kill output
					Vout1 = 0.0;
					// set flag
					mtrsActive = 0;					
				}
				else
				{
					mtrsActive = 1;
				}
			} // if (angleInitialized)
			else
			{
				Vout1 = 0.0;
			}		
			break;
		default:
			break;
	} // end of switch(controlType)
	

	
} // end of updateController