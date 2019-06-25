/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_ObserverAndControllerOverRobot.c
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

/* Block signals (auto storage) */
BlockIO_LabB_ObserverAndControl LabB_ObserverAndControllerOve_B;

/* Block states (auto storage) */
D_Work_LabB_ObserverAndControll LabB_ObserverAndControlle_DWork;

/* Real-time model */
RT_MODEL_LabB_ObserverAndContro LabB_ObserverAndControllerOv_M_;
RT_MODEL_LabB_ObserverAndContro *const LabB_ObserverAndControllerOv_M =
  &LabB_ObserverAndControllerOv_M_;

/* Model output function */
void LabB_ObserverAndControllerOverRobot_output(void)
{
  /* local block i/o variables */
  real32_T rtb_Fcn3;
  real32_T rtb_Internal_3_3;
  real32_T rtb_DataTypeConversion1;
  real32_T rtb_Internal_3_2;
  real32_T rtb_Fcn6;
  real32_T rtb_Product1;
  real32_T rtb_Fcn2;
  real32_T rtb_converttometers;
  uint16_T rtb_DataTypeConversion6;
  uint8_T rtb_ExtractDesiredBits;
  uint8_T rtb_ExtractDesiredBits_e;
  uint8_T rtb_ExtractDesiredBits_o;
  uint8_T rtb_ExtractDesiredBits_fb;
  uint8_T rtb_ExtractDesiredBits_mz;
  real32_T rtb_Add2[4];
  uint8_T rtb_ExtractDesiredBits_i1;
  int16_T rtb_Abs;
  real_T rtb_Switch;
  uint8_T rtb_ExtractDesiredBits_bb;
  uint8_T rtb_ExtractDesiredBits_i;
  uint8_T rtb_ExtractDesiredBits_h;
  uint8_T rtb_ExtractDesiredBits_cy;
  uint8_T rtb_ExtractDesiredBits_hv;
  uint8_T rtb_ExtractDesiredBits_j;
  uint8_T tmp[15];
  real32_T tmp_0[2];
  real32_T tmp_1[4];
  real32_T rtb_TmpSignalConversionAtGain_0;
  real32_T rtb_TmpSignalConversionAtGain_1;
  real32_T rtb_TmpSignalConversionAtGain_2;
  real32_T rtb_TmpSignalConversionAtGain_3;
  real32_T rtb_Gain8_idx_0;
  real32_T rtb_Gain8_idx_1;
  real32_T rtb_Gain8_idx_2;
  real32_T rtb_Gain8_idx_3;
  real32_T rtb_Add1_idx_0;
  real32_T rtb_Add1_idx_1;
  real32_T rtb_Add1_idx_2;
  real_T u0;

  /* S-Function (sf_QuadEncoder_18_19_15_62): '<S3>/Encoder ' */
  sf_QuadEncoder_18_19_15_62_Outputs_wrapper
    ( &LabB_ObserverAndControllerOve_B.Encoder_o1,
     &LabB_ObserverAndControllerOve_B.Encoder_o2,
     &LabB_ObserverAndControlle_DWork.Encoder_DSTATE,
     LabB_ObserverAndControllerOve_P.Encoder_P1, 2,
     LabB_ObserverAndControllerOve_P.Encoder_P2, 2,
     LabB_ObserverAndControllerOve_P.Encoder_P3, 2);

  /* Gain: '<S2>/convert to meters' incorporates:
   *  DataTypeConversion: '<S3>/Data Type  Conversion2'
   *  Gain: '<S2>/convert to  radians'
   */
  rtb_converttometers = LabB_ObserverAndControllerOve_P.converttoradians_Gain *
    (real32_T)LabB_ObserverAndControllerOve_B.Encoder_o1 *
    LabB_ObserverAndControllerOve_P.fWheelRadius;

  /* SampleTimeMath: '<S5>/TSamp'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  LabB_ObserverAndControllerOve_B.TSamp = rtb_converttometers *
    LabB_ObserverAndControllerOve_P.TSamp_WtEt;

  /* SampleTimeMath: '<S6>/TSamp' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *
   * About '<S6>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  LabB_ObserverAndControllerOve_B.TSamp_n =
    LabB_ObserverAndControlle_DWork.DiscreteTimeIntegratorconvertfr *
    LabB_ObserverAndControllerOve_P.TSamp_WtEt_m;

  /* DiscreteStateSpace: '<S7>/Internal_1_1' */
  {
    rtb_Fcn3 = LabB_ObserverAndControllerOve_P.Internal_1_1_C*
      LabB_ObserverAndControlle_DWork.Internal_1_1_DSTATE;
  }

  /* DiscreteStateSpace: '<S7>/Internal_1_2' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S7>/Internal_1_3' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S7>/Internal_1_4' */
  {
    rtb_Fcn2 = 0.0;
  }

  /* Sum: '<S7>/Sum1' */
  rtb_Fcn3 = ((rtb_Fcn3 + rtb_Internal_3_3) + rtb_Internal_3_2) + rtb_Fcn2;

  /* DiscreteStateSpace: '<S7>/Internal_2_1' */
  {
    rtb_Fcn2 = 0.0;
  }

  /* DiscreteStateSpace: '<S7>/Internal_2_2' */
  {
    rtb_Internal_3_2 = LabB_ObserverAndControllerOve_P.Internal_2_2_C*
      LabB_ObserverAndControlle_DWork.Internal_2_2_DSTATE;
  }

  /* DiscreteStateSpace: '<S7>/Internal_2_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S7>/Internal_2_4' */
  {
    rtb_Fcn6 = 0.0;
  }

  /* Sum: '<S7>/Sum2' */
  rtb_Fcn2 = ((rtb_Fcn2 + rtb_Internal_3_2) + rtb_Internal_3_3) + rtb_Fcn6;

  /* DiscreteStateSpace: '<S7>/Internal_3_1' */
  {
    rtb_Fcn6 = 0.0;
  }

  /* DiscreteStateSpace: '<S7>/Internal_3_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S7>/Internal_3_3' */
  {
    rtb_Internal_3_3 = LabB_ObserverAndControllerOve_P.Internal_3_3_C*
      LabB_ObserverAndControlle_DWork.Internal_3_3_DSTATE;
  }

  /* DiscreteStateSpace: '<S7>/Internal_3_4' */
  {
    rtb_Product1 = 0.0;
  }

  /* Sum: '<S7>/Sum3' */
  rtb_Fcn6 = ((rtb_Fcn6 + rtb_Internal_3_2) + rtb_Internal_3_3) + rtb_Product1;

  /* DiscreteStateSpace: '<S7>/Internal_4_1' */
  {
    rtb_Product1 = 0.0;
  }

  /* DiscreteStateSpace: '<S7>/Internal_4_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S7>/Internal_4_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S7>/Internal_4_4' */
  {
    rtb_DataTypeConversion1 = LabB_ObserverAndControllerOve_P.Internal_4_4_C*
      LabB_ObserverAndControlle_DWork.Internal_4_4_DSTATE;
  }

  /* Sum: '<S7>/Sum4' */
  rtb_Product1 = ((rtb_Product1 + rtb_Internal_3_2) + rtb_Internal_3_3) +
    rtb_DataTypeConversion1;

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGain10Inport1' */
  rtb_TmpSignalConversionAtGain_0 = rtb_Fcn3;
  rtb_TmpSignalConversionAtGain_1 = rtb_Fcn2;
  rtb_TmpSignalConversionAtGain_2 = rtb_Fcn6;
  rtb_TmpSignalConversionAtGain_3 = rtb_Product1;

  /* DiscreteStateSpace: '<S8>/Internal_1_1' */
  {
    rtb_DataTypeConversion1 = LabB_ObserverAndControllerOve_P.Internal_1_1_C_h*
      LabB_ObserverAndControlle_DWork.Internal_1_1_DSTATE_m;
  }

  /* DiscreteStateSpace: '<S8>/Internal_1_2' */
  {
    rtb_Product1 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_1_3' */
  {
    rtb_Fcn2 = 0.0;
  }

  /* Sum: '<S8>/Sum1' */
  rtb_DataTypeConversion1 = (rtb_DataTypeConversion1 + rtb_Product1) + rtb_Fcn2;

  /* DiscreteStateSpace: '<S8>/Internal_2_1' */
  {
    rtb_Product1 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_2_2' */
  {
    rtb_Fcn2 = LabB_ObserverAndControllerOve_P.Internal_2_2_C_p*
      LabB_ObserverAndControlle_DWork.Internal_2_2_DSTATE_p;
  }

  /* DiscreteStateSpace: '<S8>/Internal_2_3' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* Sum: '<S8>/Sum2' */
  rtb_Product1 = (rtb_Product1 + rtb_Fcn2) + rtb_Internal_3_2;

  /* DiscreteStateSpace: '<S8>/Internal_3_1' */
  {
    rtb_Fcn2 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_3_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_3_3' */
  {
    rtb_Internal_3_3 = LabB_ObserverAndControllerOve_P.Internal_3_3_C_h*
      LabB_ObserverAndControlle_DWork.Internal_3_3_DSTATE_o;
  }

  /* Sum: '<S8>/Sum3' */
  rtb_Fcn2 = (rtb_Fcn2 + rtb_Internal_3_2) + rtb_Internal_3_3;

  /* Sum: '<S4>/Add1' incorporates:
   *  Gain: '<S4>/Gain4'
   */
  rtb_Add1_idx_0 = LabB_ObserverAndControllerOve_P.Md5[0] * rtb_converttometers
    + rtb_DataTypeConversion1;
  rtb_Add1_idx_1 = LabB_ObserverAndControllerOve_P.Md5[1] * rtb_converttometers
    + rtb_Product1;
  rtb_Add1_idx_2 = LabB_ObserverAndControllerOve_P.Md5[2] * rtb_converttometers
    + rtb_Fcn2;

  /* Sum: '<S4>/Add2' incorporates:
   *  Gain: '<S4>/Gain5'
   *  Gain: '<S4>/Gain6'
   */
  for (rtb_Abs = 0; rtb_Abs < 4; rtb_Abs++) {
    rtb_Add2[rtb_Abs] = ((LabB_ObserverAndControllerOve_P.Md7[rtb_Abs + 4] *
                          rtb_Add1_idx_1 +
                          LabB_ObserverAndControllerOve_P.Md7[rtb_Abs] *
                          rtb_Add1_idx_0) +
                         LabB_ObserverAndControllerOve_P.Md7[rtb_Abs + 8] *
                         rtb_Add1_idx_2) +
      LabB_ObserverAndControllerOve_P.Md6[rtb_Abs] * rtb_converttometers;
  }

  /* End of Sum: '<S4>/Add2' */

  /* ManualSwitch: '<S4>/Manual Switch1' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  ManualSwitch: '<S4>/Manual Switch'
   *  Sum: '<S5>/Diff'
   *  Sum: '<S6>/Diff'
   *  UnitDelay: '<S5>/UD'
   *  UnitDelay: '<S6>/UD'
   */
  if (LabB_ObserverAndControllerOve_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_Gain8_idx_0 = rtb_converttometers;
    rtb_Gain8_idx_1 = LabB_ObserverAndControllerOve_B.TSamp -
      LabB_ObserverAndControlle_DWork.UD_DSTATE;
    rtb_Gain8_idx_2 =
      LabB_ObserverAndControlle_DWork.DiscreteTimeIntegratorconvertfr;
    rtb_Gain8_idx_3 = LabB_ObserverAndControllerOve_B.TSamp_n -
      LabB_ObserverAndControlle_DWork.UD_DSTATE_o;
  } else if (LabB_ObserverAndControllerOve_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<S4>/Manual Switch' incorporates:
     *  SignalConversion: '<S4>/TmpSignal ConversionAtGain10Inport1'
     */
    rtb_Gain8_idx_0 = rtb_Fcn3;
    rtb_Gain8_idx_1 = rtb_TmpSignalConversionAtGain_1;
    rtb_Gain8_idx_2 = rtb_Fcn6;
    rtb_Gain8_idx_3 = rtb_TmpSignalConversionAtGain_3;
  } else {
    rtb_Gain8_idx_0 = rtb_Add2[0];
    rtb_Gain8_idx_1 = rtb_Add2[1];
    rtb_Gain8_idx_2 = rtb_Add2[2];
    rtb_Gain8_idx_3 = rtb_Add2[3];
  }

  /* End of ManualSwitch: '<S4>/Manual Switch1' */

  /* Gain: '<S1>/controller' */
  rtb_DataTypeConversion1 = ((LabB_ObserverAndControllerOve_P.controller_Gain[0]
    * rtb_Gain8_idx_0 + LabB_ObserverAndControllerOve_P.controller_Gain[1] *
    rtb_Gain8_idx_1) + LabB_ObserverAndControllerOve_P.controller_Gain[2] *
    rtb_Gain8_idx_2) + LabB_ObserverAndControllerOve_P.controller_Gain[3] *
    rtb_Gain8_idx_3;

  /* Product: '<S1>/Product1' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Fcn: '<S1>/turn off the motor if the measured angle is greater than X degrees'
   */
  rtb_Product1 = (real32_T)((real32_T)fabs
    (LabB_ObserverAndControlle_DWork.DiscreteTimeIntegratorconvertfr) < 0.75F) *
    rtb_DataTypeConversion1;

  /* Fcn: '<S9>/Fcn' */
  rtb_Fcn2 = (rtb_DataTypeConversion1 + 10.0F) * 3276.8F;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  rtb_Gain8_idx_0 = (real32_T)floor(rtb_Fcn2);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0F);
  }

  rtb_DataTypeConversion6 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion' */

  /* DataTypeConversion: '<S39>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_bb = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S40>/Extract Desired Bits' */
  rtb_ExtractDesiredBits = (uint8_T)rtb_DataTypeConversion6;

  /* Fcn: '<S9>/Fcn1' */
  rtb_Fcn2 = (rtb_converttometers + 10.0F) * 3276.8F;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  rtb_Gain8_idx_0 = (real32_T)floor(rtb_Fcn2);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0F);
  }

  rtb_DataTypeConversion6 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion1' */

  /* DataTypeConversion: '<S45>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_i = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S46>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_e = (uint8_T)rtb_DataTypeConversion6;

  /* Fcn: '<S9>/Fcn2' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   */
  rtb_Fcn2 = (LabB_ObserverAndControlle_DWork.DiscreteTimeIntegratorconvertfr +
              10.0F) * 3276.8F;

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  rtb_Gain8_idx_0 = (real32_T)floor(rtb_Fcn2);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0F);
  }

  rtb_DataTypeConversion6 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion2' */

  /* DataTypeConversion: '<S47>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_h = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S48>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_o = (uint8_T)rtb_DataTypeConversion6;

  /* Fcn: '<S9>/Fcn3' */
  rtb_Fcn3 = (rtb_Fcn3 + 10.0F) * 3276.8F;

  /* DataTypeConversion: '<S9>/Data Type Conversion3' */
  rtb_Gain8_idx_0 = (real32_T)floor(rtb_Fcn3);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0F);
  }

  rtb_DataTypeConversion6 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion3' */

  /* DataTypeConversion: '<S49>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_cy = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S50>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_fb = (uint8_T)rtb_DataTypeConversion6;

  /* Fcn: '<S9>/Fcn4' */
  rtb_Fcn6 = (rtb_Fcn6 + 10.0F) * 3276.8F;

  /* DataTypeConversion: '<S9>/Data Type Conversion4' */
  rtb_Gain8_idx_0 = (real32_T)floor(rtb_Fcn6);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0F);
  }

  rtb_DataTypeConversion6 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion4' */

  /* DataTypeConversion: '<S51>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_hv = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S52>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_mz = (uint8_T)rtb_DataTypeConversion6;

  /* Fcn: '<S9>/Fcn5' */
  rtb_Fcn6 = (rtb_Add2[0] + 10.0F) * 3276.8F;

  /* DataTypeConversion: '<S9>/Data Type Conversion5' */
  rtb_Gain8_idx_0 = (real32_T)floor(rtb_Fcn6);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0F);
  }

  rtb_DataTypeConversion6 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion5' */

  /* DataTypeConversion: '<S41>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_j = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S42>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_i1 = (uint8_T)rtb_DataTypeConversion6;

  /* Fcn: '<S9>/Fcn6' */
  rtb_Fcn6 = (rtb_Add2[2] + 10.0F) * 3276.8F;

  /* DataTypeConversion: '<S9>/Data Type Conversion6' */
  rtb_Gain8_idx_0 = (real32_T)floor(rtb_Fcn6);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0F);
  }

  rtb_DataTypeConversion6 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion6' */

  /* S-Function (arduinoserialwrite_sfcn): '<S9>/Serial Transmit' incorporates:
   *  Constant: '<S9>/Constant'
   *  DataTypeConversion: '<S43>/Extract Desired Bits'
   *  DataTypeConversion: '<S44>/Extract Desired Bits'
   *  SignalConversion: '<S9>/TmpSignal ConversionAtSerial TransmitInport1'
   */
  tmp[0] = LabB_ObserverAndControllerOve_P.Constant_Value;
  tmp[1] = rtb_ExtractDesiredBits_bb;
  tmp[2] = rtb_ExtractDesiredBits;
  tmp[3] = rtb_ExtractDesiredBits_i;
  tmp[4] = rtb_ExtractDesiredBits_e;
  tmp[5] = rtb_ExtractDesiredBits_h;
  tmp[6] = rtb_ExtractDesiredBits_o;
  tmp[7] = rtb_ExtractDesiredBits_cy;
  tmp[8] = rtb_ExtractDesiredBits_fb;
  tmp[9] = rtb_ExtractDesiredBits_hv;
  tmp[10] = rtb_ExtractDesiredBits_mz;
  tmp[11] = rtb_ExtractDesiredBits_j;
  tmp[12] = rtb_ExtractDesiredBits_i1;
  tmp[13] = (uint8_T)(rtb_DataTypeConversion6 >> 8);
  tmp[14] = (uint8_T)rtb_DataTypeConversion6;
  Serial_write(LabB_ObserverAndControllerOve_P.SerialTransmit_portNumber, tmp,
               15UL);

  /* Sum: '<S4>/Add' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/Gain2'
   *  Gain: '<S4>/Gain3'
   */
  for (rtb_Abs = 0; rtb_Abs < 3; rtb_Abs++) {
    LabB_ObserverAndControllerOve_B.Add[rtb_Abs] =
      ((LabB_ObserverAndControllerOve_P.Md1[rtb_Abs + 3] * rtb_Add1_idx_1 +
        LabB_ObserverAndControllerOve_P.Md1[rtb_Abs] * rtb_Add1_idx_0) +
       LabB_ObserverAndControllerOve_P.Md1[rtb_Abs + 6] * rtb_Add1_idx_2) +
      ((LabB_ObserverAndControllerOve_P.Md4[rtb_Abs] *
        LabB_ObserverAndControlle_DWork.DiscreteTimeIntegratorconvertfr +
        LabB_ObserverAndControllerOve_P.Md3[rtb_Abs] * rtb_converttometers) +
       LabB_ObserverAndControllerOve_P.Md2[rtb_Abs] * rtb_DataTypeConversion1);
  }

  /* End of Sum: '<S4>/Add' */

  /* Gain: '<S4>/Gain10' incorporates:
   *  Sum: '<S4>/Sum'
   */
  for (rtb_Abs = 0; rtb_Abs < 2; rtb_Abs++) {
    rtb_Gain8_idx_0 = LabB_ObserverAndControllerOve_P.Cd[rtb_Abs + 6] *
      rtb_TmpSignalConversionAtGain_3 +
      (LabB_ObserverAndControllerOve_P.Cd[rtb_Abs + 4] *
       rtb_TmpSignalConversionAtGain_2 +
       (LabB_ObserverAndControllerOve_P.Cd[rtb_Abs + 2] *
        rtb_TmpSignalConversionAtGain_1 +
        LabB_ObserverAndControllerOve_P.Cd[rtb_Abs] *
        rtb_TmpSignalConversionAtGain_0));
    tmp_0[rtb_Abs] = rtb_Gain8_idx_0;
  }

  /* End of Gain: '<S4>/Gain10' */

  /* Sum: '<S4>/Sum' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Gain: '<S4>/Gain9'
   */
  rtb_Gain8_idx_0 = rtb_converttometers - tmp_0[0];
  rtb_Gain8_idx_1 =
    LabB_ObserverAndControlle_DWork.DiscreteTimeIntegratorconvertfr - tmp_0[1];

  /* Sum: '<S4>/Add3' incorporates:
   *  Gain: '<S4>/Gain8'
   *  Gain: '<S4>/Gain9'
   */
  for (rtb_Abs = 0; rtb_Abs < 4; rtb_Abs++) {
    rtb_Add2[rtb_Abs] = (LabB_ObserverAndControllerOve_P.Ld[rtb_Abs + 4] *
                         rtb_Gain8_idx_1 +
                         LabB_ObserverAndControllerOve_P.Ld[rtb_Abs] *
                         rtb_Gain8_idx_0) +
      LabB_ObserverAndControllerOve_P.Bd[rtb_Abs] * rtb_DataTypeConversion1;
  }

  /* Gain: '<S4>/Gain7' incorporates:
   *  Sum: '<S4>/Add3'
   */
  for (rtb_Abs = 0; rtb_Abs < 4; rtb_Abs++) {
    rtb_Gain8_idx_0 = LabB_ObserverAndControllerOve_P.Ad[rtb_Abs + 12] *
      rtb_TmpSignalConversionAtGain_3 +
      (LabB_ObserverAndControllerOve_P.Ad[rtb_Abs + 8] *
       rtb_TmpSignalConversionAtGain_2 +
       (LabB_ObserverAndControllerOve_P.Ad[rtb_Abs + 4] *
        rtb_TmpSignalConversionAtGain_1 +
        LabB_ObserverAndControllerOve_P.Ad[rtb_Abs] *
        rtb_TmpSignalConversionAtGain_0));
    tmp_1[rtb_Abs] = rtb_Gain8_idx_0;
  }

  /* End of Gain: '<S4>/Gain7' */

  /* Sum: '<S4>/Add3' */
  LabB_ObserverAndControllerOve_B.Add3[0] = rtb_Add2[0] + tmp_1[0];
  LabB_ObserverAndControllerOve_B.Add3[1] = rtb_Add2[1] + tmp_1[1];
  LabB_ObserverAndControllerOve_B.Add3[2] = rtb_Add2[2] + tmp_1[2];
  LabB_ObserverAndControllerOve_B.Add3[3] = rtb_Add2[3] + tmp_1[3];

  /* S-Function (sf_MPU6050_Driver_GxAyz): '<S3>/Gyro and Accelerometer' */
  sf_MPU6050_Driver_GxAyz_Outputs_wrapper
    ( &LabB_ObserverAndControllerOve_B.GyroandAccelerometer_o1,
     &LabB_ObserverAndControllerOve_B.GyroandAccelerometer_o2,
     &LabB_ObserverAndControllerOve_B.GyroandAccelerometer_o3,
     &LabB_ObserverAndControlle_DWork.GyroandAccelerometer_DSTATE);

  /* DataTypeConversion: '<S3>/Data Type  Conversion1' */
  rtb_DataTypeConversion1 =
    LabB_ObserverAndControllerOve_B.GyroandAccelerometer_o1;

  /* Gain: '<S2>/convert to radians//sec' incorporates:
   *  Constant: '<S2>/gyro bias'
   *  Sum: '<S2>/Sum'
   */
  LabB_ObserverAndControllerOve_B.converttoradianssec = (rtb_DataTypeConversion1
    - LabB_ObserverAndControllerOve_P.fGyroBias) *
    LabB_ObserverAndControllerOve_P.converttoradianssec_Gain;

  /* Gain: '<S53>/conversion to duty cycle (convert to int)' */
  rtb_Gain8_idx_0 = (real32_T)floor
    (LabB_ObserverAndControllerOve_P.conversiontodutycycleconverttoi *
     rtb_Product1);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0F);
  }

  rtb_Abs = rtb_Gain8_idx_0 < 0.0F ? -(int16_T)(uint16_T)-rtb_Gain8_idx_0 :
    (int16_T)(uint16_T)rtb_Gain8_idx_0;

  /* End of Gain: '<S53>/conversion to duty cycle (convert to int)' */

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S53>/Constant1'
   *  Constant: '<S53>/Constant2'
   */
  if (rtb_Abs >= LabB_ObserverAndControllerOve_P.Switch_Threshold) {
    rtb_Switch = LabB_ObserverAndControllerOve_P.Constant2_Value;
  } else {
    rtb_Switch = LabB_ObserverAndControllerOve_P.Constant1_Value;
  }

  /* End of Switch: '<S53>/Switch' */

  /* DataTypeConversion: '<S54>/Data Type Conversion' */
  if (rtb_Switch < 256.0) {
    if (rtb_Switch >= 0.0) {
      rtb_ExtractDesiredBits_bb = (uint8_T)rtb_Switch;
    } else {
      rtb_ExtractDesiredBits_bb = 0U;
    }
  } else {
    rtb_ExtractDesiredBits_bb = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S54>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S54>/Digital Output' */
  MW_digitalWrite(LabB_ObserverAndControllerOve_P.DigitalOutput_pinNumber,
                  rtb_ExtractDesiredBits_bb);

  /* Abs: '<S53>/Abs' */
  if (rtb_Abs < 0) {
    rtb_Abs = -rtb_Abs;
  }

  /* End of Abs: '<S53>/Abs' */

  /* Sum: '<S53>/Add2' incorporates:
   *  Constant: '<S53>/Constant3'
   */
  u0 = LabB_ObserverAndControllerOve_P.Constant3_Value + (real_T)rtb_Abs;

  /* Saturate: '<S53>/Saturation 0 to 255' */
  if (u0 > LabB_ObserverAndControllerOve_P.Saturation0to255_UpperSat) {
    u0 = LabB_ObserverAndControllerOve_P.Saturation0to255_UpperSat;
  } else {
    if (u0 < LabB_ObserverAndControllerOve_P.Saturation0to255_LowerSat) {
      u0 = LabB_ObserverAndControllerOve_P.Saturation0to255_LowerSat;
    }
  }

  /* DataTypeConversion: '<S55>/Data Type Conversion' incorporates:
   *  Abs: '<S53>/Abs3'
   *  Gain: '<S53>/Gain1'
   *  Saturate: '<S53>/Saturation 0 to 255'
   *  Sum: '<S53>/Add1'
   */
  rtb_Switch = fabs(LabB_ObserverAndControllerOve_P.Gain1_Gain * rtb_Switch - u0);
  if (rtb_Switch < 256.0) {
    rtb_ExtractDesiredBits_bb = (uint8_T)rtb_Switch;
  } else {
    rtb_ExtractDesiredBits_bb = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S55>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S55>/PWM' */
  MW_analogWrite(LabB_ObserverAndControllerOve_P.PWM_pinNumber,
                 rtb_ExtractDesiredBits_bb);
}

/* Model update function */
void LabB_ObserverAndControllerOverRobot_update(void)
{
  /* S-Function "sf_QuadEncoder_18_19_15_62_wrapper" Block: <S3>/Encoder  */
  sf_QuadEncoder_18_19_15_62_Update_wrapper
    ( &LabB_ObserverAndControllerOve_B.Encoder_o1,
     &LabB_ObserverAndControllerOve_B.Encoder_o2,
     &LabB_ObserverAndControlle_DWork.Encoder_DSTATE,
     LabB_ObserverAndControllerOve_P.Encoder_P1, 2,
     LabB_ObserverAndControllerOve_P.Encoder_P2, 2,
     LabB_ObserverAndControllerOve_P.Encoder_P3, 2);

  /* Update for UnitDelay: '<S5>/UD' */
  LabB_ObserverAndControlle_DWork.UD_DSTATE =
    LabB_ObserverAndControllerOve_B.TSamp;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  LabB_ObserverAndControlle_DWork.DiscreteTimeIntegratorconvertfr +=
    LabB_ObserverAndControllerOve_P.DiscreteTimeIntegratorconvertfr *
    LabB_ObserverAndControllerOve_B.converttoradianssec;

  /* Update for UnitDelay: '<S6>/UD' */
  LabB_ObserverAndControlle_DWork.UD_DSTATE_o =
    LabB_ObserverAndControllerOve_B.TSamp_n;

  /* Update for DiscreteStateSpace: '<S7>/Internal_1_1' */
  {
    LabB_ObserverAndControlle_DWork.Internal_1_1_DSTATE =
      LabB_ObserverAndControllerOve_B.Add3[0] +
      (LabB_ObserverAndControllerOve_P.Internal_1_1_A)*
      LabB_ObserverAndControlle_DWork.Internal_1_1_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S7>/Internal_2_2' */
  {
    LabB_ObserverAndControlle_DWork.Internal_2_2_DSTATE =
      LabB_ObserverAndControllerOve_B.Add3[1] +
      (LabB_ObserverAndControllerOve_P.Internal_2_2_A)*
      LabB_ObserverAndControlle_DWork.Internal_2_2_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S7>/Internal_3_3' */
  {
    LabB_ObserverAndControlle_DWork.Internal_3_3_DSTATE =
      LabB_ObserverAndControllerOve_B.Add3[2] +
      (LabB_ObserverAndControllerOve_P.Internal_3_3_A)*
      LabB_ObserverAndControlle_DWork.Internal_3_3_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S7>/Internal_4_4' */
  {
    LabB_ObserverAndControlle_DWork.Internal_4_4_DSTATE =
      LabB_ObserverAndControllerOve_B.Add3[3] +
      (LabB_ObserverAndControllerOve_P.Internal_4_4_A)*
      LabB_ObserverAndControlle_DWork.Internal_4_4_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S8>/Internal_1_1' */
  {
    LabB_ObserverAndControlle_DWork.Internal_1_1_DSTATE_m =
      LabB_ObserverAndControllerOve_B.Add[0] +
      (LabB_ObserverAndControllerOve_P.Internal_1_1_A_m)*
      LabB_ObserverAndControlle_DWork.Internal_1_1_DSTATE_m;
  }

  /* Update for DiscreteStateSpace: '<S8>/Internal_2_2' */
  {
    LabB_ObserverAndControlle_DWork.Internal_2_2_DSTATE_p =
      LabB_ObserverAndControllerOve_B.Add[1] +
      (LabB_ObserverAndControllerOve_P.Internal_2_2_A_o)*
      LabB_ObserverAndControlle_DWork.Internal_2_2_DSTATE_p;
  }

  /* Update for DiscreteStateSpace: '<S8>/Internal_3_3' */
  {
    LabB_ObserverAndControlle_DWork.Internal_3_3_DSTATE_o =
      LabB_ObserverAndControllerOve_B.Add[2] +
      (LabB_ObserverAndControllerOve_P.Internal_3_3_A_a)*
      LabB_ObserverAndControlle_DWork.Internal_3_3_DSTATE_o;
  }

  /* S-Function "sf_MPU6050_Driver_GxAyz_wrapper" Block: <S3>/Gyro and Accelerometer */
  sf_MPU6050_Driver_GxAyz_Update_wrapper
    ( &LabB_ObserverAndControllerOve_B.GyroandAccelerometer_o1,
     &LabB_ObserverAndControllerOve_B.GyroandAccelerometer_o2,
     &LabB_ObserverAndControllerOve_B.GyroandAccelerometer_o3,
     &LabB_ObserverAndControlle_DWork.GyroandAccelerometer_DSTATE);
}

/* Model initialize function */
void LabB_ObserverAndControllerOverRobot_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(LabB_ObserverAndControllerOv_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &LabB_ObserverAndControllerOve_B), 0,
                sizeof(BlockIO_LabB_ObserverAndControl));

  /* states (dwork) */
  (void) memset((void *)&LabB_ObserverAndControlle_DWork, 0,
                sizeof(D_Work_LabB_ObserverAndControll));

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S54>/Digital Output' */
  MW_pinModeOutput(LabB_ObserverAndControllerOve_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S55>/PWM' */
  MW_pinModeOutput(LabB_ObserverAndControllerOve_P.PWM_pinNumber);

  /* S-Function Block: <S3>/Encoder  */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        LabB_ObserverAndControlle_DWork.Encoder_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for UnitDelay: '<S5>/UD' */
  LabB_ObserverAndControlle_DWork.UD_DSTATE =
    LabB_ObserverAndControllerOve_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  LabB_ObserverAndControlle_DWork.DiscreteTimeIntegratorconvertfr =
    LabB_ObserverAndControllerOve_P.DiscreteTimeIntegratorconvert_e;

  /* InitializeConditions for UnitDelay: '<S6>/UD' */
  LabB_ObserverAndControlle_DWork.UD_DSTATE_o =
    LabB_ObserverAndControllerOve_P.DiscreteDerivative_ICPrevScal_n;

  /* S-Function Block: <S3>/Gyro and Accelerometer */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        LabB_ObserverAndControlle_DWork.GyroandAccelerometer_DSTATE =
          initVector[0];
      }
    }
  }
}

/* Model terminate function */
void LabB_ObserverAndControllerOverRobot_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
