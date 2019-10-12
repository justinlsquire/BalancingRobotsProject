// NOTE: word art generated from here: http://patorjk.com/software/taag/ - font 'Big' - default settings

/*---------------------------------------------------------------------------------------------------------------

  _____        __ _              _      _ _                    _           
 |  __ \      / _(_)            | |    (_) |                  (_)          
 | |  | | ___| |_ _ _ __   ___  | |     _| |__  _ __ __ _ _ __ _  ___  ___ 
 | |  | |/ _ \  _| | '_ \ / _ \ | |    | | '_ \| '__/ _` | '__| |/ _ \/ __|
 | |__| |  __/ | | | | | |  __/ | |____| | |_) | | | (_| | |  | |  __/\__ \
 |_____/ \___|_| |_|_| |_|\___| |______|_|_.__/|_|  \__,_|_|  |_|\___||___/                                                                                                                                                   
/*---------------------------------------------------------------------------------------------------------------*/

// hardware-dependent library for robots
// Choose which library to use, based on the hardware
//#include<BALBOA.h> 
//#include <MINSEG.h>
#include <MINSEG_V2.h>
// platform-independent control and estimation library
#include <SEG_CONTROL.h> 

// create object for the robot (either Minseg or Balboa)
// but it must be called 'robot' for the code to work correctly
//Balboa robot; 
Minseg robot; 

// create object for the controller (universal)
segControl controller;

unsigned long lastUpdateMicrosIMU;

unsigned long turnTimer;


//*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*
//*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*
//*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*


/*---------------------------------------------------------------------------------------------------------------
  ____             _                          _       _                _____      _               
 |  _ \           (_)           /\           | |     (_)              / ____|    | |              
 | |_) | ___  __ _ _ _ __      /  \   _ __ __| |_   _ _ _ __   ___   | (___   ___| |_ _   _ _ __  
 |  _ < / _ \/ _` | | '_ \    / /\ \ | '__/ _` | | | | | '_ \ / _ \   \___ \ / _ \ __| | | | '_ \ 
 | |_) |  __/ (_| | | | | |  / ____ \| | | (_| | |_| | | | | | (_) |  ____) |  __/ |_| |_| | |_) |
 |____/ \___|\__, |_|_| |_| /_/    \_\_|  \__,_|\__,_|_|_| |_|\___/  |_____/ \___|\__|\__,_| .__/ 
              __/ |                                                                        | |    
             |___/                                                                         |_|    
/*---------------------------------------------------------------------------------------------------------------*/
void setup() {
  // delay - temporary for debugging
  //delay(3000);
  // initialize the serial port for communications
  Serial.begin(115200);

  // call the library function to set up and initialize all
  // the platform specific hardware (ports, pins, peripherals, etc.)
  robot.setupHardware(); // sets up all of the stock hardware on the robot

 // delay(3000);

  // configure the controller for this application
  controller.updateRate = 200; // in Hz - per function documentation

  // call the libarary function to take these parameters just entered
  // and do some background calculations to set up the controller for 
  // being ready to use
  controller.setupController();

  // temporary - for my setup with MinSeg - JS/28Jul2019
  //robot.gx_raw_offset = -60; // my gyro offset 
  robot.gx_raw_offset = 180; // my gyro offset 
  controller.orientationOffsetX = -1.57; // radians - mine is not too straight because I broke it and had to repair it
  //controller.orientationOffsetX = -1.7; // radians - mine is not too straight because I broke it and had to repair it

  // some experimental PID settings, before moving on to state space
  controller.Kp = 65;
  controller.Kp = 26;
  //controller.Kp = 130;
  controller.Ki = 165;
  controller.Kd = 1.2;

  // set up numerical estimator and state space controller for now
  controller.estimatorType = ESTIMATOR_NUMERICAL;
  controller.controlType = CONTROLLER_SS;

  
  //robot.clearIMU_FIFO();


  // update turn timer
  turnTimer = millis();
} // end of setup()
/*---------------------------------------------------------------------------------------------------------------
  ______           _                    _       _                _____      _               
 |  ____|         | |     /\           | |     (_)              / ____|    | |              
 | |__   _ __   __| |    /  \   _ __ __| |_   _ _ _ __   ___   | (___   ___| |_ _   _ _ __  
 |  __| | '_ \ / _` |   / /\ \ | '__/ _` | | | | | '_ \ / _ \   \___ \ / _ \ __| | | | '_ \ 
 | |____| | | | (_| |  / ____ \| | | (_| | |_| | | | | | (_) |  ____) |  __/ |_| |_| | |_) |
 |______|_| |_|\__,_| /_/    \_\_|  \__,_|\__,_|_|_| |_|\___/  |_____/ \___|\__|\__,_| .__/ 
                                                                                     | |    
                                                                                     |_|    
/*---------------------------------------------------------------------------------------------------------------*/

//*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*
//*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*
//*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*

