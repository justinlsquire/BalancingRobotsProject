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
// MinSeg M2V5
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
  controller.updateRate = 200; // in Hz - per function documentation in library

  // pass the robot-specific parameters to the controller object
  controller.wheelRadius = robot.wheelRadius;

  // call the libarary function to take these parameters just entered
  // and do some background calculations to set up the controller for 
  // being ready to use
  controller.setupController();

  // set these based on the true observed values from the sensors 
  // instructions will be done soon
  robot.gx_raw_offset = 373; // gyro offset in raw units
  controller.orientationOffsetX = -1.64; // vertical (balancing) orientation offset in radians
  //robot.encDir = 1; // for older MinSeg M2V5
  robot.encDir = -1; // for newer MinSeg M2V5

  // some experimental PID settings that work well for Minseg M2V5
  controller.Kp = 26;
  controller.Ki = 165;
  controller.Kd = 1.2;

  // set up estimator and controller type here
  controller.estimatorType = ESTIMATOR_NUMERICAL;
  //controller.estimatorType = ESTIMATOR_KALMAN; // needs work - not ready
  controller.controlType = CONTROLLER_SS;
  //controller.controlType = CONTROLLER_PID;

  // in development features
  //controller.wheelIntegralOnPID = 1;


  // update turn timer - not needed currently (Feb, 2020)
  //turnTimer = millis();
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

    // update IMU every iteration through loop
    robot.updateIMU_RAW();
  //}




  /* Turn Related Stuff - not functional currently
  if ((millis() - turnTimer) >= 25000)
  {
    robot.endTurn();
  }
  else if ((millis() - turnTimer) >= 20000)
  {
    // start the turning
    //robot.beginTurn(RIGHT,10);
  }
  */


  // Call function to check for serial data being sent to update PID and settings
  checkForSerial();
  
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
  
  // and then pass it to the controller object
  
  // accelerometer value in the vertical (gravity) direction 
  controller.ay = robot.ay;
  // accelerometer value in the horizontal direction
  controller.az = robot.az;
  // gyro value around the rotational axis of the robot
  controller.gx = robot.gx;
  // encoder distance traveled
  controller.x1 = robot.x1;
  //controller.x2 = robot.x2; // second encoder not used currently (Feb 2020)

  // update estimator for control feedback signals
  controller.updateEstimator();


  //*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^
  // Sensor calibration steps 
  //*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^
  
  // 1) Raw average gyro values - leave robot untouched on any surface,
  //    uncomment the line below, upload code, and watch serial monitor
  //    to see the output - use this value to set robot.gx_raw_offset (in setup)
  //Serial.println(robot.getGyroXAvg());

  // comment the line out again before moving on.

  // you can confirm that the gyro offset worked by uncommenting this line
  //Serial.println(robot.gx*57.4);
  // (it should be around 0 when the robot is sitting still on any surface)

  
  // 2) Vertical orientation offset
  //    uncomment the line below, upload code, and watch serial monitor while trying to
  //    carefully hold the robot vertically balanced (gently using your fingers to maintain it
  //    around the balance point)
  //    use the value to set robot.orientationOffsetX (in setup)
  //Serial.println(robot.getOrientationOffset()*100);

  // comment the line out again before moving on.

  // you can confirm that the offset worked by uncommenting this line
  //Serial.println(controller.ex*57.4);
  // (it should be around 0 when the robot is vertical)

  // temporary stuff for debugging only
  // ---------------------------------------------
  //Serial.println(robot.getGyroXRaw());
  //Serial.println(robot.gxFifoAvg);
  //Serial.println(robot.gx);
  //Serial.println(robot.getAccYRaw());
  //Serial.println(robot.az);
  //Serial.println(controller.ex*57.4);
  //Serial.println(controller.x1_dot);
  //Serial.println(controller.x1);
  //Serial.println(robot.mtr1Speed);
  // ---------------------------------------------


  //*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^
  // End of sensor calibration steps 
  //*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^
  
  // update controller output (calculate it)
  controller.updateController();
  // debugging output
  //Serial.println(controller.Vout1);

  // this is detected based on the body angle of the robot
  // if the robot is tilted past about 30 degrees
  robot.mtrsActive = controller.mtrsActive;
  
  // update actuator with this output
  robot.updateMotor1(controller.Vout1); 
  // if the robot has two motors, uncomment and figure out this part
  robot.updateMotor2(controller.Vout1);
} // end of controller update




void checkForSerial(void)
{
  // variable to hold the command code received over serial
  int commandCode;
  // string to hold data for values
  String recvString = "";
  // temporary byte for reading bytes we don't care about
  int trash;
  // temporary character for reading into string
  int inChar;
  // temporary integer for conversion to value
  int tempInt;
  
  if (Serial.available()>=5)
  {
    // check to see if the command code is present, otherwise flush
    
    commandCode = Serial.read();

    switch(commandCode)
    {
      case 'P':
        while(Serial.available()>0)
        {
          inChar = Serial.read();
          if(isDigit(inChar))
          {
            recvString += (char)inChar;
          }          
        }
        tempInt = recvString.toInt();
        // assign Kp value
        controller.Kp = ((float)(tempInt));
        Serial.print('P');
        Serial.println(tempInt);
        break;
      case 'I':
        while(Serial.available()>0)
        {
          inChar = Serial.read();
          if(isDigit(inChar))
          {
            recvString+= (char)inChar;
          }          
        }
        tempInt = recvString.toInt();
        // assign Ki value
        controller.Ki = ((float)(tempInt));
        Serial.print('I');
        Serial.println(tempInt);  
        // zero the integral term
        controller.integralTerm = 0;
        break;
      case 'D':
        while(Serial.available()>0)
        {
          inChar = Serial.read();
          if(isDigit(inChar))
          {
            recvString+= (char)inChar;
          }          
        }
        tempInt = recvString.toInt();
        // assign Kd value
        controller.Kd = ((float)(tempInt))*0.01; // Kd is x 100
        Serial.print('D');
        Serial.println(tempInt);        
        break;
      case 'W':
        while(Serial.available()>0)
        {
          inChar = Serial.read();
          if(isDigit(inChar))
          {
            recvString+= (char)inChar;
          }          
        }
        tempInt = recvString.toInt();

        if (tempInt == 0)
        {
          controller.wheelIntegralOnPID = 0;
        }
        else if (tempInt == 1)
        {
          controller.wheelIntegralOnPID = 1;
          // zero the integral
          controller.wheelIntegralX1 = 0;
        }
        // assign Kd value
        //controller.Kd = -((float)(tempInt))*0.01; // Kd is x 100
        Serial.print('W');
        Serial.println(tempInt);        
        break;        
      default:
        // read out the rest of the bytes to clear it, since we didn't receive a valid command code
        while(Serial.available())
        {
          trash = Serial.read();        
        }
        break;
    } // end of switch(commandCode)
  } // end of if(Serial.available()>=5)
} // end of checkForSerial function

/*---------------------------------------------------------------------------------------------------------------
  ______           _   _    _                 ______                _   _                 
 |  ____|         | | | |  | |               |  ____|              | | (_)                
 | |__   _ __   __| | | |  | |___  ___ _ __  | |__ _   _ _ __   ___| |_ _  ___  _ __  ___ 
 |  __| | '_ \ / _` | | |  | / __|/ _ \ '__| |  __| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 | |____| | | | (_| | | |__| \__ \  __/ |    | |  | |_| | | | | (__| |_| | (_) | | | \__ \
 |______|_| |_|\__,_|  \____/|___/\___|_|    |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/                                                                                                                                                                                    
/*---------------------------------------------------------------------------------------------------------------*/
