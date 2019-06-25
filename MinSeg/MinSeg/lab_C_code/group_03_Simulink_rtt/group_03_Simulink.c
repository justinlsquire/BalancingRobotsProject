/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: group_03_Simulink.c
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

/* Block signals (auto storage) */
BlockIO_group_03_Simulink group_03_Simulink_B;

/* Block states (auto storage) */
D_Work_group_03_Simulink group_03_Simulink_DWork;

/* Real-time model */
RT_MODEL_group_03_Simulink group_03_Simulink_M_;
RT_MODEL_group_03_Simulink *const group_03_Simulink_M = &group_03_Simulink_M_;

/* Model output function */
void group_03_Simulink_output(void)
{
  /* local block i/o variables */
  real_T rtb_Add2_d;
  real_T rtb_Fcn6;
  real_T rtb_Internal_4_4;
  real_T rtb_Internal_3_3;
  real_T rtb_Internal_3_2;
  real_T rtb_Fcn4;
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
  real_T rtb_Gain8_idx_1;
  real_T rtb_Gain8_idx_3;
  real_T rtb_Add1_idx_0;
  real_T rtb_Add1_idx_1;
  real_T rtb_Add1_idx_2;
  real32_T tmp_1;

  /* FromWorkspace: '<S4>/FromWs' */
  {
    real_T *pDataValues = (real_T *)
      group_03_Simulink_DWork.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      group_03_Simulink_DWork.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = group_03_Simulink_DWork.FromWs_IWORK.PrevIndex;
    real_T t = group_03_Simulink_M->Timing.t[0];
    if (t >= pTimeValues[5]) {
      rtb_Fcn6 = pDataValues[5];
    } else {
      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[5]) {
        currTimeIndex = 4;
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

      group_03_Simulink_DWork.FromWs_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_Fcn6 = pDataValues[currTimeIndex];
          } else {
            rtb_Fcn6 = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex= currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_Fcn6 = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 6;
        }
      }
    }
  }

  /* FromWorkspace: '<S6>/FromWs' */
  {
    real_T *pDataValues = (real_T *)
      group_03_Simulink_DWork.FromWs_PWORK_d.DataPtr;
    real_T *pTimeValues = (real_T *)
      group_03_Simulink_DWork.FromWs_PWORK_d.TimePtr;
    int_T currTimeIndex = group_03_Simulink_DWork.FromWs_IWORK_f.PrevIndex;
    real_T t = group_03_Simulink_M->Timing.t[0];
    if (t >= pTimeValues[5]) {
      rtb_Add2_d = pDataValues[5];
    } else {
      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[5]) {
        currTimeIndex = 4;
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

      group_03_Simulink_DWork.FromWs_IWORK_f.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_Add2_d = pDataValues[currTimeIndex];
          } else {
            rtb_Add2_d = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex= currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_Add2_d = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 6;
        }
      }
    }
  }

  /* ManualSwitch: '<S1>/SELECT MAX or TRIAL' */
  if (group_03_Simulink_P.SELECTMAXorTRIAL_CurrentSetting != 1) {
    rtb_Fcn6 = rtb_Add2_d;
  }

  /* End of ManualSwitch: '<S1>/SELECT MAX or TRIAL' */

  /* S-Function (sf_QuadEncoder_18_19_15_62): '<S3>/Encoder ' */
  sf_QuadEncoder_18_19_15_62_Outputs_wrapper( &group_03_Simulink_B.Encoder_o1,
    &group_03_Simulink_B.Encoder_o2, &group_03_Simulink_DWork.Encoder_DSTATE,
    group_03_Simulink_P.Encoder_P1, 2, group_03_Simulink_P.Encoder_P2, 2,
    group_03_Simulink_P.Encoder_P3, 2);

  /* Gain: '<S2>/convert to meters' incorporates:
   *  DataTypeConversion: '<S3>/Data Type  Conversion2'
   *  Gain: '<S2>/convert to  radians'
   */
  converttometers = group_03_Simulink_P.converttoradians_Gain * (real32_T)
    group_03_Simulink_B.Encoder_o1 * group_03_Simulink_P.fWheelRadius;

  /* SampleTimeMath: '<S7>/TSamp'
   *
   * About '<S7>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  group_03_Simulink_B.TSamp = converttometers * group_03_Simulink_P.TSamp_WtEt;

  /* SampleTimeMath: '<S8>/TSamp' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *
   * About '<S8>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  group_03_Simulink_B.TSamp_n =
    group_03_Simulink_DWork.DiscreteTimeIntegratorconvertfr *
    group_03_Simulink_P.TSamp_WtEt_m;

  /* DiscreteStateSpace: '<S9>/Internal_1_1' */
  {
    rtb_Internal_4_4 = group_03_Simulink_P.Internal_1_1_C*
      group_03_Simulink_DWork.Internal_1_1_DSTATE;
  }

  /* DiscreteStateSpace: '<S9>/Internal_1_2' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_1_3' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_1_4' */
  {
    rtb_Fcn4 = 0.0;
  }

  /* Sum: '<S9>/Sum1' */
  Sum1 = ((rtb_Internal_4_4 + rtb_Internal_3_3) + rtb_Internal_3_2) + rtb_Fcn4;

  /* DiscreteStateSpace: '<S9>/Internal_2_1' */
  {
    rtb_Fcn4 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_2_2' */
  {
    rtb_Internal_3_2 = group_03_Simulink_P.Internal_2_2_C*
      group_03_Simulink_DWork.Internal_2_2_DSTATE;
  }

  /* DiscreteStateSpace: '<S9>/Internal_2_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_2_4' */
  {
    rtb_Internal_4_4 = 0.0;
  }

  /* Sum: '<S9>/Sum2' */
  Sum2 = ((rtb_Fcn4 + rtb_Internal_3_2) + rtb_Internal_3_3) + rtb_Internal_4_4;

  /* DiscreteStateSpace: '<S9>/Internal_3_1' */
  {
    rtb_Fcn4 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_3_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_3_3' */
  {
    rtb_Internal_3_3 = group_03_Simulink_P.Internal_3_3_C*
      group_03_Simulink_DWork.Internal_3_3_DSTATE;
  }

  /* DiscreteStateSpace: '<S9>/Internal_3_4' */
  {
    rtb_Internal_4_4 = 0.0;
  }

  /* Sum: '<S9>/Sum3' */
  Sum3 = ((rtb_Fcn4 + rtb_Internal_3_2) + rtb_Internal_3_3) + rtb_Internal_4_4;

  /* DiscreteStateSpace: '<S9>/Internal_4_1' */
  {
    rtb_Fcn4 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_4_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_4_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_4_4' */
  {
    rtb_Internal_4_4 = group_03_Simulink_P.Internal_4_4_C*
      group_03_Simulink_DWork.Internal_4_4_DSTATE;
  }

  /* Sum: '<S9>/Sum4' */
  Sum4 = ((rtb_Fcn4 + rtb_Internal_3_2) + rtb_Internal_3_3) + rtb_Internal_4_4;

  /* DiscreteStateSpace: '<S10>/Internal_1_1' */
  {
    rtb_Fcn4 = group_03_Simulink_P.Internal_1_1_C_h*
      group_03_Simulink_DWork.Internal_1_1_DSTATE_m;
  }

  /* DiscreteStateSpace: '<S10>/Internal_1_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S10>/Internal_1_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* Sum: '<S10>/Sum1' */
  Sum1_l = (rtb_Fcn4 + rtb_Internal_3_2) + rtb_Internal_3_3;

  /* DiscreteStateSpace: '<S10>/Internal_2_1' */
  {
    rtb_Fcn4 = 0.0;
  }

  /* DiscreteStateSpace: '<S10>/Internal_2_2' */
  {
    rtb_Internal_3_2 = group_03_Simulink_P.Internal_2_2_C_p*
      group_03_Simulink_DWork.Internal_2_2_DSTATE_p;
  }

  /* DiscreteStateSpace: '<S10>/Internal_2_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* Sum: '<S10>/Sum2' */
  Sum2_p = (rtb_Fcn4 + rtb_Internal_3_2) + rtb_Internal_3_3;

  /* DiscreteStateSpace: '<S10>/Internal_3_1' */
  {
    rtb_Fcn4 = 0.0;
  }

  /* DiscreteStateSpace: '<S10>/Internal_3_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S10>/Internal_3_3' */
  {
    rtb_Internal_3_3 = group_03_Simulink_P.Internal_3_3_C_h*
      group_03_Simulink_DWork.Internal_3_3_DSTATE_o;
  }

  /* Sum: '<S5>/Add1' incorporates:
   *  Gain: '<S5>/Gain4'
   *  Sum: '<S10>/Sum3'
   */
  rtb_Add1_idx_0 = group_03_Simulink_P.Md5[0] * converttometers + Sum1_l;
  rtb_Add1_idx_1 = group_03_Simulink_P.Md5[1] * converttometers + Sum2_p;
  rtb_Add1_idx_2 = ((rtb_Fcn4 + rtb_Internal_3_2) + rtb_Internal_3_3) +
    group_03_Simulink_P.Md5[2] * converttometers;

  /* Sum: '<S5>/Add2' incorporates:
   *  Gain: '<S5>/Gain5'
   *  Gain: '<S5>/Gain6'
   */
  for (rtb_Abs = 0; rtb_Abs < 4; rtb_Abs++) {
    rtb_Add2[rtb_Abs] = ((group_03_Simulink_P.Md7[rtb_Abs + 4] * rtb_Add1_idx_1
                          + group_03_Simulink_P.Md7[rtb_Abs] * rtb_Add1_idx_0) +
                         group_03_Simulink_P.Md7[rtb_Abs + 8] * rtb_Add1_idx_2)
      + group_03_Simulink_P.Md6[rtb_Abs] * converttometers;
  }

  /* End of Sum: '<S5>/Add2' */

  /* ManualSwitch: '<S5>/Manual Switch1' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  ManualSwitch: '<S5>/Manual Switch'
   *  Sum: '<S7>/Diff'
   *  Sum: '<S8>/Diff'
   *  UnitDelay: '<S7>/UD'
   *  UnitDelay: '<S8>/UD'
   */
  if (group_03_Simulink_P.ManualSwitch1_CurrentSetting == 1) {
    Sum1_l = converttometers;
    rtb_Gain8_idx_1 = group_03_Simulink_B.TSamp -
      group_03_Simulink_DWork.UD_DSTATE;
    Sum2_p = group_03_Simulink_DWork.DiscreteTimeIntegratorconvertfr;
    rtb_Gain8_idx_3 = group_03_Simulink_B.TSamp_n -
      group_03_Simulink_DWork.UD_DSTATE_o;
  } else if (group_03_Simulink_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<S5>/Manual Switch' */
    Sum1_l = Sum1;
    rtb_Gain8_idx_1 = Sum2;
    Sum2_p = Sum3;
    rtb_Gain8_idx_3 = Sum4;
  } else {
    Sum1_l = rtb_Add2[0];
    rtb_Gain8_idx_1 = rtb_Add2[1];
    Sum2_p = rtb_Add2[2];
    rtb_Gain8_idx_3 = rtb_Add2[3];
  }

  /* End of ManualSwitch: '<S5>/Manual Switch1' */

  /* Gain: '<S1>/controller' incorporates:
   *  Gain: '<S1>/Gain2'
   *  Sum: '<S1>/Sum'
   */
  rtb_Add2_d = (((-group_03_Simulink_P.Nxd[0] * rtb_Fcn6 + Sum1_l) *
                 -group_03_Simulink_P.Kd[0] + (-group_03_Simulink_P.Nxd[1] *
    rtb_Fcn6 + rtb_Gain8_idx_1) * -group_03_Simulink_P.Kd[1]) +
                (-group_03_Simulink_P.Nxd[2] * rtb_Fcn6 + Sum2_p) *
                -group_03_Simulink_P.Kd[2]) + (-group_03_Simulink_P.Nxd[3] *
    rtb_Fcn6 + rtb_Gain8_idx_3) * -group_03_Simulink_P.Kd[3];

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/Gain3'
   */
  rtb_Fcn6 = group_03_Simulink_P.Nud * rtb_Fcn6 + rtb_Add2_d;

  /* Product: '<S1>/Product1' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Fcn: '<S1>/turn off the motor if the measured angle is greater than X degrees'
   */
  Sum2_p = (real_T)((real32_T)fabs
                    (group_03_Simulink_DWork.DiscreteTimeIntegratorconvertfr) <
                    0.75F) * rtb_Fcn6;

  /* Fcn: '<S11>/Fcn' */
  rtb_Fcn6 = (rtb_Add2_d + 10.0) * 3276.8;

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  Sum1_l = floor(rtb_Fcn6);
  if (rtIsNaN(Sum1_l) || rtIsInf(Sum1_l)) {
    Sum1_l = 0.0;
  } else {
    Sum1_l = fmod(Sum1_l, 65536.0);
  }

  rtb_DataTypeConversion6 = Sum1_l < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-Sum1_l
    : (uint16_T)Sum1_l;

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* DataTypeConversion: '<S41>/Extract Desired Bits' */
  ExtractDesiredBits_n = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S42>/Extract Desired Bits' */
  ExtractDesiredBits = (uint8_T)rtb_DataTypeConversion6;

  /* DataTypeConversion: '<S11>/Data Type Conversion1' incorporates:
   *  Fcn: '<S11>/Fcn1'
   */
  tmp_1 = (real32_T)floor((converttometers + 10.0F) * 3276.8F);
  if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
    tmp_1 = 0.0F;
  } else {
    tmp_1 = (real32_T)fmod(tmp_1, 65536.0F);
  }

  rtb_DataTypeConversion6 = tmp_1 < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-tmp_1 :
    (uint16_T)tmp_1;

  /* End of DataTypeConversion: '<S11>/Data Type Conversion1' */

  /* DataTypeConversion: '<S47>/Extract Desired Bits' */
  ExtractDesiredBits_jl = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S48>/Extract Desired Bits' */
  ExtractDesiredBits_k = (uint8_T)rtb_DataTypeConversion6;

  /* DataTypeConversion: '<S11>/Data Type Conversion2' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Fcn: '<S11>/Fcn2'
   */
  tmp_1 = (real32_T)floor
    ((group_03_Simulink_DWork.DiscreteTimeIntegratorconvertfr + 10.0F) * 3276.8F);
  if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
    tmp_1 = 0.0F;
  } else {
    tmp_1 = (real32_T)fmod(tmp_1, 65536.0F);
  }

  rtb_DataTypeConversion4 = tmp_1 < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-tmp_1 :
    (uint16_T)tmp_1;

  /* End of DataTypeConversion: '<S11>/Data Type Conversion2' */

  /* DataTypeConversion: '<S49>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_g = (uint8_T)(rtb_DataTypeConversion4 >> 8);

  /* DataTypeConversion: '<S50>/Extract Desired Bits' */
  rtb_ExtractDesiredBits = (uint8_T)rtb_DataTypeConversion4;

  /* Fcn: '<S11>/Fcn3' */
  rtb_Fcn4 = (Sum1 + 10.0) * 3276.8;

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  Sum1_l = floor(rtb_Fcn4);
  if (rtIsNaN(Sum1_l) || rtIsInf(Sum1_l)) {
    Sum1_l = 0.0;
  } else {
    Sum1_l = fmod(Sum1_l, 65536.0);
  }

  rtb_DataTypeConversion4 = Sum1_l < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-Sum1_l
    : (uint16_T)Sum1_l;

  /* End of DataTypeConversion: '<S11>/Data Type Conversion3' */

  /* DataTypeConversion: '<S51>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_p = (uint8_T)(rtb_DataTypeConversion4 >> 8);

  /* DataTypeConversion: '<S52>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_h = (uint8_T)rtb_DataTypeConversion4;

  /* Fcn: '<S11>/Fcn4' */
  rtb_Fcn4 = (Sum3 + 10.0) * 3276.8;

  /* DataTypeConversion: '<S11>/Data Type Conversion4' */
  Sum1_l = floor(rtb_Fcn4);
  if (rtIsNaN(Sum1_l) || rtIsInf(Sum1_l)) {
    Sum1_l = 0.0;
  } else {
    Sum1_l = fmod(Sum1_l, 65536.0);
  }

  rtb_DataTypeConversion4 = Sum1_l < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-Sum1_l
    : (uint16_T)Sum1_l;

  /* End of DataTypeConversion: '<S11>/Data Type Conversion4' */

  /* Fcn: '<S11>/Fcn5' */
  rtb_Fcn6 = (rtb_Add2[0] + 10.0) * 3276.8;

  /* DataTypeConversion: '<S11>/Data Type Conversion5' */
  Sum1_l = floor(rtb_Fcn6);
  if (rtIsNaN(Sum1_l) || rtIsInf(Sum1_l)) {
    Sum1_l = 0.0;
  } else {
    Sum1_l = fmod(Sum1_l, 65536.0);
  }

  rtb_DataTypeConversion6 = Sum1_l < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-Sum1_l
    : (uint16_T)Sum1_l;

  /* End of DataTypeConversion: '<S11>/Data Type Conversion5' */

  /* DataTypeConversion: '<S43>/Extract Desired Bits' */
  ExtractDesiredBits_ki = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S44>/Extract Desired Bits' */
  ExtractDesiredBits_j = (uint8_T)rtb_DataTypeConversion6;

  /* Fcn: '<S11>/Fcn6' */
  rtb_Fcn6 = (rtb_Add2[2] + 10.0) * 3276.8;

  /* DataTypeConversion: '<S11>/Data Type Conversion6' */
  Sum1_l = floor(rtb_Fcn6);
  if (rtIsNaN(Sum1_l) || rtIsInf(Sum1_l)) {
    Sum1_l = 0.0;
  } else {
    Sum1_l = fmod(Sum1_l, 65536.0);
  }

  rtb_DataTypeConversion6 = Sum1_l < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-Sum1_l
    : (uint16_T)Sum1_l;

  /* End of DataTypeConversion: '<S11>/Data Type Conversion6' */

  /* S-Function (arduinoserialwrite_sfcn): '<S11>/Serial Transmit' incorporates:
   *  Constant: '<S11>/Constant'
   *  DataTypeConversion: '<S45>/Extract Desired Bits'
   *  DataTypeConversion: '<S46>/Extract Desired Bits'
   *  DataTypeConversion: '<S53>/Extract Desired Bits'
   *  DataTypeConversion: '<S54>/Extract Desired Bits'
   *  SignalConversion: '<S11>/TmpSignal ConversionAtSerial TransmitInport1'
   */
  tmp[0] = group_03_Simulink_P.Constant_Value;
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
  Serial_write(group_03_Simulink_P.SerialTransmit_portNumber, tmp, 15UL);

  /* Sum: '<S5>/Add' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  Gain: '<S5>/Gain2'
   *  Gain: '<S5>/Gain3'
   */
  for (rtb_Abs = 0; rtb_Abs < 3; rtb_Abs++) {
    group_03_Simulink_B.Add[rtb_Abs] = ((group_03_Simulink_P.Md1[rtb_Abs + 3] *
      rtb_Add1_idx_1 + group_03_Simulink_P.Md1[rtb_Abs] * rtb_Add1_idx_0) +
      group_03_Simulink_P.Md1[rtb_Abs + 6] * rtb_Add1_idx_2) + (((real_T)
      (group_03_Simulink_P.Md4[rtb_Abs] *
       group_03_Simulink_DWork.DiscreteTimeIntegratorconvertfr) +
      group_03_Simulink_P.Md3[rtb_Abs] * converttometers) +
      group_03_Simulink_P.Md2[rtb_Abs] * rtb_Add2_d);
  }

  /* End of Sum: '<S5>/Add' */

  /* Gain: '<S5>/Gain10' incorporates:
   *  SignalConversion: '<S5>/TmpSignal ConversionAtGain10Inport1'
   */
  Sum1_l = ((group_03_Simulink_P.Cd[0] * Sum1 + group_03_Simulink_P.Cd[1] * Sum2)
            + group_03_Simulink_P.Cd[2] * Sum3) + group_03_Simulink_P.Cd[3] *
    Sum4;

  /* Sum: '<S5>/Sum' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Gain: '<S5>/Gain10'
   */
  rtb_Gain8_idx_1 = converttometers - Sum1_l;
  Sum1_l = group_03_Simulink_DWork.DiscreteTimeIntegratorconvertfr - Sum1_l;

  /* Sum: '<S5>/Add3' incorporates:
   *  Gain: '<S5>/Gain8'
   *  Gain: '<S5>/Gain9'
   */
  for (rtb_Abs = 0; rtb_Abs < 4; rtb_Abs++) {
    rtb_Add2[rtb_Abs] = (group_03_Simulink_P.Ld[rtb_Abs + 4] * Sum1_l +
                         group_03_Simulink_P.Ld[rtb_Abs] * rtb_Gain8_idx_1) +
      group_03_Simulink_P.Bd[rtb_Abs] * rtb_Add2_d;
  }

  /* Gain: '<S5>/Gain7' incorporates:
   *  SignalConversion: '<S5>/TmpSignal ConversionAtGain10Inport1'
   *  Sum: '<S5>/Add3'
   */
  for (rtb_Abs = 0; rtb_Abs < 4; rtb_Abs++) {
    Sum1_l = group_03_Simulink_P.Ad[rtb_Abs + 12] * Sum4 +
      (group_03_Simulink_P.Ad[rtb_Abs + 8] * Sum3 +
       (group_03_Simulink_P.Ad[rtb_Abs + 4] * Sum2 +
        group_03_Simulink_P.Ad[rtb_Abs] * Sum1));
    tmp_0[rtb_Abs] = Sum1_l;
  }

  /* End of Gain: '<S5>/Gain7' */

  /* Sum: '<S5>/Add3' */
  group_03_Simulink_B.Add3[0] = rtb_Add2[0] + tmp_0[0];
  group_03_Simulink_B.Add3[1] = rtb_Add2[1] + tmp_0[1];
  group_03_Simulink_B.Add3[2] = rtb_Add2[2] + tmp_0[2];
  group_03_Simulink_B.Add3[3] = rtb_Add2[3] + tmp_0[3];

  /* S-Function (sf_MPU6050_Driver_GxAyz): '<S3>/Gyro and Accelerometer' */
  sf_MPU6050_Driver_GxAyz_Outputs_wrapper
    ( &group_03_Simulink_B.GyroandAccelerometer_o1,
     &group_03_Simulink_B.GyroandAccelerometer_o2,
     &group_03_Simulink_B.GyroandAccelerometer_o3,
     &group_03_Simulink_DWork.GyroandAccelerometer_DSTATE);

  /* Gain: '<S2>/convert to radians//sec' incorporates:
   *  Constant: '<S2>/gyro bias'
   *  DataTypeConversion: '<S3>/Data Type  Conversion1'
   *  Sum: '<S2>/Sum'
   */
  group_03_Simulink_B.converttoradianssec = ((real32_T)
    group_03_Simulink_B.GyroandAccelerometer_o1 - group_03_Simulink_P.fGyroBias)
    * group_03_Simulink_P.converttoradianssec_Gain;

  /* Gain: '<S55>/conversion to duty cycle (convert to int)' */
  Sum1_l = floor(group_03_Simulink_P.conversiontodutycycleconverttoi * Sum2_p);
  if (rtIsNaN(Sum1_l) || rtIsInf(Sum1_l)) {
    Sum1_l = 0.0;
  } else {
    Sum1_l = fmod(Sum1_l, 65536.0);
  }

  rtb_Abs = Sum1_l < 0.0 ? -(int16_T)(uint16_T)-Sum1_l : (int16_T)(uint16_T)
    Sum1_l;

  /* End of Gain: '<S55>/conversion to duty cycle (convert to int)' */

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S55>/Constant1'
   *  Constant: '<S55>/Constant2'
   */
  if (rtb_Abs >= group_03_Simulink_P.Switch_Threshold) {
    Sum2_p = group_03_Simulink_P.Constant2_Value;
  } else {
    Sum2_p = group_03_Simulink_P.Constant1_Value;
  }

  /* End of Switch: '<S55>/Switch' */

  /* DataTypeConversion: '<S56>/Data Type Conversion' */
  if (Sum2_p < 256.0) {
    if (Sum2_p >= 0.0) {
      group_03_Simulink_B.DataTypeConversion = (uint8_T)Sum2_p;
    } else {
      group_03_Simulink_B.DataTypeConversion = 0U;
    }
  } else {
    group_03_Simulink_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S56>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S56>/Digital Output' */
  MW_digitalWrite(group_03_Simulink_P.DigitalOutput_pinNumber,
                  group_03_Simulink_B.DataTypeConversion);

  /* Abs: '<S55>/Abs' */
  if (rtb_Abs < 0) {
    rtb_Abs = -rtb_Abs;
  }

  /* End of Abs: '<S55>/Abs' */

  /* Sum: '<S55>/Add2' incorporates:
   *  Constant: '<S55>/Constant3'
   */
  rtb_Add2_d = group_03_Simulink_P.Constant3_Value + (real_T)rtb_Abs;

  /* Saturate: '<S55>/Saturation 0 to 255' */
  if (rtb_Add2_d > group_03_Simulink_P.Saturation0to255_UpperSat) {
    Sum1_l = group_03_Simulink_P.Saturation0to255_UpperSat;
  } else if (rtb_Add2_d < group_03_Simulink_P.Saturation0to255_LowerSat) {
    Sum1_l = group_03_Simulink_P.Saturation0to255_LowerSat;
  } else {
    Sum1_l = rtb_Add2_d;
  }

  /* DataTypeConversion: '<S57>/Data Type Conversion' incorporates:
   *  Abs: '<S55>/Abs3'
   *  Gain: '<S55>/Gain1'
   *  Saturate: '<S55>/Saturation 0 to 255'
   *  Sum: '<S55>/Add1'
   */
  Sum1_l = fabs(group_03_Simulink_P.Gain1_Gain * Sum2_p - Sum1_l);
  if (Sum1_l < 256.0) {
    group_03_Simulink_B.DataTypeConversion_b = (uint8_T)Sum1_l;
  } else {
    group_03_Simulink_B.DataTypeConversion_b = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S57>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S57>/PWM' */
  MW_analogWrite(group_03_Simulink_P.PWM_pinNumber,
                 group_03_Simulink_B.DataTypeConversion_b);
}

/* Model update function */
void group_03_Simulink_update(void)
{
  /* S-Function "sf_QuadEncoder_18_19_15_62_wrapper" Block: <S3>/Encoder  */
  sf_QuadEncoder_18_19_15_62_Update_wrapper( &group_03_Simulink_B.Encoder_o1,
    &group_03_Simulink_B.Encoder_o2, &group_03_Simulink_DWork.Encoder_DSTATE,
    group_03_Simulink_P.Encoder_P1, 2, group_03_Simulink_P.Encoder_P2, 2,
    group_03_Simulink_P.Encoder_P3, 2);

  /* Update for UnitDelay: '<S7>/UD' */
  group_03_Simulink_DWork.UD_DSTATE = group_03_Simulink_B.TSamp;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  group_03_Simulink_DWork.DiscreteTimeIntegratorconvertfr +=
    group_03_Simulink_P.DiscreteTimeIntegratorconvertfr *
    group_03_Simulink_B.converttoradianssec;

  /* Update for UnitDelay: '<S8>/UD' */
  group_03_Simulink_DWork.UD_DSTATE_o = group_03_Simulink_B.TSamp_n;

  /* Update for DiscreteStateSpace: '<S9>/Internal_1_1' */
  {
    group_03_Simulink_DWork.Internal_1_1_DSTATE = group_03_Simulink_B.Add3[0] +
      (group_03_Simulink_P.Internal_1_1_A)*
      group_03_Simulink_DWork.Internal_1_1_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S9>/Internal_2_2' */
  {
    group_03_Simulink_DWork.Internal_2_2_DSTATE = group_03_Simulink_B.Add3[1] +
      (group_03_Simulink_P.Internal_2_2_A)*
      group_03_Simulink_DWork.Internal_2_2_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S9>/Internal_3_3' */
  {
    group_03_Simulink_DWork.Internal_3_3_DSTATE = group_03_Simulink_B.Add3[2] +
      (group_03_Simulink_P.Internal_3_3_A)*
      group_03_Simulink_DWork.Internal_3_3_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S9>/Internal_4_4' */
  {
    group_03_Simulink_DWork.Internal_4_4_DSTATE = group_03_Simulink_B.Add3[3] +
      (group_03_Simulink_P.Internal_4_4_A)*
      group_03_Simulink_DWork.Internal_4_4_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S10>/Internal_1_1' */
  {
    group_03_Simulink_DWork.Internal_1_1_DSTATE_m = group_03_Simulink_B.Add[0] +
      (group_03_Simulink_P.Internal_1_1_A_m)*
      group_03_Simulink_DWork.Internal_1_1_DSTATE_m;
  }

  /* Update for DiscreteStateSpace: '<S10>/Internal_2_2' */
  {
    group_03_Simulink_DWork.Internal_2_2_DSTATE_p = group_03_Simulink_B.Add[1] +
      (group_03_Simulink_P.Internal_2_2_A_o)*
      group_03_Simulink_DWork.Internal_2_2_DSTATE_p;
  }

  /* Update for DiscreteStateSpace: '<S10>/Internal_3_3' */
  {
    group_03_Simulink_DWork.Internal_3_3_DSTATE_o = group_03_Simulink_B.Add[2] +
      (group_03_Simulink_P.Internal_3_3_A_a)*
      group_03_Simulink_DWork.Internal_3_3_DSTATE_o;
  }

  /* S-Function "sf_MPU6050_Driver_GxAyz_wrapper" Block: <S3>/Gyro and Accelerometer */
  sf_MPU6050_Driver_GxAyz_Update_wrapper
    ( &group_03_Simulink_B.GyroandAccelerometer_o1,
     &group_03_Simulink_B.GyroandAccelerometer_o2,
     &group_03_Simulink_B.GyroandAccelerometer_o3,
     &group_03_Simulink_DWork.GyroandAccelerometer_DSTATE);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  group_03_Simulink_M->Timing.t[0] =
    (++group_03_Simulink_M->Timing.clockTick0) *
    group_03_Simulink_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    group_03_Simulink_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void group_03_Simulink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)group_03_Simulink_M, 0,
                sizeof(RT_MODEL_group_03_Simulink));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&group_03_Simulink_M->solverInfo,
                          &group_03_Simulink_M->Timing.simTimeStep);
    rtsiSetTPtr(&group_03_Simulink_M->solverInfo, &rtmGetTPtr
                (group_03_Simulink_M));
    rtsiSetStepSizePtr(&group_03_Simulink_M->solverInfo,
                       &group_03_Simulink_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&group_03_Simulink_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(group_03_Simulink_M))));
    rtsiSetRTModelPtr(&group_03_Simulink_M->solverInfo, group_03_Simulink_M);
  }

  rtsiSetSimTimeStep(&group_03_Simulink_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&group_03_Simulink_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(group_03_Simulink_M, &group_03_Simulink_M->Timing.tArray[0]);
  group_03_Simulink_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &group_03_Simulink_B), 0,
                sizeof(BlockIO_group_03_Simulink));

  /* states (dwork) */
  (void) memset((void *)&group_03_Simulink_DWork, 0,
                sizeof(D_Work_group_03_Simulink));

  /* Start for FromWorkspace: '<S4>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 10.0, 10.0, 20.0, 20.0, 30.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 1.6, 1.6, 1.6 } ;

    group_03_Simulink_DWork.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    group_03_Simulink_DWork.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    group_03_Simulink_DWork.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<S6>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 10.0, 10.0, 20.0, 20.0, 30.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.5, 0.5, 0.5 } ;

    group_03_Simulink_DWork.FromWs_PWORK_d.TimePtr = (void *) pTimeValues0;
    group_03_Simulink_DWork.FromWs_PWORK_d.DataPtr = (void *) pDataValues0;
    group_03_Simulink_DWork.FromWs_IWORK_f.PrevIndex = 0;
  }

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S56>/Digital Output' */
  MW_pinModeOutput(group_03_Simulink_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S57>/PWM' */
  MW_pinModeOutput(group_03_Simulink_P.PWM_pinNumber);

  /* S-Function Block: <S3>/Encoder  */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        group_03_Simulink_DWork.Encoder_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for UnitDelay: '<S7>/UD' */
  group_03_Simulink_DWork.UD_DSTATE =
    group_03_Simulink_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  group_03_Simulink_DWork.DiscreteTimeIntegratorconvertfr =
    group_03_Simulink_P.DiscreteTimeIntegratorconvert_e;

  /* InitializeConditions for UnitDelay: '<S8>/UD' */
  group_03_Simulink_DWork.UD_DSTATE_o =
    group_03_Simulink_P.DiscreteDerivative_ICPrevScal_n;

  /* InitializeConditions for DiscreteStateSpace: '<S9>/Internal_1_1' */
  group_03_Simulink_DWork.Internal_1_1_DSTATE =
    group_03_Simulink_P.Internal_1_1_X0;

  /* InitializeConditions for DiscreteStateSpace: '<S9>/Internal_2_2' */
  group_03_Simulink_DWork.Internal_2_2_DSTATE =
    group_03_Simulink_P.Internal_2_2_X0;

  /* InitializeConditions for DiscreteStateSpace: '<S9>/Internal_3_3' */
  group_03_Simulink_DWork.Internal_3_3_DSTATE =
    group_03_Simulink_P.Internal_3_3_X0;

  /* InitializeConditions for DiscreteStateSpace: '<S9>/Internal_4_4' */
  group_03_Simulink_DWork.Internal_4_4_DSTATE =
    group_03_Simulink_P.Internal_4_4_X0;

  /* InitializeConditions for DiscreteStateSpace: '<S10>/Internal_1_1' */
  group_03_Simulink_DWork.Internal_1_1_DSTATE_m =
    group_03_Simulink_P.Internal_1_1_X0_m;

  /* InitializeConditions for DiscreteStateSpace: '<S10>/Internal_2_2' */
  group_03_Simulink_DWork.Internal_2_2_DSTATE_p =
    group_03_Simulink_P.Internal_2_2_X0_h;

  /* InitializeConditions for DiscreteStateSpace: '<S10>/Internal_3_3' */
  group_03_Simulink_DWork.Internal_3_3_DSTATE_o =
    group_03_Simulink_P.Internal_3_3_X0_p;

  /* S-Function Block: <S3>/Gyro and Accelerometer */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        group_03_Simulink_DWork.GyroandAccelerometer_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void group_03_Simulink_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
