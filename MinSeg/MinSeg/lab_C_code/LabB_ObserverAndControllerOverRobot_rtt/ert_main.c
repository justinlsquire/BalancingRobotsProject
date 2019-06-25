/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'LabB_ObserverAndControllerOverRobot'.
 *
 * Model version                  : 1.697
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Wed Dec 14 11:33:47 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LabB_ObserverAndControllerOverRobot.h"
#include "Arduino.h"
#include "io_wrappers.h"
#define STEP_SIZE                      (unsigned long) (5000)

int_T main(void)
{
  unsigned long oldtime = 0L;
  unsigned long actualtime;
  init();
  LabB_ObserverAndControllerOverRobot_initialize();

  /* This pin indicates the base rate overrun */
  pinMode(13, OUTPUT);
  digitalWrite(13, 0);

#ifdef _RTT_USE_SERIAL0_

  Serial_begin(0, 115200);
  Serial_write(0, "***starting the model***", 26);

#endif

#ifdef _RTT_USE_SERIAL1_

  Serial_begin(1, 9600);

#endif

#ifdef _RTT_USE_SERIAL2_

  Serial_begin(2, 9600);

#endif

#ifdef _RTT_USE_SERIAL3_

  Serial_begin(3, 9600);

#endif

  /* The main step loop */
  while (rtmGetErrorStatus(LabB_ObserverAndControllerOv_M) == (NULL)) {
    actualtime = micros();
    if ((unsigned long) (actualtime - oldtime) >= STEP_SIZE) {
      oldtime = actualtime;
      LabB_ObserverAndControllerOverRobot_output();

      /* Get model outputs here */
      LabB_ObserverAndControllerOverRobot_update();

      /* Check for overrun */
      if ((unsigned long) (micros() - oldtime) > STEP_SIZE) {
        digitalWrite(13, 1);
      }
    }
  }

  LabB_ObserverAndControllerOverRobot_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
