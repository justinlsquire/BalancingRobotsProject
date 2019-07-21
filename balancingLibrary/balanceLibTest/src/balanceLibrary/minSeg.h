//minSeg.h
#ifndef MINSEG_h
#define MINSEG_h                   


//#ifdef __cplusplus
//extern "C"{
//#endif

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include "balanceLibrary.h"
#include "Arduino.h"


// define macros here
#define MTR_DIR_PIN 4
#define MTR_PWM_PIN 5
#define MTR_DIR_PORT PORTG
#define MTR_DIR_OFFSET 5 // PG5 - digital pin 4

#define ENC1_PIN 2
#define ENC2_PIN 3
#define ENC_READ_PORT PINE
#define ENC1_PORT_OFFSET 4 // PE4 - digital pin 2
#define ENC2_PORT_OFFSET 5 // PE5 - digital pin 3

#define LED_PIN 13 // digital pin 13
#define LED_PORT PORTB // PB7
#define LED_PORT_OFFSET 7 // PB7 - digital pin 13

#define MAX_VOLTAGE 6.0
#define MAX_INTEGRAL 6.0
    
// define variables here
//MPU6050 accelgyro;


    // function prototypes
    //void updateIMU(struct robot * rbt);
    void setupLED(void);
    void setupMotor(void);
    //void setupEncoder(void);

//#ifdef __cplusplus
//} // extern "C"
//#endif

#endif

