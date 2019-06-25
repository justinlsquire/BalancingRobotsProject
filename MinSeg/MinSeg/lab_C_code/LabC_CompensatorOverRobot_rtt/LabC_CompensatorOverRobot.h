/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabC_CompensatorOverRobot.h
 *
 * Code generated for Simulink model 'LabC_CompensatorOverRobot'.
 *
 * Model version                  : 1.702
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Thu Dec 15 23:08:47 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LabC_CompensatorOverRobot_h_
#define RTW_HEADER_LabC_CompensatorOverRobot_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef LabC_CompensatorOverRobot_COMMON_INCLUDES_
# define LabC_CompensatorOverRobot_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_serialwrite_lct.h"
#include "arduino_digitaloutput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* LabC_CompensatorOverRobot_COMMON_INCLUDES_ */

#include "LabC_CompensatorOverRobot_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Add[3];                       /* '<S4>/Add' */
  real_T Add3[4];                      /* '<S4>/Add3' */
  real32_T TSamp;                      /* '<S9>/TSamp' */
  real32_T TSamp_n;                    /* '<S10>/TSamp' */
  real32_T converttoradianssec;        /* '<S2>/convert to radians//sec' */
  int16_T Encoder_o1;                  /* '<S3>/Encoder ' */
  int16_T Encoder_o2;                  /* '<S3>/Encoder ' */
  int16_T GyroandAccelerometer_o1;     /* '<S3>/Gyro and Accelerometer' */
  int16_T GyroandAccelerometer_o2;     /* '<S3>/Gyro and Accelerometer' */
  int16_T GyroandAccelerometer_o3;     /* '<S3>/Gyro and Accelerometer' */
  uint8_T DataTypeConversion;          /* '<S58>/Data Type Conversion' */
  uint8_T DataTypeConversion_b;        /* '<S59>/Data Type Conversion' */
} BlockIO_LabC_CompensatorOverRob;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Encoder_DSTATE;               /* '<S3>/Encoder ' */
  real_T Internal_1_1_DSTATE;          /* '<S11>/Internal_1_1' */
  real_T Internal_2_2_DSTATE;          /* '<S11>/Internal_2_2' */
  real_T Internal_3_3_DSTATE;          /* '<S11>/Internal_3_3' */
  real_T Internal_4_4_DSTATE;          /* '<S11>/Internal_4_4' */
  real_T Internal_1_1_DSTATE_m;        /* '<S12>/Internal_1_1' */
  real_T Internal_2_2_DSTATE_p;        /* '<S12>/Internal_2_2' */
  real_T Internal_3_3_DSTATE_o;        /* '<S12>/Internal_3_3' */
  real_T GyroandAccelerometer_DSTATE;  /* '<S3>/Gyro and Accelerometer' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S8>/FromWs' */

  real32_T UD_DSTATE;                  /* '<S9>/UD' */
  real32_T DiscreteTimeIntegratorconvertfr;/* '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  real32_T UD_DSTATE_o;                /* '<S10>/UD' */
  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S8>/FromWs' */
} D_Work_LabC_CompensatorOverRobo;

