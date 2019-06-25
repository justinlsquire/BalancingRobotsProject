/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_ObserverAndControllerOverRobot.h
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

#ifndef RTW_HEADER_LabB_ObserverAndControllerOverRobot_h_
#define RTW_HEADER_LabB_ObserverAndControllerOverRobot_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef LabB_ObserverAndControllerOverRobot_COMMON_INCLUDES_
# define LabB_ObserverAndControllerOverRobot_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_serialwrite_lct.h"
#include "arduino_digitaloutput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* LabB_ObserverAndControllerOverRobot_COMMON_INCLUDES_ */

#include "LabB_ObserverAndControllerOverRobot_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T TSamp;                      /* '<S5>/TSamp' */
  real32_T TSamp_n;                    /* '<S6>/TSamp' */
  real32_T Add[3];                     /* '<S4>/Add' */
  real32_T Add3[4];                    /* '<S4>/Add3' */
  real32_T converttoradianssec;        /* '<S2>/convert to radians//sec' */
  int16_T Encoder_o1;                  /* '<S3>/Encoder ' */
  int16_T Encoder_o2;                  /* '<S3>/Encoder ' */
  int16_T GyroandAccelerometer_o1;     /* '<S3>/Gyro and Accelerometer' */
  int16_T GyroandAccelerometer_o2;     /* '<S3>/Gyro and Accelerometer' */
  int16_T GyroandAccelerometer_o3;     /* '<S3>/Gyro and Accelerometer' */
} BlockIO_LabB_ObserverAndControl;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Encoder_DSTATE;               /* '<S3>/Encoder ' */
  real_T GyroandAccelerometer_DSTATE;  /* '<S3>/Gyro and Accelerometer' */
  real32_T UD_DSTATE;                  /* '<S5>/UD' */
  real32_T DiscreteTimeIntegratorconvertfr;/* '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  real32_T UD_DSTATE_o;                /* '<S6>/UD' */
  real32_T Internal_1_1_DSTATE;        /* '<S7>/Internal_1_1' */
  real32_T Internal_2_2_DSTATE;        /* '<S7>/Internal_2_2' */
  real32_T Internal_3_3_DSTATE;        /* '<S7>/Internal_3_3' */
  real32_T Internal_4_4_DSTATE;        /* '<S7>/Internal_4_4' */
  real32_T Internal_1_1_DSTATE_m;      /* '<S8>/Internal_1_1' */
  real32_T Internal_2_2_DSTATE_p;      /* '<S8>/Internal_2_2' */
  real32_T Internal_3_3_DSTATE_o;      /* '<S8>/Internal_3_3' */
} D_Work_LabB_ObserverAndControll;

