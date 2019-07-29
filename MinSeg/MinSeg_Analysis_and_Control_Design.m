%% MinSeg system analysis and controller design
clc
clear all
close all

%% Constants defined
g = 9.8;
b_f = 0;
m_b = 0.381;
l_b = 0.112;
I_b = 0.00616;
m_w = 0.036;
l_w = 0.021;
I_w = 0.00000746;
R_m = 4.4;
L_m = 0;
b_m = 0;
K_e = 0.444;
K_t = 0.470;

%% EOM w/out disturbance
a = I_b+m_b*l_b^2;
b = m_b*l_b;
e = b_f/l_w+K_e*K_t/(R_m*l_w);
f = -b_f-K_e*K_t/R_m;
g = m_b*g*l_b;
d = I_w/l_w+l_w*m_w+l_w*m_b;
c = l_w*l_b*m_b;
h = -K_e*K_t/(R_m*l_w)-b_f/l_w;
i = b_f+K_e*K_t/R_m;

A1 = [1 0 0 0;...
      0 b 0 a;...
      0 0 1 0;...
      0 d 0 c];
  
B1 = [0 1 0 0;...
      0 e g f;...
      0 0 0 1;...
      0 h 0 i];

beta1 = [0;...
        -K_t/R_m;...
         0;...
         K_t/R_m];
 
A = inv(A1)*B1;
B = inv(A1)*beta1;
% C = eye(4);
% D = zeros(4,2);
C = [0 0 1 0];
D = 0;

%% Compute transfer function
[num,den] = ss2tf(A,B,C,D,1);
num = [num(1:3) 0 0]; % truncated due to numerical issue
[Z,P,K] = tf2zp(num,den);
sys = tf(num,den);

%% convert to digital
sysD = c2d(sys,0.01); % 100 Hz