// This library must be installed through libraries manager
#include <TimerOne.h>

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"




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

#define CONTROL_PERIOD 50000 // in microseconds (50 ms interval by default)

#define MAX_VOLTAGE 6.0
#define MAX_INTEGRAL 6.0



// define variables here
MPU6050 accelgyro;

volatile int16_t ax, ay, az; // raw values for accelerometer
volatile int16_t gx, gy, gz; // raw values for gyro

int16_t gx_offset = -346;//0; // for calibration of gyro offset

volatile float eX; // euler angle in rad
volatile float gX; // rate in rad/s
volatile float gXfilt; // filtered gyro for Kd
volatile float lastgXfilt;

volatile float Kp = 90.0;
volatile float Kd = 8.0;
volatile float Ki = 0.0;
volatile float integralTerm = 0.0;

volatile float vOut = 0.0;

volatile float alfaGyro = 0.85; // amount of weight given to new value of gyro



uint8_t imuFeedbackAvailable = 0; // initialize false

// encoder count
volatile long encCnt = 5;
long encCntCopy = 0;

// timer variables
unsigned long controlTimer = 0;
float dt = 0.0;
unsigned long dtInt = 0;

// motor variables
int mtrOut = 0;
uint8_t tempMtrOut = 255;
uint8_t rising = 1;






// define functions here
void controllerUpdate(void)
{
  // get sensor data
    // IMU
    // read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // these methods (and a few others) are also available
    //accelgyro.getAcceleration(&ax, &ay, &az);
    //LED_PORT ^= (1<<LED_PORT_OFFSET);
    //accelgyro.getRotation(&gx, &gy, &gz);    

    // subtract off the offset
    gx -= gx_offset;

    // convert to rad/s (extracted from datasheet)

    // negate here for correct movement
    gX = -(gx * .000133231241);

    gXfilt = (alfaGyro) * gX + (1-alfaGyro) * lastgXfilt;
    lastgXfilt = gXfilt;

    // get time since last measurement
    dt = (micros()-dtInt) * 0.000001;
    // reset it
    dtInt = micros();
    

    // update Euler integrated angle
    eX += gX * dt;

    
    

    // encoder

  // Calculate feedback control law

  integralTerm += Ki * eX * dt;

  // check for anti-windup
  if (integralTerm > MAX_INTEGRAL)
  {
    integralTerm = MAX_INTEGRAL;
  }
  else if (integralTerm < (-MAX_INTEGRAL))
  {
    integralTerm = -MAX_INTEGRAL;
  }

  vOut = Kp * eX + Kd * gX + integralTerm;

  // check for voltage saturation
  if (vOut > MAX_VOLTAGE)
  {
    vOut = MAX_VOLTAGE;
  }
  else if (vOut < (-MAX_VOLTAGE))
  {
    vOut = -MAX_VOLTAGE;
  }

  // scale voltage 
  mtrOut = (int16_t)(vOut / (MAX_VOLTAGE) * 255.0);
  

  // update motor command
  if (mtrOut < 0)
  {
    // set direction 0
    MTR_DIR_PORT &= ~(1<<MTR_DIR_OFFSET);
    tempMtrOut = -mtrOut;
  }
  else
  {
    // set direction 1
    MTR_DIR_PORT |= (1<<MTR_DIR_OFFSET);
    tempMtrOut = 255-mtrOut;
  }

  // write PWM
  analogWrite(MTR_PWM_PIN,tempMtrOut);
  

  // toggle LED
  LED_PORT ^= (1<<LED_PORT_OFFSET);
} // end of controllerupdate





void setupLED(void)
{
  // set as output
  pinMode(LED_PIN,OUTPUT);
  // turn off initially
  digitalWrite(LED_PIN,0);
}



void setupMotor(void)
{
  pinMode(MTR_PWM_PIN,OUTPUT); // PWM pin for motor driver
  pinMode(MTR_DIR_PIN,OUTPUT); // direction pin for motor driver

  // set at 0 initially
  digitalWrite(MTR_DIR_PIN,LOW);
  analogWrite(MTR_PWM_PIN,0);
  
} // end of setupMotor


void setupEncoder(void)
{
  // encoder is on pins 2 and 3
  // set up pullup resistors to prevent floating
  pinMode(ENC1_PIN,INPUT_PULLUP);
  pinMode(ENC2_PIN,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(2),enc1ISR,CHANGE);
  attachInterrupt(digitalPinToInterrupt(3),enc2ISR,CHANGE);
  
} // end of setupEncoder

void enc1ISR(void)
{
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

void enc2ISR(void)
{
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



uint8_t setupIMU(void)
{
  uint8_t imuWorking = 0; // initialize false
   
  Wire.begin();
  // test connection
  imuWorking = accelgyro.testConnection();

  
  accelgyro.setDLPFMode(5);
  accelgyro.initialize();



  return(imuWorking);
} // end of setupIMU


void calibrateIMU(void)
{
  // read the values and get the offsets
  float gxAvg = 0.0;
  uint8_t calCnt = 100;
  uint16_t tempX;
  
  for (int i = 0; i < calCnt; i++)
  {
    tempX = accelgyro.getRotationX();
    gxAvg += ((float)tempX)/((float)calCnt);
  }

  gx_offset = (int16_t)gxAvg;
  
} // end of calibrateIMU

void setup(void)
{
  // Set up serial port
  Serial.begin(115200);

  // Set up LED
  setupLED();

  // delay for a bit to distinguish LED
  delay(1000);
  
  // set up motor pins and ports
  setupMotor();

  // set up encoder pins and ports
  setupEncoder();

  // set up IMU stuff
  setupIMU();

  // set up LED
  if (setupIMU())
  {
    // set global flag true (it was initialized false)
    imuFeedbackAvailable = 1;

    // calibrate gyro
    //calibrateIMU();

    // turn on LED
    for (int i = 0; i < 10; i++)
    {
      digitalWrite(LED_PIN,1);
      delay(50);
      digitalWrite(LED_PIN,0);
      delay(50);
    }
    digitalWrite(LED_PIN,1);
  } // end of if(setupIMU())
  

  delay(1000);

  // set up timer for controller 
  //Timer1.initialize(150000);
  //Timer1.attachInterrupt(controllerUpdate); // controllerUpdate to run every 50 ms

} // end of setup




void loop(void)
{
  //unsigned long blinkCopy;  // holds a copy of the blinkCount

  // to read a variable which the interrupt code writes, we
  // must temporarily disable interrupts, to be sure it will
  // not change while we are reading.  To minimize the time
  // with interrupts off, just quickly make a copy, and then
  // use the copy while allowing the interrupt to keep working.
  //noInterrupts();
  // update copy variables
 // encCntCopy = encCnt;
 // interrupts();

  // write out serial data

  if ((micros() - controlTimer) >= CONTROL_PERIOD)
  {
    // reset timer
    controlTimer = micros();
    // call service routine
    controllerUpdate();
  }

//  Serial.print(encCnt);
//  Serial.print(',');
//  Serial.print(mtrOut);
//  Serial.print(',');
//  Serial.println(gx);

  //Serial.println(eX);
  //Serial.println(gXfilt);
  Serial.println(vOut);
  //Serial.println(gx_offset);
  
}
