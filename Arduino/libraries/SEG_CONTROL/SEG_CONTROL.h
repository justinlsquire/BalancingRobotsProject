/*
  MINSEG.h - Library for using MinSeg with balancing and estimation library
*/
#ifndef SEG_CONTROL_h
#define SEG_CONTROL_h

#include "Arduino.h"



// define macros here
// enumeration of controller types
#define CONTROLLER_PID 1 // PID Controller
#define CONTROLLER_SS 2 // state space controller

// enumeration of estimator types
#define ESTIMATOR_COMPLEMENTARY 1
#define ESTIMATOR_KALMAN 2
#define ESTIMATOR_NUMERICAL 3

// default controller settings - can be changed in code
#define CONTROL_TYPE_DEFAULT CONTROLLER_PID

// default estimator settings - can be changed in code
#define ESTIMATOR_TYPE_DEFAULT ESTIMATOR_COMPLEMENTARY

//#define ALPHA_COMPLEMENTARY_DEFAULT 0.993 // 99 percent gyro 
#define ALPHA_COMPLEMENTARY_DEFAULT 0.998 // 99 percent gyro 

// percentage given to new value of wheel speed calculation
#define ALPHA_WHEEL_SPEED_DEFAULT 0.85 

// For the MinSeg, the euler estimate produces 90 degrees when upright 
// this needs to be subtracted so it is balancing around the zero position
#define ORIENTATION_OFFSET_DEFAULT 1.5708 // 90 deg offset (converted to rad)


// some default PID values that kind of worked for MinSeg
#define KP_DEFAULT -18.0965 //100
#define KI_DEFAULT 0.0 //10
#define KD_DEFAULT -0.7904 // 0.4
#define N_DEFAULT 0.0 // derivative filter not implemented yet (maybe never)
#define DEADZONE_DEFAULT 0.01 // volts under which motor output is cutoff
#define INTEGRAL_MAX_DEFAULT 10.0 // anti-windup


// some default state space values that worked for MinSeg
//#define KF_DEFAULT_0 -0.3162 // x position
//#define KF_DEFAULT_1 -42.4163 // x velocity
//#define KF_DEFAULT_2 -63.0683 // body angle
//#define KF_DEFAULT_3 -10.5755 // body angular rate

// #define KF_DEFAULT_0 -0.4400 // x position
// #define KF_DEFAULT_1 -0.2919 // x velocity
// #define KF_DEFAULT_2 -28.8721 // body angle
// #define KF_DEFAULT_3 -1.6327 // body angular rate

#define KF_DEFAULT_0 1.2910 // x position
#define KF_DEFAULT_1 12.5746 // x velocity
#define KF_DEFAULT_2 -18.0965 // body angle
#define KF_DEFAULT_3 -0.7904 // body angular rate


// the angle at which the motor output is not active
#define CONTROLLER_SHUTOFF_ANGLE 0.5 // in radians

#define GYRO_DEADBAND 0.02 // gyro is zero outside of this range

// default wheel radius to use in calculations
#define CONTROLLER_WHEEL_RADIUS_DEFUALT 0.022098; // from Minseg M2V5


class segControl
{
  public:
	// everything else is hard-coded
	// only thing we need to set up for now is the led pin
    segControl();
	void setupController(void);
	void updateEstimator(void);
	void updateEulerEstimate(void);
	void updateController(void);
	
	
	
  // variables
  // stuff like motor voltage commands, controller stuff, etc
  
  uint16_t updateRate; // controller update rate (in Hz)
  float dt; // controller update rate (in seconds)
  unsigned long updateDtMicros; // time inverval between controller updates (
  unsigned long lastUpdateTime; // time (micros) for the 
  
  // estimated parameters
  // euler angles
  float ex, ey, ez; // in rad  
  float gx, gy, gz; // in rad/s
  float ax, ay, az; // in g
  
  float exIntegral;
  
  uint8_t angleInitialized;
  
  float orientationOffsetX; // in rad

  float x1; // displacement of motor 1 (left/default)
  float x2; // displacement of motor 2 (right)
  float lastx1; // previous value
  float lastx2; // previous value
  float x1_dot; //angular speed of motor 1 (left/default) 
  float x2_dot;//angular speed of motor 2 (right) 
  float lastx1_dot; // last value (for filtering) 
  float lastx2_dot; // last value (for filtering)
  float wheelIntegralX1;
  
  uint8_t wheelIntegralOnPID;
  
  // wheel radius - that needs to be received from the robot object
  float wheelRadius;
  
  unsigned long lastEstimatorMicros; // last microsecond measurement from estimation routine
  float actualDtEstimator;
  
  float alphaWheelSpeed;

  // controller related
  uint8_t controlType; // PID, State Space, etc. - based on enumeration of the different types

  // PID related
  float Vout1; // calculated motor output voltage
  float Vout2; // motor voltage 2
  float lastErr;
  float Kp; // proportional
  float Ki; // integral
  float Kd; // derivative
  float N; // derivative filter
  float integralTerm; // for keeping track of integral
  float integralMax; // max windup for integral term
  float deadZone; // controller voltage level that remains zero output
  unsigned long lastControlMicros; // last microsecond measurement from control routine
  float actualDt; // time interval between controller updates (calculated each time)
  

  // state space related   
  float Kf[5]; // feedback terms (up to 5 state) for state space control

  // estimation related
  uint8_t estimatorType; // complementary filter, kalman filter, full state feedback, partial estimator, etc.

  float alphaComplementary; // value to use for gyro ((1-alphaComplementary) for accelerometer contribution)

  float Ke[5]; // kalman filter feedback values (up to 5 state)
  
  uint8_t mtrsActive;
	
	
  private:
	// functions or variables 
};

#endif