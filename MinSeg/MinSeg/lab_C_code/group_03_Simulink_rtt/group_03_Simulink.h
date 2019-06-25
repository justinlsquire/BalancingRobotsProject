/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: group_03_Simulink.h
 *
 * Code generated for Simulink model 'group_03_Simulink'.
 *
 * Model version                  : 1.711
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Thu Jan 05 13:01:37 2017
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_group_03_Simulink_h_
#define RTW_HEADER_group_03_Simulink_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef group_03_Simulink_COMMON_INCLUDES_
# define group_03_Simulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_serialwrite_lct.h"
#include "arduino_digitaloutput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* group_03_Simulink_COMMON_INCLUDES_ */

#include "group_03_Simulink_types.h"
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
  real_T Add[3];                       /* '<S5>/Add' */
  real_T Add3[4];                      /* '<S5>/Add3' */
  real32_T TSamp;                      /* '<S7>/TSamp' */
  real32_T TSamp_n;                    /* '<S8>/TSamp' */
  real32_T converttoradianssec;        /* '<S2>/convert to radians//sec' */
  int16_T Encoder_o1;                  /* '<S3>/Encoder ' */
  int16_T Encoder_o2;                  /* '<S3>/Encoder ' */
  int16_T GyroandAccelerometer_o1;     /* '<S3>/Gyro and Accelerometer' */
  int16_T GyroandAccelerometer_o2;     /* '<S3>/Gyro and Accelerometer' */
  int16_T GyroandAccelerometer_o3;     /* '<S3>/Gyro and Accelerometer' */
  uint8_T DataTypeConversion;          /* '<S56>/Data Type Conversion' */
  uint8_T DataTypeConversion_b;        /* '<S57>/Data Type Conversion' */
} BlockIO_group_03_Simulink;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Encoder_DSTATE;               /* '<S3>/Encoder ' */
  real_T Internal_1_1_DSTATE;          /* '<S9>/Internal_1_1' */
  real_T Internal_2_2_DSTATE;          /* '<S9>/Internal_2_2' */
  real_T Internal_3_3_DSTATE;          /* '<S9>/Internal_3_3' */
  real_T Internal_4_4_DSTATE;          /* '<S9>/Internal_4_4' */
  real_T Internal_1_1_DSTATE_m;        /* '<S10>/Internal_1_1' */
  real_T Internal_2_2_DSTATE_p;        /* '<S10>/Internal_2_2' */
  real_T Internal_3_3_DSTATE_o;        /* '<S10>/Internal_3_3' */
  real_T GyroandAccelerometer_DSTATE;  /* '<S3>/Gyro and Accelerometer' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S4>/FromWs' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK_d;                    /* '<S6>/FromWs' */

  real32_T UD_DSTATE;                  /* '<S7>/UD' */
  real32_T DiscreteTimeIntegratorconvertfr;/* '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  real32_T UD_DSTATE_o;                /* '<S8>/UD' */
  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S4>/FromWs' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK_f;                    /* '<S6>/FromWs' */
} D_Work_group_03_Simulink;

