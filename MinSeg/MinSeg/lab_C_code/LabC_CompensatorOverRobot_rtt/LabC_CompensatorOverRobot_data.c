/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabC_CompensatorOverRobot_data.c
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

#include "LabC_CompensatorOverRobot.h"
#include "LabC_CompensatorOverRobot_private.h"

/* Block parameters (auto storage) */
Parameters_LabC_CompensatorOver LabC_CompensatorOverRobot_P = {
  /*  Variable: Ad
   * Referenced by: '<S4>/Gain7'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0021693758049392887, 0.16925750888188618,
    0.01238621272879745, 3.6356607101497014, -3.5615030253047318E-5,
    -0.0095489942538593744, 1.0005975462171406, 0.21848514588281692,
    5.9371727424617068E-5, 0.017409977283227344, 0.0047409380143409053,
    0.9242486713039969 },

  /*  Variable: Bd
   * Referenced by: '<S4>/Gain8'
   */
  { 0.00013388087409070936, 0.03929187457991079, -0.00058583438582150086,
    -0.17195692548005337 },

  /*  Variable: Cd
   * Referenced by: '<S4>/Gain10'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /*  Variable: Kd
   * Referenced by: '<S1>/controller'
   */
  { -17.304393551704297, -31.649634894934358, -31.936156472342347,
    -7.7945861195728225 },

  /*  Variable: Ld
   * Referenced by: '<S4>/Gain9'
   */
  { 0.099507000772021348, -3.3344124589877486, 0.14388010155783179,
    23.274772039894991, -0.084692885328994424, 7.6531997189652987,
    0.28580626403427878, -27.993550256947334 },

  /*  Variable: Md1
   * Referenced by: '<S4>/Gain'
   */
  { 0.05556030480145116, -0.10113534077028064, 2.6596043619178928,
    -0.11015069274629463, 0.92791922632776991, 0.33104483707906851,
    0.014298299078724847, 0.001634067035223034, 0.89753584850660806 },

  /*  Variable: Md2
   * Referenced by: '<S4>/Gain1'
   */
  { 0.03227516450630305, -0.0075917043581830365, -0.23219327400276463 },

  /*  Variable: Md7
   * Referenced by: '<S4>/Gain6'
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
   * Referenced by: '<S4>/Gain2'
   */
  { -52.4101F, -52.3291321F, -449.924957F },

  /*  Variable: Md4
   * Referenced by: '<S4>/Gain3'
   */
  { 0.102468289F, 0.0745420232F, -0.0965356F },

  /*  Variable: Md5
   * Referenced by: '<S4>/Gain4'
   */
  { 52.4101F, 52.3291321F, 449.924957F },

  /*  Variable: Md6
   * Referenced by: '<S4>/Gain5'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F },
  -363.0F,                             /* Variable: fGyroBias
                                        * Referenced by: '<S2>/gyro bias'
                                        */
  0.0216F,                             /* Variable: fWheelRadius
                                        * Referenced by: '<S2>/convert to meters'
                                        */
  0.0F,                                /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S9>/UD'
                                        */
  0.0F,                                /* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                        * Referenced by: '<S10>/UD'
                                        */
  6U,                                  /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S58>/Digital Output'
                                        */
  8U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S59>/PWM'
                                        */
  0U,                                  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S13>/Serial Transmit'
                                        */
  -0.0,                                /* Computed Parameter: Internal_1_1_A
                                        * Referenced by: '<S11>/Internal_1_1'
                                        */
  1.0,                                 /* Computed Parameter: Internal_1_1_C
                                        * Referenced by: '<S11>/Internal_1_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_1_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_1_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_1_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_1_4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_2_1'
                                        */
  -0.0,                                /* Computed Parameter: Internal_2_2_A
                                        * Referenced by: '<S11>/Internal_2_2'
                                        */
  1.0,                                 /* Computed Parameter: Internal_2_2_C
                                        * Referenced by: '<S11>/Internal_2_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_2_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_2_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_2_4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_3_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_3_2'
                                        */
  -0.0,                                /* Computed Parameter: Internal_3_3_A
                                        * Referenced by: '<S11>/Internal_3_3'
                                        */
  1.0,                                 /* Computed Parameter: Internal_3_3_C
                                        * Referenced by: '<S11>/Internal_3_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_3_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_3_4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_4_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_4_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_4_3'
                                        */
  -0.0,                                /* Computed Parameter: Internal_4_4_A
                                        * Referenced by: '<S11>/Internal_4_4'
                                        */
  1.0,                                 /* Computed Parameter: Internal_4_4_C
                                        * Referenced by: '<S11>/Internal_4_4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Internal_4_4'
                                        */
  -0.0,                                /* Computed Parameter: Internal_1_1_A_m
                                        * Referenced by: '<S12>/Internal_1_1'
                                        */
  1.0,                                 /* Computed Parameter: Internal_1_1_C_h
                                        * Referenced by: '<S12>/Internal_1_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Internal_1_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Internal_1_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Internal_1_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Internal_2_1'
                                        */
  -0.0,                                /* Computed Parameter: Internal_2_2_A_o
                                        * Referenced by: '<S12>/Internal_2_2'
                                        */
  1.0,                                 /* Computed Parameter: Internal_2_2_C_p
                                        * Referenced by: '<S12>/Internal_2_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Internal_2_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Internal_2_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Internal_3_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Internal_3_2'
                                        */
  -0.0,                                /* Computed Parameter: Internal_3_3_A_a
                                        * Referenced by: '<S12>/Internal_3_3'
                                        */
  1.0,                                 /* Computed Parameter: Internal_3_3_C_h
                                        * Referenced by: '<S12>/Internal_3_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Internal_3_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S57>/Constant2'
                                        */
  -42.5,                               /* Expression: -255/6
                                        * Referenced by: '<S57>/conversion to duty cycle (convert to int)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S57>/Constant1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S57>/Constant3'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S57>/Saturation 0 to 255'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S57>/Saturation 0 to 255'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S57>/Gain1'
                                        */
  -0.00872664619F,                     /* Computed Parameter: converttoradians_Gain
                                        * Referenced by: '<S2>/convert to  radians'
                                        */
  200.0F,                              /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S9>/TSamp'
                                        */
  0.005F,                              /* Computed Parameter: DiscreteTimeIntegratorconvertfr
                                        * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegratorconvert_e
                                        * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                        */
  200.0F,                              /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S10>/TSamp'
                                        */
  -0.000133231239F,                    /* Computed Parameter: converttoradianssec_Gain
                                        * Referenced by: '<S2>/convert to radians//sec'
                                        */
  0,                                   /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S57>/Switch'
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
                                        * Referenced by: '<S13>/Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
