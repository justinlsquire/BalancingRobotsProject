//balanceLibrary.h
#ifndef BALANCELIBRARY_h
#define BALANCELIBRARY_h                   

//#ifdef __cplusplus
//extern "C"{
//#endif

#include <stdint.h>

// enumeration of controller types
#define CONTROLLER_PID 1
#define CONTROLLER_SS 2

// enumeration of estimator types
#define ESTIMATOR_COMPLEMENTARY 1
#define ESTIMATOR_KALMAN 2

    struct robot {
        uint16_t updateRate; // controller update rate (in Hz)
        float updateDt; // time interval between controller updates (calculated each time)

        // motor related
        uint8_t numberMotors;
        struct motor * motor1; // the default motor if 1 motor
        struct motor * motor2; // second motor if there are two

        // displacement related
        float wheelRadius; // radius (in meters) of wheel(s) used 
        float gearRatio; // total gear ratio from motor output to wheel output
        float x1; // displacement of motor 1 (left/default)
        float x2; // displacement of motor 2 (right)

        // IMU related
        uint8_t hasAccel; // flag for whether or not it has accelerometer
        uint8_t hasMagnetometer; // flag for whether or not it has magnetometer

        // gyro
        int16_t gx_raw, gy_raw, gz_raw; // raw (integer) values of gyro
        int16_t gx_raw_offset, gy_raw_offset, gz_raw_offset; // raw (integer) offset values of gyro
        float gx_scale, gy_scale, gz_scale; // scale factors for converting raw gyro values to g* (rad/s)
        float gx, gy, gz; // gyro values (in rad/s)

        // accelerometer
        int16_t ax_raw, ay_raw, az_raw; // raw (integer) values of accelerometer
        int16_t ax_raw_offset, ay_raw_offset, az_raw_offset; // raw (integer) offset values of accelerometer
        float ax_scale, ay_scale, az_scale; // scale factor for converting a*_raw to a* (in g); 
        float ax, ay, az; // acceleration values (in g)

        // magnetometer
        int16_t mx_raw, my_raw, mz_raw; // raw (integer) values of magnetometer
        int16_t mx_raw_offset, my_raw_offset, mz_raw_offset; // raw (integer) offset values of magnetometer
        float mx_scale, my_scale, mz_scale; // scale factor for converting m*_raw to m* (gauss)
        float mx, my, mz; 

        // euler angles
        float ex, ey, ez; // in rad

        // controller related
        uint8_t controlType; // PID, State Space, etc. - based on enumeration of the different types

        // PID related
        float Kp; // proportional
        float Ki; // integral
        float Kd; // derivative
        float N; // derivative filter
        float integralTerm; // for keeping track of integral
        float integralMax; // max windup for integral term
        float deadZone; // controller voltage level that remains zero output

        // state space related
        float Kf[5]; // feedback terms (up to 5 state) for state space control

        // estimation related
        uint8_t estimatorType; // complementary filter, kalman filter, full state feedback, partial estimator, etc.

        float alphaComplementary; // value to use for gyro ((1-alphaComplementary) for accelerometer contribution)

        float Ke[5]; // kalman filter feedback values (up to 5 state) 
    };

    struct motor {
        uint8_t active; // 0 = inactive, 1 = active
        uint8_t mtrDirection; // 0 = normal, 1 = inverted
        float maxVoltage; // max motor voltage
        uint8_t hasEncoder; // 0 = no encoder on motor, 1 = motor on encoder
        struct encoder * enc; // structure of the encoder - only applicable if hasEncoder == 1
        uint8_t dutyCycle; // duty cycle of motor for pwm
        float speed; // angular speed of motor in rad/s
    }; 

    struct encoder {
        long counts; // counts (+ or -) of the encoder pulses
        uint16_t cpr; // counts per revolution of motor
        uint8_t encDirection; // 0 = normal, 1 = inverted
    }; 


    // function prototypes
    void updateController(struct robot * rbt);


//#ifdef __cplusplus
//} // extern "C"
//#endif

#endif