/* Parameters (auto storage) */
struct Parameters_group_03_Simulink_ {
  real_T Ad[16];                       /* Variable: Ad
                                        * Referenced by: '<S5>/Gain7'
                                        */
  real_T Bd[4];                        /* Variable: Bd
                                        * Referenced by: '<S5>/Gain8'
                                        */
  real_T Cd[4];                        /* Variable: Cd
                                        * Referenced by: '<S5>/Gain10'
                                        */
  real_T Kd[4];                        /* Variable: Kd
                                        * Referenced by: '<S1>/controller'
                                        */
  real_T Ld[8];                        /* Variable: Ld
                                        * Referenced by: '<S5>/Gain9'
                                        */
  real_T Md1[9];                       /* Variable: Md1
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Md2[3];                       /* Variable: Md2
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Md7[12];                      /* Variable: Md7
                                        * Referenced by: '<S5>/Gain6'
                                        */
  real_T Nud;                          /* Variable: Nud
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T Nxd[4];                       /* Variable: Nxd
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real32_T Md3[3];                     /* Variable: Md3
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real32_T Md4[3];                     /* Variable: Md4
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real32_T Md5[3];                     /* Variable: Md5
                                        * Referenced by: '<S5>/Gain4'
                                        */
  real32_T Md6[4];                     /* Variable: Md6
                                        * Referenced by: '<S5>/Gain5'
                                        */
  real32_T fGyroBias;                  /* Variable: fGyroBias
                                        * Referenced by: '<S2>/gyro bias'
                                        */
  real32_T fWheelRadius;               /* Variable: fWheelRadius
                                        * Referenced by: '<S2>/convert to meters'
                                        */
  real32_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                            * Referenced by: '<S7>/UD'
                                            */
  real32_T DiscreteDerivative_ICPrevScal_n;/* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                            * Referenced by: '<S8>/UD'
                                            */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S56>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S57>/PWM'
                                        */
  uint32_T SerialTransmit_portNumber;  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S11>/Serial Transmit'
                                        */
  real_T Internal_1_1_A;               /* Computed Parameter: Internal_1_1_A
                                        * Referenced by: '<S9>/Internal_1_1'
                                        */
  real_T Internal_1_1_C;               /* Computed Parameter: Internal_1_1_C
                                        * Referenced by: '<S9>/Internal_1_1'
                                        */
  real_T Internal_1_1_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_1_1'
                                        */
  real_T Internal_1_2_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_1_2'
                                        */
  real_T Internal_1_3_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_1_3'
                                        */
  real_T Internal_1_4_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_1_4'
                                        */
  real_T Internal_2_1_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_2_1'
                                        */
  real_T Internal_2_2_A;               /* Computed Parameter: Internal_2_2_A
                                        * Referenced by: '<S9>/Internal_2_2'
                                        */
  real_T Internal_2_2_C;               /* Computed Parameter: Internal_2_2_C
                                        * Referenced by: '<S9>/Internal_2_2'
                                        */
  real_T Internal_2_2_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_2_2'
                                        */
  real_T Internal_2_3_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_2_3'
                                        */
  real_T Internal_2_4_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_2_4'
                                        */
  real_T Internal_3_1_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_3_1'
                                        */
  real_T Internal_3_2_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_3_2'
                                        */
  real_T Internal_3_3_A;               /* Computed Parameter: Internal_3_3_A
                                        * Referenced by: '<S9>/Internal_3_3'
                                        */
  real_T Internal_3_3_C;               /* Computed Parameter: Internal_3_3_C
                                        * Referenced by: '<S9>/Internal_3_3'
                                        */
  real_T Internal_3_3_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_3_3'
                                        */
  real_T Internal_3_4_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_3_4'
                                        */
  real_T Internal_4_1_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_4_1'
                                        */
  real_T Internal_4_2_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_4_2'
                                        */
  real_T Internal_4_3_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_4_3'
                                        */
  real_T Internal_4_4_A;               /* Computed Parameter: Internal_4_4_A
                                        * Referenced by: '<S9>/Internal_4_4'
                                        */
  real_T Internal_4_4_C;               /* Computed Parameter: Internal_4_4_C
                                        * Referenced by: '<S9>/Internal_4_4'
                                        */
  real_T Internal_4_4_X0;              /* Expression: 0
                                        * Referenced by: '<S9>/Internal_4_4'
                                        */
  real_T Internal_1_1_A_m;             /* Computed Parameter: Internal_1_1_A_m
                                        * Referenced by: '<S10>/Internal_1_1'
                                        */
  real_T Internal_1_1_C_h;             /* Computed Parameter: Internal_1_1_C_h
                                        * Referenced by: '<S10>/Internal_1_1'
                                        */
  real_T Internal_1_1_X0_m;            /* Expression: 0
                                        * Referenced by: '<S10>/Internal_1_1'
                                        */
  real_T Internal_1_2_X0_l;            /* Expression: 0
                                        * Referenced by: '<S10>/Internal_1_2'
                                        */
  real_T Internal_1_3_X0_l;            /* Expression: 0
                                        * Referenced by: '<S10>/Internal_1_3'
                                        */
  real_T Internal_2_1_X0_c;            /* Expression: 0
                                        * Referenced by: '<S10>/Internal_2_1'
                                        */
  real_T Internal_2_2_A_o;             /* Computed Parameter: Internal_2_2_A_o
                                        * Referenced by: '<S10>/Internal_2_2'
                                        */
  real_T Internal_2_2_C_p;             /* Computed Parameter: Internal_2_2_C_p
                                        * Referenced by: '<S10>/Internal_2_2'
                                        */
  real_T Internal_2_2_X0_h;            /* Expression: 0
                                        * Referenced by: '<S10>/Internal_2_2'
                                        */
  real_T Internal_2_3_X0_m;            /* Expression: 0
                                        * Referenced by: '<S10>/Internal_2_3'
                                        */
  real_T Internal_3_1_X0_m;            /* Expression: 0
                                        * Referenced by: '<S10>/Internal_3_1'
                                        */
  real_T Internal_3_2_X0_n;            /* Expression: 0
                                        * Referenced by: '<S10>/Internal_3_2'
                                        */
  real_T Internal_3_3_A_a;             /* Computed Parameter: Internal_3_3_A_a
                                        * Referenced by: '<S10>/Internal_3_3'
                                        */
  real_T Internal_3_3_C_h;             /* Computed Parameter: Internal_3_3_C_h
                                        * Referenced by: '<S10>/Internal_3_3'
                                        */
  real_T Internal_3_3_X0_p;            /* Expression: 0
                                        * Referenced by: '<S10>/Internal_3_3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S55>/Constant2'
                                        */
  real_T conversiontodutycycleconverttoi;/* Expression: -255/6
                                          * Referenced by: '<S55>/conversion to duty cycle (convert to int)'
                                          */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S55>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 10
                                        * Referenced by: '<S55>/Constant3'
                                        */
  real_T Saturation0to255_UpperSat;    /* Expression: 255
                                        * Referenced by: '<S55>/Saturation 0 to 255'
                                        */
  real_T Saturation0to255_LowerSat;    /* Expression: 0
                                        * Referenced by: '<S55>/Saturation 0 to 255'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255
                                        * Referenced by: '<S55>/Gain1'
                                        */
  real32_T converttoradians_Gain;      /* Computed Parameter: converttoradians_Gain
                                        * Referenced by: '<S2>/convert to  radians'
                                        */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S7>/TSamp'
                                        */
  real32_T DiscreteTimeIntegratorconvertfr;/* Computed Parameter: DiscreteTimeIntegratorconvertfr
                                            * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                            */
  real32_T DiscreteTimeIntegratorconvert_e;/* Computed Parameter: DiscreteTimeIntegratorconvert_e
                                            * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                            */
  real32_T TSamp_WtEt_m;               /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S8>/TSamp'
                                        */
  real32_T converttoradianssec_Gain;   /* Computed Parameter: converttoradianssec_Gain
                                        * Referenced by: '<S2>/convert to radians//sec'
                                        */
  int16_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S55>/Switch'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S5>/Manual Switch'
                                        */
  uint8_T SELECTMAXorTRIAL_CurrentSetting;/* Computed Parameter: SELECTMAXorTRIAL_CurrentSetting
                                           * Referenced by: '<S1>/SELECT MAX or TRIAL'
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
                                        * Referenced by: '<S5>/Manual Switch1'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S11>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_group_03_Simulink {
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
extern Parameters_group_03_Simulink group_03_Simulink_P;

/* Block signals (auto storage) */
extern BlockIO_group_03_Simulink group_03_Simulink_B;

/* Block states (auto storage) */
extern D_Work_group_03_Simulink group_03_Simulink_DWork;

/* Model entry point functions */
extern void group_03_Simulink_initialize(void);
extern void group_03_Simulink_output(void);
extern void group_03_Simulink_update(void);
extern void group_03_Simulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_group_03_Simulink *const group_03_Simulink_M;

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
 * '<Root>' : 'group_03_Simulink'
 * '<S1>'   : 'group_03_Simulink/controller'
 * '<S2>'   : 'group_03_Simulink/measurement filter'
 * '<S3>'   : 'group_03_Simulink/plant'
 * '<S4>'   : 'group_03_Simulink/controller/max'
 * '<S5>'   : 'group_03_Simulink/controller/observer'
 * '<S6>'   : 'group_03_Simulink/controller/trial (0.5)'
 * '<S7>'   : 'group_03_Simulink/controller/observer/Discrete Derivative'
 * '<S8>'   : 'group_03_Simulink/controller/observer/Discrete Derivative '
 * '<S9>'   : 'group_03_Simulink/controller/observer/LTI System'
 * '<S10>'  : 'group_03_Simulink/controller/observer/integrator'
 * '<S11>'  : 'group_03_Simulink/controller/observer/send through the serial port'
 * '<S12>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_1_1'
 * '<S13>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_1_2'
 * '<S14>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_1_3'
 * '<S15>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_1_4'
 * '<S16>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_2_1'
 * '<S17>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_2_2'
 * '<S18>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_2_3'
 * '<S19>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_2_4'
 * '<S20>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_3_1'
 * '<S21>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_3_2'
 * '<S22>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_3_3'
 * '<S23>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_3_4'
 * '<S24>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_4_1'
 * '<S25>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_4_2'
 * '<S26>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_4_3'
 * '<S27>'  : 'group_03_Simulink/controller/observer/LTI System/IO Delay_4_4'
 * '<S28>'  : 'group_03_Simulink/controller/observer/LTI System/Input Delay'
 * '<S29>'  : 'group_03_Simulink/controller/observer/LTI System/Output Delay'
 * '<S30>'  : 'group_03_Simulink/controller/observer/integrator/IO Delay_1_1'
 * '<S31>'  : 'group_03_Simulink/controller/observer/integrator/IO Delay_1_2'
 * '<S32>'  : 'group_03_Simulink/controller/observer/integrator/IO Delay_1_3'
 * '<S33>'  : 'group_03_Simulink/controller/observer/integrator/IO Delay_2_1'
 * '<S34>'  : 'group_03_Simulink/controller/observer/integrator/IO Delay_2_2'
 * '<S35>'  : 'group_03_Simulink/controller/observer/integrator/IO Delay_2_3'
 * '<S36>'  : 'group_03_Simulink/controller/observer/integrator/IO Delay_3_1'
 * '<S37>'  : 'group_03_Simulink/controller/observer/integrator/IO Delay_3_2'
 * '<S38>'  : 'group_03_Simulink/controller/observer/integrator/IO Delay_3_3'
 * '<S39>'  : 'group_03_Simulink/controller/observer/integrator/Input Delay'
 * '<S40>'  : 'group_03_Simulink/controller/observer/integrator/Output Delay'
 * '<S41>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits'
 * '<S42>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits1'
 * '<S43>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits10'
 * '<S44>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits11'
 * '<S45>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits12'
 * '<S46>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits13'
 * '<S47>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits2'
 * '<S48>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits3'
 * '<S49>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits4'
 * '<S50>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits5'
 * '<S51>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits6'
 * '<S52>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits7'
 * '<S53>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits8'
 * '<S54>'  : 'group_03_Simulink/controller/observer/send through the serial port/Extract Bits9'
 * '<S55>'  : 'group_03_Simulink/plant/Volts to the motor'
 * '<S56>'  : 'group_03_Simulink/plant/Volts to the motor/Digital Output1'
 * '<S57>'  : 'group_03_Simulink/plant/Volts to the motor/PWM'
 */
#endif                                 /* RTW_HEADER_group_03_Simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