/* Parameters (auto storage) */
struct Parameters_LabC_CompensatorOver_ {
  real_T Ad[16];                       /* Variable: Ad
                                        * Referenced by: '<S4>/Gain7'
                                        */
  real_T Bd[4];                        /* Variable: Bd
                                        * Referenced by: '<S4>/Gain8'
                                        */
  real_T Cd[4];                        /* Variable: Cd
                                        * Referenced by: '<S4>/Gain10'
                                        */
  real_T Kd[4];                        /* Variable: Kd
                                        * Referenced by: '<S1>/controller'
                                        */
  real_T Ld[8];                        /* Variable: Ld
                                        * Referenced by: '<S4>/Gain9'
                                        */
  real_T Md1[9];                       /* Variable: Md1
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Md2[3];                       /* Variable: Md2
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Md7[12];                      /* Variable: Md7
                                        * Referenced by: '<S4>/Gain6'
                                        */
  real_T Nud;                          /* Variable: Nud
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T Nxd[4];                       /* Variable: Nxd
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real32_T Md3[3];                     /* Variable: Md3
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real32_T Md4[3];                     /* Variable: Md4
                                        * Referenced by: '<S4>/Gain3'
                                        */
  real32_T Md5[3];                     /* Variable: Md5
                                        * Referenced by: '<S4>/Gain4'
                                        */
  real32_T Md6[4];                     /* Variable: Md6
                                        * Referenced by: '<S4>/Gain5'
                                        */
  real32_T fGyroBias;                  /* Variable: fGyroBias
                                        * Referenced by: '<S2>/gyro bias'
                                        */
  real32_T fWheelRadius;               /* Variable: fWheelRadius
                                        * Referenced by: '<S2>/convert to meters'
                                        */
  real32_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                            * Referenced by: '<S9>/UD'
                                            */
  real32_T DiscreteDerivative_ICPrevScal_n;/* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                            * Referenced by: '<S10>/UD'
                                            */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S58>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S59>/PWM'
                                        */
  uint32_T SerialTransmit_portNumber;  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S13>/Serial Transmit'
                                        */
  real_T Internal_1_1_A;               /* Computed Parameter: Internal_1_1_A
                                        * Referenced by: '<S11>/Internal_1_1'
                                        */
  real_T Internal_1_1_C;               /* Computed Parameter: Internal_1_1_C
                                        * Referenced by: '<S11>/Internal_1_1'
                                        */
  real_T Internal_1_1_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_1_1'
                                        */
  real_T Internal_1_2_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_1_2'
                                        */
  real_T Internal_1_3_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_1_3'
                                        */
  real_T Internal_1_4_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_1_4'
                                        */
  real_T Internal_2_1_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_2_1'
                                        */
  real_T Internal_2_2_A;               /* Computed Parameter: Internal_2_2_A
                                        * Referenced by: '<S11>/Internal_2_2'
                                        */
  real_T Internal_2_2_C;               /* Computed Parameter: Internal_2_2_C
                                        * Referenced by: '<S11>/Internal_2_2'
                                        */
  real_T Internal_2_2_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_2_2'
                                        */
  real_T Internal_2_3_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_2_3'
                                        */
  real_T Internal_2_4_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_2_4'
                                        */
  real_T Internal_3_1_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_3_1'
                                        */
  real_T Internal_3_2_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_3_2'
                                        */
  real_T Internal_3_3_A;               /* Computed Parameter: Internal_3_3_A
                                        * Referenced by: '<S11>/Internal_3_3'
                                        */
  real_T Internal_3_3_C;               /* Computed Parameter: Internal_3_3_C
                                        * Referenced by: '<S11>/Internal_3_3'
                                        */
  real_T Internal_3_3_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_3_3'
                                        */
  real_T Internal_3_4_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_3_4'
                                        */
  real_T Internal_4_1_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_4_1'
                                        */
  real_T Internal_4_2_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_4_2'
                                        */
  real_T Internal_4_3_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_4_3'
                                        */
  real_T Internal_4_4_A;               /* Computed Parameter: Internal_4_4_A
                                        * Referenced by: '<S11>/Internal_4_4'
                                        */
  real_T Internal_4_4_C;               /* Computed Parameter: Internal_4_4_C
                                        * Referenced by: '<S11>/Internal_4_4'
                                        */
  real_T Internal_4_4_X0;              /* Expression: 0
                                        * Referenced by: '<S11>/Internal_4_4'
                                        */
  real_T Internal_1_1_A_m;             /* Computed Parameter: Internal_1_1_A_m
                                        * Referenced by: '<S12>/Internal_1_1'
                                        */
  real_T Internal_1_1_C_h;             /* Computed Parameter: Internal_1_1_C_h
                                        * Referenced by: '<S12>/Internal_1_1'
                                        */
  real_T Internal_1_1_X0_m;            /* Expression: 0
                                        * Referenced by: '<S12>/Internal_1_1'
                                        */
  real_T Internal_1_2_X0_l;            /* Expression: 0
                                        * Referenced by: '<S12>/Internal_1_2'
                                        */
  real_T Internal_1_3_X0_l;            /* Expression: 0
                                        * Referenced by: '<S12>/Internal_1_3'
                                        */
  real_T Internal_2_1_X0_c;            /* Expression: 0
                                        * Referenced by: '<S12>/Internal_2_1'
                                        */
  real_T Internal_2_2_A_o;             /* Computed Parameter: Internal_2_2_A_o
                                        * Referenced by: '<S12>/Internal_2_2'
                                        */
  real_T Internal_2_2_C_p;             /* Computed Parameter: Internal_2_2_C_p
                                        * Referenced by: '<S12>/Internal_2_2'
                                        */
  real_T Internal_2_2_X0_h;            /* Expression: 0
                                        * Referenced by: '<S12>/Internal_2_2'
                                        */
  real_T Internal_2_3_X0_m;            /* Expression: 0
                                        * Referenced by: '<S12>/Internal_2_3'
                                        */
  real_T Internal_3_1_X0_m;            /* Expression: 0
                                        * Referenced by: '<S12>/Internal_3_1'
                                        */
  real_T Internal_3_2_X0_n;            /* Expression: 0
                                        * Referenced by: '<S12>/Internal_3_2'
                                        */
  real_T Internal_3_3_A_a;             /* Computed Parameter: Internal_3_3_A_a
                                        * Referenced by: '<S12>/Internal_3_3'
                                        */
  real_T Internal_3_3_C_h;             /* Computed Parameter: Internal_3_3_C_h
                                        * Referenced by: '<S12>/Internal_3_3'
                                        */
  real_T Internal_3_3_X0_p;            /* Expression: 0
                                        * Referenced by: '<S12>/Internal_3_3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S57>/Constant2'
                                        */
  real_T conversiontodutycycleconverttoi;/* Expression: -255/6
                                          * Referenced by: '<S57>/conversion to duty cycle (convert to int)'
                                          */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S57>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 10
                                        * Referenced by: '<S57>/Constant3'
                                        */
  real_T Saturation0to255_UpperSat;    /* Expression: 255
                                        * Referenced by: '<S57>/Saturation 0 to 255'
                                        */
  real_T Saturation0to255_LowerSat;    /* Expression: 0
                                        * Referenced by: '<S57>/Saturation 0 to 255'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255
                                        * Referenced by: '<S57>/Gain1'
                                        */
  real32_T converttoradians_Gain;      /* Computed Parameter: converttoradians_Gain
                                        * Referenced by: '<S2>/convert to  radians'
                                        */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S9>/TSamp'
                                        */
  real32_T DiscreteTimeIntegratorconvertfr;/* Computed Parameter: DiscreteTimeIntegratorconvertfr
                                            * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                            */
  real32_T DiscreteTimeIntegratorconvert_e;/* Computed Parameter: DiscreteTimeIntegratorconvert_e
                                            * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                            */
  real32_T TSamp_WtEt_m;               /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S10>/TSamp'
                                        */
  real32_T converttoradianssec_Gain;   /* Computed Parameter: converttoradianssec_Gain
                                        * Referenced by: '<S2>/convert to radians//sec'
                                        */
  int16_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S57>/Switch'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S4>/Manual Switch'
                                        */
  uint8_T Encoder_P1[2];               /* Expression: uint8([0 1])
                                        * Referenced by: '<S3>/Encoder '
                                        */
  uint8_T Encoder_P2[2];               /* Expression: uint8([18 62])
                                        * Referenced by: '<S3>/Encoder '
                                        */
  uint8_T Encoder_P3[2];               /* Expression: uint8([19 15])
                                        * Referenced by: '<S3>/Encoder '
                                        */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<S4>/Manual Switch1'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S13>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_LabC_CompensatorOverRob {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_LabC_CompensatorOver LabC_CompensatorOverRobot_P;

/* Block signals (auto storage) */
extern BlockIO_LabC_CompensatorOverRob LabC_CompensatorOverRobot_B;

/* Block states (auto storage) */
extern D_Work_LabC_CompensatorOverRobo LabC_CompensatorOverRobot_DWork;

/* Model entry point functions */
extern void LabC_CompensatorOverRobot_initialize(void);
extern void LabC_CompensatorOverRobot_output(void);
extern void LabC_CompensatorOverRobot_update(void);
extern void LabC_CompensatorOverRobot_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LabC_CompensatorOverRo *const LabC_CompensatorOverRobot_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LabC_CompensatorOverRobot'
 * '<S1>'   : 'LabC_CompensatorOverRobot/controller'
 * '<S2>'   : 'LabC_CompensatorOverRobot/measurement filter'
 * '<S3>'   : 'LabC_CompensatorOverRobot/plant'
 * '<S4>'   : 'LabC_CompensatorOverRobot/controller/observer'
 * '<S5>'   : 'LabC_CompensatorOverRobot/controller/reference'
 * '<S6>'   : 'LabC_CompensatorOverRobot/controller/reference1'
 * '<S7>'   : 'LabC_CompensatorOverRobot/controller/reference2'
 * '<S8>'   : 'LabC_CompensatorOverRobot/controller/reference3'
 * '<S9>'   : 'LabC_CompensatorOverRobot/controller/observer/Discrete Derivative'
 * '<S10>'  : 'LabC_CompensatorOverRobot/controller/observer/Discrete Derivative '
 * '<S11>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System'
 * '<S12>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator'
 * '<S13>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port'
 * '<S14>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_1_1'
 * '<S15>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_1_2'
 * '<S16>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_1_3'
 * '<S17>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_1_4'
 * '<S18>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_2_1'
 * '<S19>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_2_2'
 * '<S20>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_2_3'
 * '<S21>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_2_4'
 * '<S22>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_3_1'
 * '<S23>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_3_2'
 * '<S24>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_3_3'
 * '<S25>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_3_4'
 * '<S26>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_4_1'
 * '<S27>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_4_2'
 * '<S28>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_4_3'
 * '<S29>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_4_4'
 * '<S30>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/Input Delay'
 * '<S31>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/Output Delay'
 * '<S32>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_1_1'
 * '<S33>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_1_2'
 * '<S34>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_1_3'
 * '<S35>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_2_1'
 * '<S36>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_2_2'
 * '<S37>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_2_3'
 * '<S38>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_3_1'
 * '<S39>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_3_2'
 * '<S40>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_3_3'
 * '<S41>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/Input Delay'
 * '<S42>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/Output Delay'
 * '<S43>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits'
 * '<S44>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits1'
 * '<S45>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits10'
 * '<S46>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits11'
 * '<S47>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits12'
 * '<S48>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits13'
 * '<S49>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits2'
 * '<S50>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits3'
 * '<S51>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits4'
 * '<S52>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits5'
 * '<S53>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits6'
 * '<S54>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits7'
 * '<S55>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits8'
 * '<S56>'  : 'LabC_CompensatorOverRobot/controller/observer/send through the serial port/Extract Bits9'
 * '<S57>'  : 'LabC_CompensatorOverRobot/plant/Volts to the motor'
 * '<S58>'  : 'LabC_CompensatorOverRobot/plant/Volts to the motor/Digital Output1'
 * '<S59>'  : 'LabC_CompensatorOverRobot/plant/Volts to the motor/PWM'
 */
#endif                                 /* RTW_HEADER_LabC_CompensatorOverRobot_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