/*---------------------------------------------------------------------------------------------------------------
  ____             _                          _       _               _                       
 |  _ \           (_)           /\           | |     (_)             | |                      
 | |_) | ___  __ _ _ _ __      /  \   _ __ __| |_   _ _ _ __   ___   | |     ___   ___  _ __  
 |  _ < / _ \/ _` | | '_ \    / /\ \ | '__/ _` | | | | | '_ \ / _ \  | |    / _ \ / _ \| '_ \ 
 | |_) |  __/ (_| | | | | |  / ____ \| | | (_| | |_| | | | | | (_) | | |___| (_) | (_) | |_) |
 |____/ \___|\__, |_|_| |_| /_/    \_\_|  \__,_|\__,_|_|_| |_|\___/  |______\___/ \___/| .__/ 
              __/ |                                                                    | |    
             |___/                                                                     |_|    
/*---------------------------------------------------------------------------------------------------------------*/
void loop() {

  // check the timer to see if it is time to 
  // run the controller update
  if ((micros() - controller.lastUpdateTime) >= controller.updateDtMicros)
  {
    // reset the last time to the current time - so that 
    // next time we go to this loop, we will be operating 
    // on the updated value
    controller.lastUpdateTime = micros();
    // call the update function
    controllerUpdate();
  } // end of if - for time inverval check

  //robot.updateIMU_FIFO();

  //if ((micros() - lastUpdateMicrosIMU) >= 1000)
  //{
   // lastUpdateMicrosIMU = micros();
    // update the IMU stuff
    robot.updateIMU_RAW();
  //}




  if ((millis() - turnTimer) >= 25000)
  {
    robot.endTurn();
  }
  else if ((millis() - turnTimer) >= 20000)
  {
    // start the turning
    //robot.beginTurn(RIGHT,10);
  }

  
} // end of loop()

/*---------------------------------------------------------------------------------------------------------------
  ______           _                    _       _               _                       
 |  ____|         | |     /\           | |     (_)             | |                      
 | |__   _ __   __| |    /  \   _ __ __| |_   _ _ _ __   ___   | |     ___   ___  _ __  
 |  __| | '_ \ / _` |   / /\ \ | '__/ _` | | | | | '_ \ / _ \  | |    / _ \ / _ \| '_ \ 
 | |____| | | | (_| |  / ____ \| | | (_| | |_| | | | | | (_) | | |___| (_) | (_) | |_) |
 |______|_| |_|\__,_| /_/    \_\_|  \__,_|\__,_|_|_| |_|\___/  |______\___/ \___/| .__/ 
                                                                                 | |    
                                                                                 |_|    
/*---------------------------------------------------------------------------------------------------------------*/

//*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*
//*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*
//*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*

/*---------------------------------------------------------------------------------------------------------------
  ____             _         _    _                 ______                _   _                 
 |  _ \           (_)       | |  | |               |  ____|              | | (_)                
 | |_) | ___  __ _ _ _ __   | |  | |___  ___ _ __  | |__ _   _ _ __   ___| |_ _  ___  _ __  ___ 
 |  _ < / _ \/ _` | | '_ \  | |  | / __|/ _ \ '__| |  __| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 | |_) |  __/ (_| | | | | | | |__| \__ \  __/ |    | |  | |_| | | | | (__| |_| | (_) | | | \__ \
 |____/ \___|\__, |_|_| |_|  \____/|___/\___|_|    |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
              __/ |                                                                             
             |___/                                                                              
/*---------------------------------------------------------------------------------------------------------------*/
void controllerUpdate(void)
{
  // update sensors on the robot hardware
  robot.updateAccel();
  robot.updateGyro();
  robot.updateEncoders();
  
  // and pass it to the controller object
  
  // accelerometer value in the vertical (gravity) direction 
  controller.ay = robot.ay;
  // accelerometer value in the horizontal direction
  controller.az = robot.az;
  // gyro value around the rotational axis of the robot
  controller.gx = robot.gx;
  // encoder distance traveled
  controller.x1 = robot.x1;
  //controller.x2 = robot.x2;

  
  
  // update estimator (if present)
  controller.updateEstimator();

  // temporary stuff for debugging 
  //Serial.println(robot.getGyroXRaw());
  //Serial.println(robot.gxFifoAvg);
  //Serial.println(robot.gx);
  //Serial.println(robot.getAccYRaw());
  //Serial.println(robot.az);
  Serial.println(controller.ex*57.4);
  //Serial.println(controller.x1_dot);
  //Serial.println(controller.x1);
  //Serial.println(robot.mtr1Speed);
  
  // update controller output (calculate it)
  controller.updateController();
  //Serial.println(controller.Vout1);

  //controller.Vout1 = 2;

  robot.mtrsActive = controller.mtrsActive;
  
  // update actuator with this output
  robot.updateMotor1(controller.Vout1); 
  // if the robot has two motors, uncomment and figure out this part
  robot.updateMotor2(controller.Vout1);
} // end of controller update

/*---------------------------------------------------------------------------------------------------------------
  ______           _   _    _                 ______                _   _                 
 |  ____|         | | | |  | |               |  ____|              | | (_)                
 | |__   _ __   __| | | |  | |___  ___ _ __  | |__ _   _ _ __   ___| |_ _  ___  _ __  ___ 
 |  __| | '_ \ / _` | | |  | / __|/ _ \ '__| |  __| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 | |____| | | | (_| | | |__| \__ \  __/ |    | |  | |_| | | | | (__| |_| | (_) | | | \__ \
 |______|_| |_|\__,_|  \____/|___/\___|_|    |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/                                                                                                                                                                                    
/*---------------------------------------------------------------------------------------------------------------*/
