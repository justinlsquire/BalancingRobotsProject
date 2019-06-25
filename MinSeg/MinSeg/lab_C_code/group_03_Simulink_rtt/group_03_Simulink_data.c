/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: group_03_Simulink_data.c
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

#include "group_03_Simulink.h"
#include "group_03_Simulink_private.h"

/* Block parameters (auto storage) */
Parameters_group_03_Simulink group_03_Simulink_P = {
  /*  Variable: Ad
   * Referenced by: '<S5>/Gain7'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0021693758049392887, 0.16925750888188618,
    0.01238621272879745, 3.6356607101497014, -3.5615030253047318E-5,
    -0.0095489942538593744, 1.0005975462171406, 0.21848514588281692,
    5.9371727424617068E-5, 0.017409977283227344, 0.0047409380143409053,
    0.9242486713039969 },

  /*  Variable: Bd
   * Referenced by: '<S5>/Gain8'
   */
  { 0.00013388087409070936, 0.03929187457991079, -0.00058583438582150086,
    -0.17195692548005337 },

  /*  Variable: Cd
   * Referenced by: '<S5>/Gain10'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /*  Variable: Kd
   * Referenced by: '<S1>/controller'
   */
  { -26.226348237957421, -35.123193701320723, -43.032254247734024,
    -8.5717114527376079 },

  /*  Variable: Ld
   * Referenced by: '<S5>/Gain9'
   */
  { 0.17244593900993455, -1.9006386801622852, 0.022301903225026478,
    16.849359163345078, -0.053375197983792706, 7.7566600944540438,
    0.29710151471065516, -26.252094924380017 },

  /*  Variable: Md1
   * Referenced by: '<S5>/Gain'
   */
  { 0.90212873972017182, -0.002611644176637928, 0.059315721119974629,
    -0.0026861048880451668, 0.92441423225152275, 0.007051185158192752,
    0.037467281718726944, 0.004330474935461015, 0.82637084885312362 },

  /*  Variable: Md2
   * Referenced by: '<S5>/Gain1'
   */
  { 0.0845202950118007, -0.001511412235180461, -0.39266750595720024 },

  /*  Variable: Md7
   * Referenced by: '<S5>/Gain6'
   */
  { 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 },
  0.0,                                 /* Variable: Nud
                                        * Referenced by: '<S1>/Gain3'
                                        */

  /*  Variable: Nxd
   * Referenced by: '<S1>/Gain2'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /*  Variable: Md3
   * Referenced by: '<S5>/Gain2'
   */
  { 337.825867F, -6.91344357F, -1648.55945F },

  /*  Variable: Md4
   * Referenced by: '<S5>/Gain3'
   */
  { -0.0188945681F, 0.0764295384F, 0.270147443F },

  /*  Variable: Md5
   * Referenced by: '<S5>/Gain4'
   */
  { -337.825867F, 6.91344357F, 1648.55945F },

  /*  Variable: Md6
   * Referenced by: '<S5>/Gain5'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F },
  -363.0F,                             /* Variable: fGyroBias
                                        * Referenced by: '<S2>/gyro bias'
                                        */
  0.0216F,                             /* Variable: fWheelRadius
                                        * Referenced by: '<S2>/convert to meters'
                                        */
  0.0F,                                /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S7>/UD'
                                        */
  0.0F,                                /* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                        * Referenced by: '<S8>/UD'
                                        */
  6U,                                  /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S56>/Digital Output'
                                        */
  8U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S57>/PWM'
                                        */
  0U,                                  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S11>/Serial Transmit'
                                        */
  -0.0,                                /* Computed Parameter: Internal_1_1_A
                                        * Referenced by: '<S9>/Internal_1_1'
                                        */
  1.0,                                 /* Computed Parameter: Internal_1_1_C
                                        * Referenced by: '<S9>/Internal_1_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_1_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_1_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_1_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_1_4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_2_1'
                                        */
  -0.0,                                /* Computed Parameter: Internal_2_2_A
                                        * Referenced by: '<S9>/Internal_2_2'
                                        */
  1.0,                                 /* Computed Parameter: Internal_2_2_C
                                        * Referenced by: '<S9>/Internal_2_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_2_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_2_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_2_4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_3_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_3_2'
                                        */
  -0.0,                                /* Computed Parameter: Internal_3_3_A
                                        * Referenced by: '<S9>/Internal_3_3'
                                        */
  1.0,                                 /* Computed Parameter: Internal_3_3_C
                                        * Referenced by: '<S9>/Internal_3_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_3_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_3_4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_4_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_4_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_4_3'
                                        */
  -0.0,                                /* Computed Parameter: Internal_4_4_A
                                        * Referenced by: '<S9>/Internal_4_4'
                                        */
  1.0,                                 /* Computed Parameter: Internal_4_4_C
                                        * Referenced by: '<S9>/Internal_4_4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Internal_4_4'
                                        */
  -0.0,                                /* Computed Parameter: Internal_1_1_A_m
                                        * Referenced by: '<S10>/Internal_1_1'
                                        */
  1.0,                                 /* Computed Parameter: Internal_1_1_C_h
                                        * Referenced by: '<S10>/Internal_1_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Internal_1_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Internal_1_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Internal_1_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Internal_2_1'
                                        */
  -0.0,                                /* Computed Parameter: Internal_2_2_A_o
                                        * Referenced by: '<S10>/Internal_2_2'
                                        */
  1.0,                                 /* Computed Parameter: Internal_2_2_C_p
                                        * Referenced by: '<S10>/Internal_2_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Internal_2_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Internal_2_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Internal_3_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Internal_3_2'
                                        */
  -0.0,                                /* Computed Parameter: Internal_3_3_A_a
                                        * Referenced by: '<S10>/Internal_3_3'
                                        */
  1.0,                                 /* Computed Parameter: Internal_3_3_C_h
                                        * Referenced by: '<S10>/Internal_3_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Internal_3_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S55>/Constant2'
                                        */
  -42.5,                               /* Expression: -255/6
                                        * Referenced by: '<S55>/conversion to duty cycle (convert to int)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S55>/Constant1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S55>/Constant3'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S55>/Saturation 0 to 255'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S55>/Saturation 0 to 255'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S55>/Gain1'
                                        */
  -0.00872664619F,                     /* Computed Parameter: converttoradians_Gain
                                        * Referenced by: '<S2>/convert to  radians'
                                        */
  200.0F,                              /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S7>/TSamp'
                                        */
  0.005F,                              /* Computed Parameter: DiscreteTimeIntegratorconvertfr
                                        * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegratorconvert_e
                                        * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                        */
  200.0F,                              /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S8>/TSamp'
                                        */
  -0.000133231239F,                    /* Computed Parameter: converttoradianssec_Gain
                                        * Referenced by: '<S2>/convert to radians//sec'
                                        */
  0,                                   /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S55>/Switch'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S5>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: SELECTMAXorTRIAL_CurrentSetting
                                        * Referenced by: '<S1>/SELECT MAX or TRIAL'
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
                                        * Referenced by: '<S5>/Manual Switch1'
                                        */
  1U                                   /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S11>/Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
