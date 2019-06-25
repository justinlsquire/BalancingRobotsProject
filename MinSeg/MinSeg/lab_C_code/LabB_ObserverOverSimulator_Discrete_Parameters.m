close all;
clear all;
clc;

LabB_ControllerOverSimulator_Discrete_Parameters
close all;
clearvars -except Ad Bd Cd Dd Kd
% Redefine Cd, assuming both sensor outputs are available
Cd = [1 0 0 0;
     0 0 1 0];

% load the sampling frequency
setSampFreq
load sampFreq.mat
fSamplingPeriod = 1/sampFreq;

% Find the poles of the closed loop system with controller
pole_d = eig(Ad-Bd*Kd);
% Select the multiplication ratio for the observer poles
Xf = 6; % e.g. 'X' times faster than the poles of the closed loop controller
Xf = 12;
Xr = 12; % For reduced order observer

pp = Xr;
fp = Xf;
save('obs_poles.mat','pp','fp');

polez = exp(Xf*log(pole_d));

ind = find(abs(imag(polez))<0.0001);
polez(ind)=real(polez(ind));

Lt = place(Ad',Cd',polez);
Ld = Lt'; % For full order observer

% Reduced order C vectors split
Ca = [1 0 0 0];
Cna = [0 0 1 0];

% basis completion
V = [0 1 0 0; 0 0 1 0; 0 0 0 1];
% Reduced order shit
T_inv = [Ca;V];
T = inv(T_inv);
At = T_inv*Ad*T;
Bt = T_inv*Bd;
Cat = Ca*T;
Cnat = Cna*T;

Atxx = At(2:end,2:end);
Atyx = At(1,2:end);
Atxy = At(2:end,1);
Atyy = At(1,1);

Bty = Bt(1,1);
Btx = Bt(2:end,1);

Cty = Cnat(1,1);
Ctx = Cnat(1,2:end);


AA = Atxx;
CC = [Atyx;Ctx];
% pole locations
pole_r = abs(pole_d);
pole_r = exp(Xr*log(pole_r(1:3)));

Lr = place(AA',CC',pole_r)';

La = Lr(:,1);
Lna = Lr(:,2);

Md1 = Atxx-La*Atyx-Lna*Ctx;
Md2 = Btx - La*Bty;
Md3 = Atxy-La*Atyy-Lna*Cty;
Md4 = Lna;
Md5 = La;
Md6 = T(:,1);
Md7 = T(:,2:end);