/* Parameters (auto storage) */
struct Parameters_LabB_ObserverAndCont_ {
  real32_T Ad[16];                     /* Variable: Ad
                                        * Referenced by: '<S4>/Gain7'
                                        */
  real32_T Bd[4];                      /* Variable: Bd
                                        * Referenced by: '<S4>/Gain8'
                                        */
  real32_T Cd[8];                      /* Variable: Cd
                                        * Referenced by: '<S4>/Gain10'
                                        */
  real32_T Ld[8];                      /* Variable: Ld
                                        * Referenced by: '<S4>/Gain9'
                                        */
  real32_T Md1[9];                     /* Variable: Md1
                                        * Referenced by: '<S4>/Gain'
                                        */
  real32_T Md2[3];                     /* Variable: Md2
                                        * Referenced by: '<S4>/Gain1'
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
  real32_T Md7[12];                    /* Variable: Md7
                                        * Referenced by: '<S4>/Gain6'
                                        */
  real32_T fGyroBias;                  /* Variable: fGyroBias
                                        * Referenced by: '<S2>/gyro bias'
                                        */
  real32_T fWheelRadius;               /* Variable: fWheelRadius
                                        * Referenced by: '<S2>/convert to meters'
                                        */
  real32_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                            * Referenced by: '<S5>/UD'
                                            */
  real32_T DiscreteDerivative_ICPrevScal_n;/* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                            * Referenced by: '<S6>/UD'
                                            */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S54>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S55>/PWM'
                                        */
  uint32_T SerialTransmit_portNumber;  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S9>/Serial Transmit'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S53>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S53>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 10
                                        * Referenced by: '<S53>/Constant3'
                                        */
  real_T Saturation0to255_UpperSat;    /* Expression: 255
                                        * Referenced by: '<S53>/Saturation 0 to 255'
                                        */
  real_T Saturation0to255_LowerSat;    /* Expression: 0
                                        * Referenced by: '<S53>/Saturation 0 to 255'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255
                                        * Referenced by: '<S53>/Gain1'
                                        */
  real32_T converttoradians_Gain;      /* Computed Parameter: converttoradians_Gain
                                        * Referenced by: '<S2>/convert to  radians'
                                        */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S5>/TSamp'
                                        */
  real32_T DiscreteTimeIntegratorconvertfr;/* Computed Parameter: DiscreteTimeIntegratorconvertfr
                                            * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                            */
  real32_T DiscreteTimeIntegratorconvert_e;/* Computed Parameter: DiscreteTimeIntegratorconvert_e
                                            * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                            */
  real32_T TSamp_WtEt_m;               /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S6>/TSamp'
                                        */
  real32_T Internal_1_1_A;             /* Computed Parameter: Internal_1_1_A
                                        * Referenced by: '<S7>/Internal_1_1'
                                        */
  real32_T Internal_1_1_C;             /* Computed Parameter: Internal_1_1_C
                                        * Referenced by: '<S7>/Internal_1_1'
                                        */
  real32_T Internal_1_1_X0;            /* Computed Parameter: Internal_1_1_X0
                                        * Referenced by: '<S7>/Internal_1_1'
                                        */
  real32_T Internal_1_2_X0;            /* Computed Parameter: Internal_1_2_X0
                                        * Referenced by: '<S7>/Internal_1_2'
                                        */
  real32_T Internal_1_3_X0;            /* Computed Parameter: Internal_1_3_X0
                                        * Referenced by: '<S7>/Internal_1_3'
                                        */
  real32_T Internal_1_4_X0;            /* Computed Parameter: Internal_1_4_X0
                                        * Referenced by: '<S7>/Internal_1_4'
                                        */
  real32_T Internal_2_1_X0;            /* Computed Parameter: Internal_2_1_X0
                                        * Referenced by: '<S7>/Internal_2_1'
                                        */
  real32_T Internal_2_2_A;             /* Computed Parameter: Internal_2_2_A
                                        * Referenced by: '<S7>/Internal_2_2'
                                        */
  real32_T Internal_2_2_C;             /* Computed Parameter: Internal_2_2_C
                                        * Referenced by: '<S7>/Internal_2_2'
                                        */
  real32_T Internal_2_2_X0;            /* Computed Parameter: Internal_2_2_X0
                                        * Referenced by: '<S7>/Internal_2_2'
                                        */
  real32_T Internal_2_3_X0;            /* Computed Parameter: Internal_2_3_X0
                                        * Referenced by: '<S7>/Internal_2_3'
                                        */
  real32_T Internal_2_4_X0;            /* Computed Parameter: Internal_2_4_X0
                                        * Referenced by: '<S7>/Internal_2_4'
                                        */
  real32_T Internal_3_1_X0;            /* Computed Parameter: Internal_3_1_X0
                                        * Referenced by: '<S7>/Internal_3_1'
                                        */
  real32_T Internal_3_2_X0;            /* Computed Parameter: Internal_3_2_X0
                                        * Referenced by: '<S7>/Internal_3_2'
                                        */
  real32_T Internal_3_3_A;             /* Computed Parameter: Internal_3_3_A
                                        * Referenced by: '<S7>/Internal_3_3'
                                        */
  real32_T Internal_3_3_C;             /* Computed Parameter: Internal_3_3_C
                                        * Referenced by: '<S7>/Internal_3_3'
                                        */
  real32_T Internal_3_3_X0;            /* Computed Parameter: Internal_3_3_X0
                                        * Referenced by: '<S7>/Internal_3_3'
                                        */
  real32_T Internal_3_4_X0;            /* Computed Parameter: Internal_3_4_X0
                                        * Referenced by: '<S7>/Internal_3_4'
                                        */
  real32_T Internal_4_1_X0;            /* Computed Parameter: Internal_4_1_X0
                                        * Referenced by: '<S7>/Internal_4_1'
                                        */
  real32_T Internal_4_2_X0;            /* Computed Parameter: Internal_4_2_X0
                                        * Referenced by: '<S7>/Internal_4_2'
                                        */
  real32_T Internal_4_3_X0;            /* Computed Parameter: Internal_4_3_X0
                                        * Referenced by: '<S7>/Internal_4_3'
                                        */
  real32_T Internal_4_4_A;             /* Computed Parameter: Internal_4_4_A
                                        * Referenced by: '<S7>/Internal_4_4'
                                        */
  real32_T Internal_4_4_C;             /* Computed Parameter: Internal_4_4_C
                                        * Referenced by: '<S7>/Internal_4_4'
                                        */
  real32_T Internal_4_4_X0;            /* Computed Parameter: Internal_4_4_X0
                                        * Referenced by: '<S7>/Internal_4_4'
                                        */
  real32_T Internal_1_1_A_m;           /* Computed Parameter: Internal_1_1_A_m
                                        * Referenced by: '<S8>/Internal_1_1'
                                        */
  real32_T Internal_1_1_C_h;           /* Computed Parameter: Internal_1_1_C_h
                                        * Referenced by: '<S8>/Internal_1_1'
                                        */
  real32_T Internal_1_1_X0_m;          /* Computed Parameter: Internal_1_1_X0_m
                                        * Referenced by: '<S8>/Internal_1_1'
                                        */
  real32_T Internal_1_2_X0_l;          /* Computed Parameter: Internal_1_2_X0_l
                                        * Referenced by: '<S8>/Internal_1_2'
                                        */
  real32_T Internal_1_3_X0_l;          /* Computed Parameter: Internal_1_3_X0_l
                                        * Referenced by: '<S8>/Internal_1_3'
                                        */
  real32_T Internal_2_1_X0_c;          /* Computed Parameter: Internal_2_1_X0_c
                                        * Referenced by: '<S8>/Internal_2_1'
                                        */
  real32_T Internal_2_2_A_o;           /* Computed Parameter: Internal_2_2_A_o
                                        * Referenced by: '<S8>/Internal_2_2'
                                        */
  real32_T Internal_2_2_C_p;           /* Computed Parameter: Internal_2_2_C_p
                                        * Referenced by: '<S8>/Internal_2_2'
                                        */
  real32_T Internal_2_2_X0_h;          /* Computed Parameter: Internal_2_2_X0_h
                                        * Referenced by: '<S8>/Internal_2_2'
                                        */
  real32_T Internal_2_3_X0_m;          /* Computed Parameter: Internal_2_3_X0_m
                                        * Referenced by: '<S8>/Internal_2_3'
                                        */
  real32_T Internal_3_1_X0_m;          /* Computed Parameter: Internal_3_1_X0_m
                                        * Referenced by: '<S8>/Internal_3_1'
                                        */
  real32_T Internal_3_2_X0_n;          /* Computed Parameter: Internal_3_2_X0_n
                                        * Referenced by: '<S8>/Internal_3_2'
                                        */
  real32_T Internal_3_3_A_a;           /* Computed Parameter: Internal_3_3_A_a
                                        * Referenced by: '<S8>/Internal_3_3'
                                        */
  real32_T Internal_3_3_C_h;           /* Computed Parameter: Internal_3_3_C_h
                                        * Referenced by: '<S8>/Internal_3_3'
                                        */
  real32_T Internal_3_3_X0_p;          /* Computed Parameter: Internal_3_3_X0_p
                                        * Referenced by: '<S8>/Internal_3_3'
                                        */
  real32_T controller_Gain[4];         /* Computed Parameter: controller_Gain
                                        * Referenced by: '<S1>/controller'
                                        */
  real32_T converttoradianssec_Gain;   /* Computed Parameter: converttoradianssec_Gain
                                        * Referenced by: '<S2>/convert to radians//sec'
                                        */
  real32_T conversiontodutycycleconverttoi;/* Computed Parameter: conversiontodutycycleconverttoi
                                            * Referenced by: '<S53>/conversion to duty cycle (convert to int)'
                                            */
  int16_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S53>/Switch'
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
                                        * Referenced by: '<S9>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_LabB_ObserverAndControl {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_LabB_ObserverAndCont LabB_ObserverAndControllerOve_P;

/* Block signals (auto storage) */
extern BlockIO_LabB_ObserverAndControl LabB_ObserverAndControllerOve_B;

/* Block states (auto storage) */
extern D_Work_LabB_ObserverAndControll LabB_ObserverAndControlle_DWork;

/* Model entry point functions */
extern void LabB_ObserverAndControllerOverRobot_initialize(void);
extern void LabB_ObserverAndControllerOverRobot_output(void);
extern void LabB_ObserverAndControllerOverRobot_update(void);
extern void LabB_ObserverAndControllerOverRobot_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LabB_ObserverAndContro *const LabB_ObserverAndControllerOv_M;

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
 * '<Root>' : 'LabB_ObserverAndControllerOverRobot'
 * '<S1>'   : 'LabB_ObserverAndControllerOverRobot/controller'
 * '<S2>'   : 'LabB_ObserverAndControllerOverRobot/measurement filter'
 * '<S3>'   : 'LabB_ObserverAndControllerOverRobot/plant'
 * '<S4>'   : 'LabB_ObserverAndControllerOverRobot/controller/observer'
 * '<S5>'   : 'LabB_ObserverAndControllerOverRobot/controller/observer/Discrete Derivative'
 * '<S6>'   : 'LabB_ObserverAndControllerOverRobot/controller/observer/Discrete Derivative '
 * '<S7>'   : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System'
 * '<S8>'   : 'LabB_ObserverAndControllerOverRobot/controller/observer/integrator'
 * '<S9>'   : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port'
 * '<S10>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_1_1'
 * '<S11>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_1_2'
 * '<S12>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_1_3'
 * '<S13>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_1_4'
 * '<S14>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_2_1'
 * '<S15>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_2_2'
 * '<S16>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_2_3'
 * '<S17>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_2_4'
 * '<S18>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_3_1'
 * '<S19>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_3_2'
 * '<S20>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_3_3'
 * '<S21>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_3_4'
 * '<S22>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_4_1'
 * '<S23>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_4_2'
 * '<S24>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_4_3'
 * '<S25>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/IO Delay_4_4'
 * '<S26>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/Input Delay'
 * '<S27>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/LTI System/Output Delay'
 * '<S28>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/integrator/IO Delay_1_1'
 * '<S29>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/integrator/IO Delay_1_2'
 * '<S30>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/integrator/IO Delay_1_3'
 * '<S31>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/integrator/IO Delay_2_1'
 * '<S32>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/integrator/IO Delay_2_2'
 * '<S33>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/integrator/IO Delay_2_3'
 * '<S34>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/integrator/IO Delay_3_1'
 * '<S35>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/integrator/IO Delay_3_2'
 * '<S36>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/integrator/IO Delay_3_3'
 * '<S37>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/integrator/Input Delay'
 * '<S38>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/integrator/Output Delay'
 * '<S39>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits'
 * '<S40>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits1'
 * '<S41>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits10'
 * '<S42>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits11'
 * '<S43>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits12'
 * '<S44>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits13'
 * '<S45>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits2'
 * '<S46>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits3'
 * '<S47>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits4'
 * '<S48>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits5'
 * '<S49>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits6'
 * '<S50>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits7'
 * '<S51>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits8'
 * '<S52>'  : 'LabB_ObserverAndControllerOverRobot/controller/observer/send through the serial port/Extract Bits9'
 * '<S53>'  : 'LabB_ObserverAndControllerOverRobot/plant/Volts to the motor'
 * '<S54>'  : 'LabB_ObserverAndControllerOverRobot/plant/Volts to the motor/Digital Output1'
 * '<S55>'  : 'LabB_ObserverAndControllerOverRobot/plant/Volts to the motor/PWM'
 */
#endif                                 /* RTW_HEADER_LabB_ObserverAndControllerOverRobot_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
