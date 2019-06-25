/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_ObserverAndControllerOverRobot_data.c
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
#include "LabB_ObserverAndControllerOverRobot_private.h"

/* Block parameters (auto storage) */
Parameters_LabB_ObserverAndCont LabB_ObserverAndControllerOve_P = {
  /*  Variable: Ad
   * Referenced by: '<S4>/Gain7'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.00216937577F, 0.169257507F, 0.0123862131F,
    3.63566065F, -3.56150304E-5F, -0.00954899471F, 1.0005976F, 0.218485147F,
    5.93717268E-5F, 0.0174099766F, 0.00474093808F, 0.924248695F },

  /*  Variable: Bd
   * Referenced by: '<S4>/Gain8'
   */
  { 0.00013388088F, 0.0392918736F, -0.000585834379F, -0.171956927F },

  /*  Variable: Cd
   * Referenced by: '<S4>/Gain10'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F },

  /*  Variable: Ld
   * Referenced by: '<S4>/Gain9'
   */
  { 0.104731217F, -2.85835791F, 0.0697934926F, 15.5552053F, -0.170408875F,
    7.82141876F, 0.251910627F, -28.4914227F },

  /*  Variable: Md1
   * Referenced by: '<S4>/Gain'
   */
  { 0.0564318523F, -0.101135343F, 2.71354604F, -0.110334449F, 0.930267036F,
    0.337759048F, 0.0143221514F, 0.00163406704F, 0.899012148F },

  /*  Variable: Md2
   * Referenced by: '<S4>/Gain1'
   */
  { 0.0323289521F, -0.00759170437F, -0.228864312F },

  /*  Variable: Md3
   * Referenced by: '<S4>/Gain2'
   */
  { -52.0083504F, -52.3291321F, -425.059875F },

  /*  Variable: Md4
   * Referenced by: '<S4>/Gain3'
   */
  { 0.102637731F, 0.0721941888F, -0.104135379F },

  /*  Variable: Md5
   * Referenced by: '<S4>/Gain4'
   */
  { 52.0083504F, 52.3291321F, 425.059875F },

  /*  Variable: Md6
   * Referenced by: '<S4>/Gain5'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F },

  /*  Variable: Md7
   * Referenced by: '<S4>/Gain6'
   */
  { 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F },
  -363.0F,                             /* Variable: fGyroBias
                                        * Referenced by: '<S2>/gyro bias'
                                        */
  0.0216F,                             /* Variable: fWheelRadius
                                        * Referenced by: '<S2>/convert to meters'
                                        */
  0.0F,                                /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S5>/UD'
                                        */
  0.0F,                                /* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                        * Referenced by: '<S6>/UD'
                                        */
  6U,                                  /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S54>/Digital Output'
                                        */
  8U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S55>/PWM'
                                        */
  0U,                                  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S9>/Serial Transmit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S53>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S53>/Constant2'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S53>/Constant3'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S53>/Saturation 0 to 255'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S53>/Saturation 0 to 255'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S53>/Gain1'
                                        */
  -0.00872664619F,                     /* Computed Parameter: converttoradians_Gain
                                        * Referenced by: '<S2>/convert to  radians'
                                        */
  200.0F,                              /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S5>/TSamp'
                                        */
  0.005F,                              /* Computed Parameter: DiscreteTimeIntegratorconvertfr
                                        * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegratorconvert_e
                                        * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                        */
  200.0F,                              /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S6>/TSamp'
                                        */
  -0.0F,                               /* Computed Parameter: Internal_1_1_A
                                        * Referenced by: '<S7>/Internal_1_1'
                                        */
  1.0F,                                /* Computed Parameter: Internal_1_1_C
                                        * Referenced by: '<S7>/Internal_1_1'
                                        */
  0.0F,                                /* Computed Parameter: Internal_1_1_X0
                                        * Referenced by: '<S7>/Internal_1_1'
                                        */
  0.0F,                                /* Computed Parameter: Internal_1_2_X0
                                        * Referenced by: '<S7>/Internal_1_2'
                                        */
  0.0F,                                /* Computed Parameter: Internal_1_3_X0
                                        * Referenced by: '<S7>/Internal_1_3'
                                        */
  0.0F,                                /* Computed Parameter: Internal_1_4_X0
                                        * Referenced by: '<S7>/Internal_1_4'
                                        */
  0.0F,                                /* Computed Parameter: Internal_2_1_X0
                                        * Referenced by: '<S7>/Internal_2_1'
                                        */
  -0.0F,                               /* Computed Parameter: Internal_2_2_A
                                        * Referenced by: '<S7>/Internal_2_2'
                                        */
  1.0F,                                /* Computed Parameter: Internal_2_2_C
                                        * Referenced by: '<S7>/Internal_2_2'
                                        */
  0.0F,                                /* Computed Parameter: Internal_2_2_X0
                                        * Referenced by: '<S7>/Internal_2_2'
                                        */
  0.0F,                                /* Computed Parameter: Internal_2_3_X0
                                        * Referenced by: '<S7>/Internal_2_3'
                                        */
  0.0F,                                /* Computed Parameter: Internal_2_4_X0
                                        * Referenced by: '<S7>/Internal_2_4'
                                        */
  0.0F,                                /* Computed Parameter: Internal_3_1_X0
                                        * Referenced by: '<S7>/Internal_3_1'
                                        */
  0.0F,                                /* Computed Parameter: Internal_3_2_X0
                                        * Referenced by: '<S7>/Internal_3_2'
                                        */
  -0.0F,                               /* Computed Parameter: Internal_3_3_A
                                        * Referenced by: '<S7>/Internal_3_3'
                                        */
  1.0F,                                /* Computed Parameter: Internal_3_3_C
                                        * Referenced by: '<S7>/Internal_3_3'
                                        */
  0.0F,                                /* Computed Parameter: Internal_3_3_X0
                                        * Referenced by: '<S7>/Internal_3_3'
                                        */
  0.0F,                                /* Computed Parameter: Internal_3_4_X0
                                        * Referenced by: '<S7>/Internal_3_4'
                                        */
  0.0F,                                /* Computed Parameter: Internal_4_1_X0
                                        * Referenced by: '<S7>/Internal_4_1'
                                        */
  0.0F,                                /* Computed Parameter: Internal_4_2_X0
                                        * Referenced by: '<S7>/Internal_4_2'
                                        */
  0.0F,                                /* Computed Parameter: Internal_4_3_X0
                                        * Referenced by: '<S7>/Internal_4_3'
                                        */
  -0.0F,                               /* Computed Parameter: Internal_4_4_A
                                        * Referenced by: '<S7>/Internal_4_4'
                                        */
  1.0F,                                /* Computed Parameter: Internal_4_4_C
                                        * Referenced by: '<S7>/Internal_4_4'
                                        */
  0.0F,                                /* Computed Parameter: Internal_4_4_X0
                                        * Referenced by: '<S7>/Internal_4_4'
                                        */
  -0.0F,                               /* Computed Parameter: Internal_1_1_A_m
                                        * Referenced by: '<S8>/Internal_1_1'
                                        */
  1.0F,                                /* Computed Parameter: Internal_1_1_C_h
                                        * Referenced by: '<S8>/Internal_1_1'
                                        */
  0.0F,                                /* Computed Parameter: Internal_1_1_X0_m
                                        * Referenced by: '<S8>/Internal_1_1'
                                        */
  0.0F,                                /* Computed Parameter: Internal_1_2_X0_l
                                        * Referenced by: '<S8>/Internal_1_2'
                                        */
  0.0F,                                /* Computed Parameter: Internal_1_3_X0_l
                                        * Referenced by: '<S8>/Internal_1_3'
                                        */
  0.0F,                                /* Computed Parameter: Internal_2_1_X0_c
                                        * Referenced by: '<S8>/Internal_2_1'
                                        */
  -0.0F,                               /* Computed Parameter: Internal_2_2_A_o
                                        * Referenced by: '<S8>/Internal_2_2'
                                        */
  1.0F,                                /* Computed Parameter: Internal_2_2_C_p
                                        * Referenced by: '<S8>/Internal_2_2'
                                        */
  0.0F,                                /* Computed Parameter: Internal_2_2_X0_h
                                        * Referenced by: '<S8>/Internal_2_2'
                                        */
  0.0F,                                /* Computed Parameter: Internal_2_3_X0_m
                                        * Referenced by: '<S8>/Internal_2_3'
                                        */
  0.0F,                                /* Computed Parameter: Internal_3_1_X0_m
                                        * Referenced by: '<S8>/Internal_3_1'
                                        */
  0.0F,                                /* Computed Parameter: Internal_3_2_X0_n
                                        * Referenced by: '<S8>/Internal_3_2'
                                        */
  -0.0F,                               /* Computed Parameter: Internal_3_3_A_a
                                        * Referenced by: '<S8>/Internal_3_3'
                                        */
  1.0F,                                /* Computed Parameter: Internal_3_3_C_h
                                        * Referenced by: '<S8>/Internal_3_3'
                                        */
  0.0F,                                /* Computed Parameter: Internal_3_3_X0_p
                                        * Referenced by: '<S8>/Internal_3_3'
                                        */

  /*  Computed Parameter: controller_Gain
   * Referenced by: '<S1>/controller'
   */
  { 15.661335F, 31.7457142F, 27.9507065F, 7.81513596F },
  -0.000133231239F,                    /* Computed Parameter: converttoradianssec_Gain
                                        * Referenced by: '<S2>/convert to radians//sec'
                                        */
  -42.5F,                              /* Computed Parameter: conversiontodutycycleconverttoi
                                        * Referenced by: '<S53>/conversion to duty cycle (convert to int)'
                                        */
  0,                                   /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S53>/Switch'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S4>/Manual Switch'
                                        */

  /*  Expression: uint8([0 1])
   * Referenced by: '<S3>/Encoder '
   */
  { 0U, 1U },

  /*  Expression: uint8([18 62])
   * Referenced by: '<S3>/Encoder '
   */
  { 18U, 62U },

  /*  Expression: uint8([19 15])
   * Referenced by: '<S3>/Encoder '
   */
  { 19U, 15U },
  1U,                                  /* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<S4>/Manual Switch1'
                                        */
  1U                                   /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S9>/Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
