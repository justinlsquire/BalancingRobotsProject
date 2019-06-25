close all;
clear all;
clc;

% Run this code to load Kd
LabB_ControllerOverSimulator_Discrete_Parameters;
% Clear all variables except Kd
clearvars -except Kd
save('oacos_d_p.mat');
% Run this code to load the other gains
LabB_ObserverOverSimulator_Discrete_Parameters;
% Clear all variables except those necessary
clearvars -except Kd Ld Md1 Md2 Md3 Md4 Md5 Md6 Md7 Ad Bd Cd Dd
load('oacos_d_p.mat');

% load the sampling frequency
setSampFreq
load sampFreq.mat
fSamplingPeriod = 1/sampFreq;

% Do not modify these variables
iNumberOfEncoderSteps	= 720;
fGyroConversionFactor	= -1/131;
fWheelRadius			= 0.0216; % [m]
load('GyroBias.mat');
% fGyroBias = fGyroBias + 26;
% fGyroBias = fGyroBias + -5;

