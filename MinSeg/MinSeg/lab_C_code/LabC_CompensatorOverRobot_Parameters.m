% load LabB_Solutions.mat
close all;
clear all;
clc;

% Run this code to load Kd
LabB_ControllerOverSimulator_Discrete_Parameters;
% Clear all variables except Kd
clearvars -except Kd Ad Bd Cd Dd
save('oacos_d_p.mat');
% Run this code to load the other gains
LabB_ObserverOverSimulator_Discrete_Parameters;
% Clear all variables except those necessary
clearvars -except Kd Ld Md1 Md2 Md3 Md4 Md5 Md6 Md7 Ad Bd Cd Dd
load('oacos_d_p.mat');

% Redefine Cd for the x_w output
Cd = [1 0 0 0];

[r c] = size(Ad);

M = [(Ad - eye(size(Ad))) Bd;...
      Cd                  Dd];
  
N = [zeros(r,1);
        1];
    
Nvec = inv(M)*N;

Nxd = Nvec(1:r);
Nud = Nvec(end);

% load the sampling frequency
setSampFreq
load sampFreq.mat
fSamplingPeriod = 1/sampFreq;

% Do not modify these variables
iNumberOfEncoderSteps	= 720;
fGyroConversionFactor	= -1/131;
fWheelRadius			= 0.0216; % [m]
load('GyroBias.mat');
fGyroBias = fGyroBias + 23; %has ranged from 19 to 26

% Build reference signal
r_max = 0.05;
r_max = 0.205; %worked
r_max = 0.2; 
             

tv = [0,10,20,30];
r = [0,0,10*r_max,10*r_max];
refsignal = [tv;r];
save('refsig.mat','refsignal');

% t1 = 0:0.001:10-0.001;
% t2 = 10:0.001:20-0.001;
% t3 = 20:0.001:30;
% t_tot = [t1,t2,t3];
% r = [zeros(1,length(t1)),(0.05*(t2-10)),(0.5*ones(1,length(t3)))];

