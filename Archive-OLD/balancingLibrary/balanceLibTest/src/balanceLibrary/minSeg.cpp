#include "minSeg.h"


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

/*
void setupEncoder(void)
{
  // encoder is on pins 2 and 3
  // set up pullup resistors to prevent floating
  pinMode(ENC1_PIN,INPUT_PULLUP);
  pinMode(ENC2_PIN,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(2),enc1ISR,CHANGE);
  attachInterrupt(digitalPinToInterrupt(3),enc2ISR,CHANGE);
  
} // end of setupEncoder

*/


/*
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

*/