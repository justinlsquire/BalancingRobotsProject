/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabC_CompensatorOverRobot.c
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

/* Block signals (auto storage) */
BlockIO_LabC_CompensatorOverRob LabC_CompensatorOverRobot_B;

/* Block states (auto storage) */
D_Work_LabC_CompensatorOverRobo LabC_CompensatorOverRobot_DWork;

/* Real-time model */
RT_MODEL_LabC_CompensatorOverRo LabC_CompensatorOverRobot_M_;
RT_MODEL_LabC_CompensatorOverRo *const LabC_CompensatorOverRobot_M =
  &LabC_CompensatorOverRobot_M_;

/* Model output function */
void LabC_CompensatorOverRobot_output(void)
{
  /* local block i/o variables */
  real_T rtb_controller;
  real_T rtb_Internal_4_4;
  real_T rtb_Internal_3_3;
  real_T rtb_Internal_3_2;
  real_T rtb_Fcn4;
  real_T rtb_Gain3;
  uint16_T rtb_DataTypeConversion6;
  uint16_T rtb_DataTypeConversion4;
  uint8_T rtb_ExtractDesiredBits;
  uint8_T rtb_ExtractDesiredBits_h;
  real_T rtb_Add2[4];
  int16_T rtb_Abs;
  uint8_T rtb_ExtractDesiredBits_g;
  uint8_T rtb_ExtractDesiredBits_p;
  real32_T converttometers;
  uint8_T ExtractDesiredBits;
  uint8_T ExtractDesiredBits_k;
  real_T Sum1;
  real_T Sum3;
  uint8_T ExtractDesiredBits_j;
  real_T Sum2;
  real_T Sum4;
  real_T Sum1_l;
  real_T Sum2_p;
  uint8_T ExtractDesiredBits_n;
  uint8_T ExtractDesiredBits_jl;
  uint8_T ExtractDesiredBits_ki;
  uint8_T tmp[15];
  real_T tmp_0[4];
  real_T rtb_Gain8_idx_2;
  real_T rtb_Gain8_idx_3;
  real_T rtb_Add1_idx_0;
  real_T rtb_Add1_idx_1;
  real_T rtb_Add1_idx_2;
  real32_T tmp_1;

  /* FromWorkspace: '<S8>/FromWs' */
  {
    real_T *pDataValues = (real_T *)
      LabC_CompensatorOverRobot_DWork.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      LabC_CompensatorOverRobot_DWork.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = LabC_CompensatorOverRobot_DWork.FromWs_IWORK.PrevIndex;
    real_T t = LabC_CompensatorOverRobot_M->Timing.t[0];
    if (t >= pTimeValues[1]) {
      rtb_controller = pDataValues[1];
    } else {
      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[1]) {
        currTimeIndex = 0;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      LabC_CompensatorOverRobot_DWork.FromWs_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_controller = pDataValues[currTimeIndex];
          } else {
            rtb_controller = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex= currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_controller = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 2;
        }
      }
    }
  }

  /* Gain: '<S1>/Gain3' */
  rtb_Gain3 = LabC_CompensatorOverRobot_P.Nud * rtb_controller;

  /* S-Function (sf_QuadEncoder_18_19_15_62): '<S3>/Encoder ' */
  sf_QuadEncoder_18_19_15_62_Outputs_wrapper
    ( &LabC_CompensatorOverRobot_B.Encoder_o1,
     &LabC_CompensatorOverRobot_B.Encoder_o2,
     &LabC_CompensatorOverRobot_DWork.Encoder_DSTATE,
     LabC_CompensatorOverRobot_P.Encoder_P1, 2,
     LabC_CompensatorOverRobot_P.Encoder_P2, 2,
     LabC_CompensatorOverRobot_P.Encoder_P3, 2);

  /* Gain: '<S2>/convert to meters' incorporates:
   *  DataTypeConversion: '<S3>/Data Type  Conversion2'
   *  Gain: '<S2>/convert to  radians'
   */
  converttometers = LabC_CompensatorOverRobot_P.converttoradians_Gain *
    (real32_T)LabC_CompensatorOverRobot_B.Encoder_o1 *
    LabC_CompensatorOverRobot_P.fWheelRadius;

  /* SampleTimeMath: '<S9>/TSamp'
   *
   * About '<S9>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  LabC_CompensatorOverRobot_B.TSamp = converttometers *
    LabC_CompensatorOverRobot_P.TSamp_WtEt;

  /* SampleTimeMath: '<S10>/TSamp' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *
   * About '<S10>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  LabC_CompensatorOverRobot_B.TSamp_n =
    LabC_CompensatorOverRobot_DWork.DiscreteTimeIntegratorconvertfr *
    LabC_CompensatorOverRobot_P.TSamp_WtEt_m;

  /* DiscreteStateSpace: '<S11>/Internal_1_1' */
  {
    rtb_Internal_4_4 = LabC_CompensatorOverRobot_P.Internal_1_1_C*
      LabC_CompensatorOverRobot_DWork.Internal_1_1_DSTATE;
  }

  /* DiscreteStateSpace: '<S11>/Internal_1_2' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S11>/Internal_1_3' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S11>/Internal_1_4' */
  {
    rtb_Fcn4 = 0.0;
  }

  /* Sum: '<S11>/Sum1' */
  Sum1 = ((rtb_Internal_4_4 + rtb_Internal_3_3) + rtb_Internal_3_2) + rtb_Fcn4;

  /* DiscreteStateSpace: '<S11>/Internal_2_1' */
  {
    rtb_Fcn4 = 0.0;
  }

  /* DiscreteStateSpace: '<S11>/Internal_2_2' */
  {
    rtb_Internal_3_2 = LabC_CompensatorOverRobot_P.Internal_2_2_C*
      LabC_CompensatorOverRobot_DWork.Internal_2_2_DSTATE;
  }

  /* DiscreteStateSpace: '<S11>/Internal_2_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S11>/Internal_2_4' */
  {
    rtb_Internal_4_4 = 0.0;
  }

  /* Sum: '<S11>/Sum2' */
  Sum2 = ((rtb_Fcn4 + rtb_Internal_3_2) + rtb_Internal_3_3) + rtb_Internal_4_4;

  /* DiscreteStateSpace: '<S11>/Internal_3_1' */
  {
    rtb_Fcn4 = 0.0;
  }

  /* DiscreteStateSpace: '<S11>/Internal_3_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S11>/Internal_3_3' */
  {
    rtb_Internal_3_3 = LabC_CompensatorOverRobot_P.Internal_3_3_C*
      LabC_CompensatorOverRobot_DWork.Internal_3_3_DSTATE;
  }

  /* DiscreteStateSpace: '<S11>/Internal_3_4' */
  {
    rtb_Internal_4_4 = 0.0;
  }

  /* Sum: '<S11>/Sum3' */
  Sum3 = ((rtb_Fcn4 + rtb_Internal_3_2) + rtb_Internal_3_3) + rtb_Internal_4_4;

  /* DiscreteStateSpace: '<S11>/Internal_4_1' */
  {
    rtb_Fcn4 = 0.0;
  }

  /* DiscreteStateSpace: '<S11>/Internal_4_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S11>/Internal_4_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S11>/Internal_4_4' */
  {
    rtb_Internal_4_4 = LabC_CompensatorOverRobot_P.Internal_4_4_C*
      LabC_CompensatorOverRobot_DWork.Internal_4_4_DSTATE;
  }

  /* Sum: '<S11>/Sum4' */
  Sum4 = ((rtb_Fcn4 + rtb_Internal_3_2) + rtb_Internal_3_3) + rtb_Internal_4_4;

  /* DiscreteStateSpace: '<S12>/Internal_1_1' */
  {
    rtb_Fcn4 = LabC_CompensatorOverRobot_P.Internal_1_1_C_h*
      LabC_CompensatorOverRobot_DWork.Internal_1_1_DSTATE_m;
  }

  /* DiscreteStateSpace: '<S12>/Internal_1_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S12>/Internal_1_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* Sum: '<S12>/Sum1' */
  Sum1_l = (rtb_Fcn4 + rtb_Internal_3_2) + rtb_Internal_3_3;

  /* DiscreteStateSpace: '<S12>/Internal_2_1' */
  {
    rtb_Fcn4 = 0.0;
  }

  /* DiscreteStateSpace: '<S12>/Internal_2_2' */
  {
    rtb_Internal_3_2 = LabC_CompensatorOverRobot_P.Internal_2_2_C_p*
      LabC_CompensatorOverRobot_DWork.Internal_2_2_DSTATE_p;
  }

  /* DiscreteStateSpace: '<S12>/Internal_2_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* Sum: '<S12>/Sum2' */
  Sum2_p = (rtb_Fcn4 + rtb_Internal_3_2) + rtb_Internal_3_3;

  /* DiscreteStateSpace: '<S12>/Internal_3_1' */
  {
    rtb_Fcn4 = 0.0;
  }

  /* DiscreteStateSpace: '<S12>/Internal_3_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S12>/Internal_3_3' */
  {
    rtb_Internal_3_3 = LabC_CompensatorOverRobot_P.Internal_3_3_C_h*
      LabC_CompensatorOverRobot_DWork.Internal_3_3_DSTATE_o;
  }

  /* Sum: '<S4>/Add1' incorporates:
   *  Gain: '<S4>/Gain4'
   *  Sum: '<S12>/Sum3'
   */
  rtb_Add1_idx_0 = LabC_CompensatorOverRobot_P.Md5[0] * converttometers + Sum1_l;
  rtb_Add1_idx_1 = LabC_CompensatorOverRobot_P.Md5[1] * converttometers + Sum2_p;
  rtb_Add1_idx_2 = ((rtb_Fcn4 + rtb_Internal_3_2) + rtb_Internal_3_3) +
    LabC_CompensatorOverRobot_P.Md5[2] * converttometers;

  /* Sum: '<S4>/Add2' incorporates:
   *  Gain: '<S4>/Gain5'
   *  Gain: '<S4>/Gain6'
   */
  for (rtb_Abs = 0; rtb_Abs < 4; rtb_Abs++) {
    rtb_Add2[rtb_Abs] = ((LabC_CompensatorOverRobot_P.Md7[rtb_Abs + 4] *
                          rtb_Add1_idx_1 +
                          LabC_CompensatorOverRobot_P.Md7[rtb_Abs] *
                          rtb_Add1_idx_0) +
                         LabC_CompensatorOverRobot_P.Md7[rtb_Abs + 8] *
                         rtb_Add1_idx_2) +
      LabC_CompensatorOverRobot_P.Md6[rtb_Abs] * converttometers;
  }

  /* End of Sum: '<S4>/Add2' */

  /* ManualSwitch: '<S4>/Manual Switch1' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  ManualSwitch: '<S4>/Manual Switch'
   *  Sum: '<S10>/Diff'
   *  Sum: '<S9>/Diff'
   *  UnitDelay: '<S10>/UD'
   *  UnitDelay: '<S9>/UD'
   */
  if (LabC_CompensatorOverRobot_P.ManualSwitch1_CurrentSetting == 1) {
    Sum1_l = converttometers;
    Sum2_p = LabC_CompensatorOverRobot_B.TSamp -
      LabC_CompensatorOverRobot_DWork.UD_DSTATE;
    rtb_Gain8_idx_2 =
      LabC_CompensatorOverRobot_DWork.DiscreteTimeIntegratorconvertfr;
    rtb_Gain8_idx_3 = LabC_CompensatorOverRobot_B.TSamp_n -
      LabC_CompensatorOverRobot_DWork.UD_DSTATE_o;
  } else if (LabC_CompensatorOverRobot_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<S4>/Manual Switch' */
    Sum1_l = Sum1;
    Sum2_p = Sum2;
    rtb_Gain8_idx_2 = Sum3;
    rtb_Gain8_idx_3 = Sum4;
  } else {
    Sum1_l = rtb_Add2[0];
    Sum2_p = rtb_Add2[1];
    rtb_Gain8_idx_2 = rtb_Add2[2];
    rtb_Gain8_idx_3 = rtb_Add2[3];
  }

  /* End of ManualSwitch: '<S4>/Manual Switch1' */

  /* Gain: '<S1>/controller' incorporates:
   *  Gain: '<S1>/Gain2'
   *  Sum: '<S1>/Sum'
   */
  rtb_controller = (((-LabC_CompensatorOverRobot_P.Nxd[0] * rtb_controller +
                      Sum1_l) * -LabC_CompensatorOverRobot_P.Kd[0] +
                     (-LabC_CompensatorOverRobot_P.Nxd[1] * rtb_controller +
                      Sum2_p) * -LabC_CompensatorOverRobot_P.Kd[1]) +
                    (-LabC_CompensatorOverRobot_P.Nxd[2] * rtb_controller +
                     rtb_Gain8_idx_2) * -LabC_CompensatorOverRobot_P.Kd[2]) +
    (-LabC_CompensatorOverRobot_P.Nxd[3] * rtb_controller + rtb_Gain8_idx_3) *
    -LabC_CompensatorOverRobot_P.Kd[3];

  /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
   *  Fcn: '<S13>/Fcn'
   */
  Sum1_l = floor((rtb_controller + 10.0) * 3276.8);
  if (rtIsNaN(Sum1_l) || rtIsInf(Sum1_l)) {
    Sum1_l = 0.0;
  } else {
    Sum1_l = fmod(Sum1_l, 65536.0);
  }

  rtb_DataTypeConversion6 = Sum1_l < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-Sum1_l
    : (uint16_T)Sum1_l;

  /* End of DataTypeConversion: '<S13>/Data Type Conversion' */

  /* DataTypeConversion: '<S43>/Extract Desired Bits' */
  ExtractDesiredBits_n = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S44>/Extract Desired Bits' */
  ExtractDesiredBits = (uint8_T)rtb_DataTypeConversion6;

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Fcn: '<S13>/Fcn1'
   */
  tmp_1 = (real32_T)floor((converttometers + 10.0F) * 3276.8F);
  if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
    tmp_1 = 0.0F;
  } else {
    tmp_1 = (real32_T)fmod(tmp_1, 65536.0F);
  }

  rtb_DataTypeConversion6 = tmp_1 < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-tmp_1 :
    (uint16_T)tmp_1;

  /* End of DataTypeConversion: '<S13>/Data Type Conversion1' */

  /* DataTypeConversion: '<S49>/Extract Desired Bits' */
  ExtractDesiredBits_jl = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S50>/Extract Desired Bits' */
  ExtractDesiredBits_k = (uint8_T)rtb_DataTypeConversion6;

  /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Fcn: '<S13>/Fcn2'
   */
  tmp_1 = (real32_T)floor
    ((LabC_CompensatorOverRobot_DWork.DiscreteTimeIntegratorconvertfr + 10.0F) *
     3276.8F);
  if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
    tmp_1 = 0.0F;
  } else {
    tmp_1 = (real32_T)fmod(tmp_1, 65536.0F);
  }

  rtb_DataTypeConversion4 = tmp_1 < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-tmp_1 :
    (uint16_T)tmp_1;

  /* End of DataTypeConversion: '<S13>/Data Type Conversion2' */

  /* DataTypeConversion: '<S51>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_g = (uint8_T)(rtb_DataTypeConversion4 >> 8);

  /* DataTypeConversion: '<S52>/Extract Desired Bits' */
  rtb_ExtractDesiredBits = (uint8_T)rtb_DataTypeConversion4;

  /* Fcn: '<S13>/Fcn3' */
  rtb_Fcn4 = (Sum1 + 10.0) * 3276.8;

  /* DataTypeConversion: '<S13>/Data Type Conversion3' */
  Sum1_l = floor(rtb_Fcn4);
  if (rtIsNaN(Sum1_l) || rtIsInf(Sum1_l)) {
    Sum1_l = 0.0;
  } else {
    Sum1_l = fmod(Sum1_l, 65536.0);
  }

  rtb_DataTypeConversion4 = Sum1_l < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-Sum1_l
    : (uint16_T)Sum1_l;

  /* End of DataTypeConversion: '<S13>/Data Type Conversion3' */

  /* DataTypeConversion: '<S53>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_p = (uint8_T)(rtb_DataTypeConversion4 >> 8);

  /* DataTypeConversion: '<S54>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_h = (uint8_T)rtb_DataTypeConversion4;

  /* Fcn: '<S13>/Fcn4' */
  rtb_Fcn4 = (Sum3 + 10.0) * 3276.8;

  /* DataTypeConversion: '<S13>/Data Type Conversion4' */
  Sum1_l = floor(rtb_Fcn4);
  if (rtIsNaN(Sum1_l) || rtIsInf(Sum1_l)) {
    Sum1_l = 0.0;
  } else {
    Sum1_l = fmod(Sum1_l, 65536.0);
  }

  rtb_DataTypeConversion4 = Sum1_l < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-Sum1_l
    : (uint16_T)Sum1_l;

  /* End of DataTypeConversion: '<S13>/Data Type Conversion4' */

  /* DataTypeConversion: '<S13>/Data Type Conversion5' incorporates:
   *  Fcn: '<S13>/Fcn5'
   */
  Sum1_l = floor((rtb_Add2[0] + 10.0) * 3276.8);
  if (rtIsNaN(Sum1_l) || rtIsInf(Sum1_l)) {
    Sum1_l = 0.0;
  } else {
    Sum1_l = fmod(Sum1_l, 65536.0);
  }

  rtb_DataTypeConversion6 = Sum1_l < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-Sum1_l
    : (uint16_T)Sum1_l;

  /* End of DataTypeConversion: '<S13>/Data Type Conversion5' */

  /* DataTypeConversion: '<S45>/Extract Desired Bits' */
  ExtractDesiredBits_ki = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S46>/Extract Desired Bits' */
  ExtractDesiredBits_j = (uint8_T)rtb_DataTypeConversion6;

  /* DataTypeConversion: '<S13>/Data Type Conversion6' incorporates:
   *  Fcn: '<S13>/Fcn6'
   */
  Sum1_l = floor((rtb_Add2[2] + 10.0) * 3276.8);
  if (rtIsNaN(Sum1_l) || rtIsInf(Sum1_l)) {
    Sum1_l = 0.0;
  } else {
    Sum1_l = fmod(Sum1_l, 65536.0);
  }

  rtb_DataTypeConversion6 = Sum1_l < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-Sum1_l
    : (uint16_T)Sum1_l;

  /* End of DataTypeConversion: '<S13>/Data Type Conversion6' */

  /* S-Function (arduinoserialwrite_sfcn): '<S13>/Serial Transmit' incorporates:
   *  Constant: '<S13>/Constant'
   *  DataTypeConversion: '<S47>/Extract Desired Bits'
   *  DataTypeConversion: '<S48>/Extract Desired Bits'
   *  DataTypeConversion: '<S55>/Extract Desired Bits'
   *  DataTypeConversion: '<S56>/Extract Desired Bits'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtSerial TransmitInport1'
   */
  tmp[0] = LabC_CompensatorOverRobot_P.Constant_Value;
  tmp[1] = ExtractDesiredBits_n;
  tmp[2] = ExtractDesiredBits;
  tmp[3] = ExtractDesiredBits_jl;
  tmp[4] = ExtractDesiredBits_k;
  tmp[5] = rtb_ExtractDesiredBits_g;
  tmp[6] = rtb_ExtractDesiredBits;
  tmp[7] = rtb_ExtractDesiredBits_p;
  tmp[8] = rtb_ExtractDesiredBits_h;
  tmp[9] = (uint8_T)(rtb_DataTypeConversion4 >> 8);
  tmp[10] = (uint8_T)rtb_DataTypeConversion4;
  tmp[11] = ExtractDesiredBits_ki;
  tmp[12] = ExtractDesiredBits_j;
  tmp[13] = (uint8_T)(rtb_DataTypeConversion6 >> 8);
  tmp[14] = (uint8_T)rtb_DataTypeConversion6;
  Serial_write(LabC_CompensatorOverRobot_P.SerialTransmit_portNumber, tmp, 15UL);

  /* Sum: '<S4>/Add' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/Gain2'
   *  Gain: '<S4>/Gain3'
   */
  for (rtb_Abs = 0; rtb_Abs < 3; rtb_Abs++) {
    LabC_CompensatorOverRobot_B.Add[rtb_Abs] =
      ((LabC_CompensatorOverRobot_P.Md1[rtb_Abs + 3] * rtb_Add1_idx_1 +
        LabC_CompensatorOverRobot_P.Md1[rtb_Abs] * rtb_Add1_idx_0) +
       LabC_CompensatorOverRobot_P.Md1[rtb_Abs + 6] * rtb_Add1_idx_2) +
      (((real_T)(LabC_CompensatorOverRobot_P.Md4[rtb_Abs] *
                 LabC_CompensatorOverRobot_DWork.DiscreteTimeIntegratorconvertfr)
        + LabC_CompensatorOverRobot_P.Md3[rtb_Abs] * converttometers) +
       LabC_CompensatorOverRobot_P.Md2[rtb_Abs] * rtb_controller);
  }

  /* End of Sum: '<S4>/Add' */

  /* Gain: '<S4>/Gain10' incorporates:
   *  SignalConversion: '<S4>/TmpSignal ConversionAtGain10Inport1'
   */
  Sum1_l = ((LabC_CompensatorOverRobot_P.Cd[0] * Sum1 +
             LabC_CompensatorOverRobot_P.Cd[1] * Sum2) +
            LabC_CompensatorOverRobot_P.Cd[2] * Sum3) +
    LabC_CompensatorOverRobot_P.Cd[3] * Sum4;

  /* Sum: '<S4>/Sum' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Gain: '<S4>/Gain10'
   */
  Sum2_p = converttometers - Sum1_l;
  Sum1_l = LabC_CompensatorOverRobot_DWork.DiscreteTimeIntegratorconvertfr -
    Sum1_l;

  /* Sum: '<S4>/Add3' incorporates:
   *  Gain: '<S4>/Gain8'
   *  Gain: '<S4>/Gain9'
   */
  for (rtb_Abs = 0; rtb_Abs < 4; rtb_Abs++) {
    rtb_Add2[rtb_Abs] = (LabC_CompensatorOverRobot_P.Ld[rtb_Abs + 4] * Sum1_l +
                         LabC_CompensatorOverRobot_P.Ld[rtb_Abs] * Sum2_p) +
      LabC_CompensatorOverRobot_P.Bd[rtb_Abs] * rtb_controller;
  }

  /* Gain: '<S4>/Gain7' incorporates:
   *  SignalConversion: '<S4>/TmpSignal ConversionAtGain10Inport1'
   *  Sum: '<S4>/Add3'
   */
  for (rtb_Abs = 0; rtb_Abs < 4; rtb_Abs++) {
    Sum1_l = LabC_CompensatorOverRobot_P.Ad[rtb_Abs + 12] * Sum4 +
      (LabC_CompensatorOverRobot_P.Ad[rtb_Abs + 8] * Sum3 +
       (LabC_CompensatorOverRobot_P.Ad[rtb_Abs + 4] * Sum2 +
        LabC_CompensatorOverRobot_P.Ad[rtb_Abs] * Sum1));
    tmp_0[rtb_Abs] = Sum1_l;
  }

  /* End of Gain: '<S4>/Gain7' */

  /* Sum: '<S4>/Add3' */
  LabC_CompensatorOverRobot_B.Add3[0] = rtb_Add2[0] + tmp_0[0];
  LabC_CompensatorOverRobot_B.Add3[1] = rtb_Add2[1] + tmp_0[1];
  LabC_CompensatorOverRobot_B.Add3[2] = rtb_Add2[2] + tmp_0[2];
  LabC_CompensatorOverRobot_B.Add3[3] = rtb_Add2[3] + tmp_0[3];

  /* S-Function (sf_MPU6050_Driver_GxAyz): '<S3>/Gyro and Accelerometer' */
  sf_MPU6050_Driver_GxAyz_Outputs_wrapper
    ( &LabC_CompensatorOverRobot_B.GyroandAccelerometer_o1,
     &LabC_CompensatorOverRobot_B.GyroandAccelerometer_o2,
     &LabC_CompensatorOverRobot_B.GyroandAccelerometer_o3,
     &LabC_CompensatorOverRobot_DWork.GyroandAccelerometer_DSTATE);

  /* Gain: '<S2>/convert to radians//sec' incorporates:
   *  Constant: '<S2>/gyro bias'
   *  DataTypeConversion: '<S3>/Data Type  Conversion1'
   *  Sum: '<S2>/Sum'
   */
  LabC_CompensatorOverRobot_B.converttoradianssec = ((real32_T)
    LabC_CompensatorOverRobot_B.GyroandAccelerometer_o1 -
    LabC_CompensatorOverRobot_P.fGyroBias) *
    LabC_CompensatorOverRobot_P.converttoradianssec_Gain;

  /* Gain: '<S57>/conversion to duty cycle (convert to int)' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Fcn: '<S1>/turn off the motor if the measured angle is greater than X degrees'
   *  Product: '<S1>/Product1'
   *  Sum: '<S1>/Sum1'
   */
  Sum1_l = floor((rtb_Gain3 + rtb_controller) * (real_T)((real32_T)fabs
    (LabC_CompensatorOverRobot_DWork.DiscreteTimeIntegratorconvertfr) < 0.75F) *
                 LabC_CompensatorOverRobot_P.conversiontodutycycleconverttoi);
  if (rtIsNaN(Sum1_l) || rtIsInf(Sum1_l)) {
    Sum1_l = 0.0;
  } else {
    Sum1_l = fmod(Sum1_l, 65536.0);
  }

  rtb_Abs = Sum1_l < 0.0 ? -(int16_T)(uint16_T)-Sum1_l : (int16_T)(uint16_T)
    Sum1_l;

  /* End of Gain: '<S57>/conversion to duty cycle (convert to int)' */

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S57>/Constant2'
   */
  if (rtb_Abs >= LabC_CompensatorOverRobot_P.Switch_Threshold) {
    Sum1 = LabC_CompensatorOverRobot_P.Constant2_Value;
  } else {
    Sum1 = LabC_CompensatorOverRobot_P.Constant1_Value;
  }

  /* End of Switch: '<S57>/Switch' */

  /* DataTypeConversion: '<S58>/Data Type Conversion' */
  if (Sum1 < 256.0) {
    if (Sum1 >= 0.0) {
      LabC_CompensatorOverRobot_B.DataTypeConversion = (uint8_T)Sum1;
    } else {
      LabC_CompensatorOverRobot_B.DataTypeConversion = 0U;
    }
  } else {
    LabC_CompensatorOverRobot_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S58>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S58>/Digital Output' */
  MW_digitalWrite(LabC_CompensatorOverRobot_P.DigitalOutput_pinNumber,
                  LabC_CompensatorOverRobot_B.DataTypeConversion);

  /* Abs: '<S57>/Abs' */
  if (rtb_Abs < 0) {
    rtb_Abs = -rtb_Abs;
  }

  /* End of Abs: '<S57>/Abs' */

  /* Sum: '<S57>/Add2' incorporates:
   *  Constant: '<S57>/Constant3'
   */
  Sum1_l = LabC_CompensatorOverRobot_P.Constant3_Value + (real_T)rtb_Abs;

  /* Saturate: '<S57>/Saturation 0 to 255' */
  if (Sum1_l > LabC_CompensatorOverRobot_P.Saturation0to255_UpperSat) {
    Sum1_l = LabC_CompensatorOverRobot_P.Saturation0to255_UpperSat;
  } else {
    if (Sum1_l < LabC_CompensatorOverRobot_P.Saturation0to255_LowerSat) {
      Sum1_l = LabC_CompensatorOverRobot_P.Saturation0to255_LowerSat;
    }
  }

  /* DataTypeConversion: '<S59>/Data Type Conversion' incorporates:
   *  Abs: '<S57>/Abs3'
   *  Gain: '<S57>/Gain1'
   *  Saturate: '<S57>/Saturation 0 to 255'
   *  Sum: '<S57>/Add1'
   */
  Sum1_l = fabs(LabC_CompensatorOverRobot_P.Gain1_Gain * Sum1 - Sum1_l);
  if (Sum1_l < 256.0) {
    LabC_CompensatorOverRobot_B.DataTypeConversion_b = (uint8_T)Sum1_l;
  } else {
    LabC_CompensatorOverRobot_B.DataTypeConversion_b = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S59>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S59>/PWM' */
  MW_analogWrite(LabC_CompensatorOverRobot_P.PWM_pinNumber,
                 LabC_CompensatorOverRobot_B.DataTypeConversion_b);
}

/* Model update function */
void LabC_CompensatorOverRobot_update(void)
{
  /* S-Function "sf_QuadEncoder_18_19_15_62_wrapper" Block: <S3>/Encoder  */
  sf_QuadEncoder_18_19_15_62_Update_wrapper
    ( &LabC_CompensatorOverRobot_B.Encoder_o1,
     &LabC_CompensatorOverRobot_B.Encoder_o2,
     &LabC_CompensatorOverRobot_DWork.Encoder_DSTATE,
     LabC_CompensatorOverRobot_P.Encoder_P1, 2,
     LabC_CompensatorOverRobot_P.Encoder_P2, 2,
     LabC_CompensatorOverRobot_P.Encoder_P3, 2);

  /* Update for UnitDelay: '<S9>/UD' */
  LabC_CompensatorOverRobot_DWork.UD_DSTATE = LabC_CompensatorOverRobot_B.TSamp;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  LabC_CompensatorOverRobot_DWork.DiscreteTimeIntegratorconvertfr +=
    LabC_CompensatorOverRobot_P.DiscreteTimeIntegratorconvertfr *
    LabC_CompensatorOverRobot_B.converttoradianssec;

  /* Update for UnitDelay: '<S10>/UD' */
  LabC_CompensatorOverRobot_DWork.UD_DSTATE_o =
    LabC_CompensatorOverRobot_B.TSamp_n;

  /* Update for DiscreteStateSpace: '<S11>/Internal_1_1' */
  {
    LabC_CompensatorOverRobot_DWork.Internal_1_1_DSTATE =
      LabC_CompensatorOverRobot_B.Add3[0] +
      (LabC_CompensatorOverRobot_P.Internal_1_1_A)*
      LabC_CompensatorOverRobot_DWork.Internal_1_1_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S11>/Internal_2_2' */
  {
    LabC_CompensatorOverRobot_DWork.Internal_2_2_DSTATE =
      LabC_CompensatorOverRobot_B.Add3[1] +
      (LabC_CompensatorOverRobot_P.Internal_2_2_A)*
      LabC_CompensatorOverRobot_DWork.Internal_2_2_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S11>/Internal_3_3' */
  {
    LabC_CompensatorOverRobot_DWork.Internal_3_3_DSTATE =
      LabC_CompensatorOverRobot_B.Add3[2] +
      (LabC_CompensatorOverRobot_P.Internal_3_3_A)*
      LabC_CompensatorOverRobot_DWork.Internal_3_3_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S11>/Internal_4_4' */
  {
    LabC_CompensatorOverRobot_DWork.Internal_4_4_DSTATE =
      LabC_CompensatorOverRobot_B.Add3[3] +
      (LabC_CompensatorOverRobot_P.Internal_4_4_A)*
      LabC_CompensatorOverRobot_DWork.Internal_4_4_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S12>/Internal_1_1' */
  {
    LabC_CompensatorOverRobot_DWork.Internal_1_1_DSTATE_m =
      LabC_CompensatorOverRobot_B.Add[0] +
      (LabC_CompensatorOverRobot_P.Internal_1_1_A_m)*
      LabC_CompensatorOverRobot_DWork.Internal_1_1_DSTATE_m;
  }

  /* Update for DiscreteStateSpace: '<S12>/Internal_2_2' */
  {
    LabC_CompensatorOverRobot_DWork.Internal_2_2_DSTATE_p =
      LabC_CompensatorOverRobot_B.Add[1] +
      (LabC_CompensatorOverRobot_P.Internal_2_2_A_o)*
      LabC_CompensatorOverRobot_DWork.Internal_2_2_DSTATE_p;
  }

  /* Update for DiscreteStateSpace: '<S12>/Internal_3_3' */
  {
    LabC_CompensatorOverRobot_DWork.Internal_3_3_DSTATE_o =
      LabC_CompensatorOverRobot_B.Add[2] +
      (LabC_CompensatorOverRobot_P.Internal_3_3_A_a)*
      LabC_CompensatorOverRobot_DWork.Internal_3_3_DSTATE_o;
  }

  /* S-Function "sf_MPU6050_Driver_GxAyz_wrapper" Block: <S3>/Gyro and Accelerometer */
  sf_MPU6050_Driver_GxAyz_Update_wrapper
    ( &LabC_CompensatorOverRobot_B.GyroandAccelerometer_o1,
     &LabC_CompensatorOverRobot_B.GyroandAccelerometer_o2,
     &LabC_CompensatorOverRobot_B.GyroandAccelerometer_o3,
     &LabC_CompensatorOverRobot_DWork.GyroandAccelerometer_DSTATE);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  LabC_CompensatorOverRobot_M->Timing.t[0] =
    (++LabC_CompensatorOverRobot_M->Timing.clockTick0) *
    LabC_CompensatorOverRobot_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    LabC_CompensatorOverRobot_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void LabC_CompensatorOverRobot_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)LabC_CompensatorOverRobot_M, 0,
                sizeof(RT_MODEL_LabC_CompensatorOverRo));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LabC_CompensatorOverRobot_M->solverInfo,
                          &LabC_CompensatorOverRobot_M->Timing.simTimeStep);
    rtsiSetTPtr(&LabC_CompensatorOverRobot_M->solverInfo, &rtmGetTPtr
                (LabC_CompensatorOverRobot_M));
    rtsiSetStepSizePtr(&LabC_CompensatorOverRobot_M->solverInfo,
                       &LabC_CompensatorOverRobot_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&LabC_CompensatorOverRobot_M->solverInfo, ((const
      char_T **)(&rtmGetErrorStatus(LabC_CompensatorOverRobot_M))));
    rtsiSetRTModelPtr(&LabC_CompensatorOverRobot_M->solverInfo,
                      LabC_CompensatorOverRobot_M);
  }

  rtsiSetSimTimeStep(&LabC_CompensatorOverRobot_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&LabC_CompensatorOverRobot_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(LabC_CompensatorOverRobot_M,
             &LabC_CompensatorOverRobot_M->Timing.tArray[0]);
  LabC_CompensatorOverRobot_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &LabC_CompensatorOverRobot_B), 0,
                sizeof(BlockIO_LabC_CompensatorOverRob));

  /* states (dwork) */
  (void) memset((void *)&LabC_CompensatorOverRobot_DWork, 0,
                sizeof(D_Work_LabC_CompensatorOverRobo));

  /* Start for FromWorkspace: '<S8>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 60.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0 } ;

    LabC_CompensatorOverRobot_DWork.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    LabC_CompensatorOverRobot_DWork.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    LabC_CompensatorOverRobot_DWork.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S58>/Digital Output' */
  MW_pinModeOutput(LabC_CompensatorOverRobot_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S59>/PWM' */
  MW_pinModeOutput(LabC_CompensatorOverRobot_P.PWM_pinNumber);

  /* S-Function Block: <S3>/Encoder  */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        LabC_CompensatorOverRobot_DWork.Encoder_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for UnitDelay: '<S9>/UD' */
  LabC_CompensatorOverRobot_DWork.UD_DSTATE =
    LabC_CompensatorOverRobot_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  LabC_CompensatorOverRobot_DWork.DiscreteTimeIntegratorconvertfr =
    LabC_CompensatorOverRobot_P.DiscreteTimeIntegratorconvert_e;

  /* InitializeConditions for UnitDelay: '<S10>/UD' */
  LabC_CompensatorOverRobot_DWork.UD_DSTATE_o =
    LabC_CompensatorOverRobot_P.DiscreteDerivative_ICPrevScal_n;

  /* InitializeConditions for DiscreteStateSpace: '<S11>/Internal_1_1' */
  LabC_CompensatorOverRobot_DWork.Internal_1_1_DSTATE =
    LabC_CompensatorOverRobot_P.Internal_1_1_X0;

  /* InitializeConditions for DiscreteStateSpace: '<S11>/Internal_2_2' */
  LabC_CompensatorOverRobot_DWork.Internal_2_2_DSTATE =
    LabC_CompensatorOverRobot_P.Internal_2_2_X0;

  /* InitializeConditions for DiscreteStateSpace: '<S11>/Internal_3_3' */
  LabC_CompensatorOverRobot_DWork.Internal_3_3_DSTATE =
    LabC_CompensatorOverRobot_P.Internal_3_3_X0;

  /* InitializeConditions for DiscreteStateSpace: '<S11>/Internal_4_4' */
  LabC_CompensatorOverRobot_DWork.Internal_4_4_DSTATE =
    LabC_CompensatorOverRobot_P.Internal_4_4_X0;

  /* InitializeConditions for DiscreteStateSpace: '<S12>/Internal_1_1' */
  LabC_CompensatorOverRobot_DWork.Internal_1_1_DSTATE_m =
    LabC_CompensatorOverRobot_P.Internal_1_1_X0_m;

  /* InitializeConditions for DiscreteStateSpace: '<S12>/Internal_2_2' */
  LabC_CompensatorOverRobot_DWork.Internal_2_2_DSTATE_p =
    LabC_CompensatorOverRobot_P.Internal_2_2_X0_h;

  /* InitializeConditions for DiscreteStateSpace: '<S12>/Internal_3_3' */
  LabC_CompensatorOverRobot_DWork.Internal_3_3_DSTATE_o =
    LabC_CompensatorOverRobot_P.Internal_3_3_X0_p;

  /* S-Function Block: <S3>/Gyro and Accelerometer */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        LabC_CompensatorOverRobot_DWork.GyroandAccelerometer_DSTATE =
          initVector[0];
      }
    }
  }
}

/* Model terminate function */
void LabC_CompensatorOverRobot_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
