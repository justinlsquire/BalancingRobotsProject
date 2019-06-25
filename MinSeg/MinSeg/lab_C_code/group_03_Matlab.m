fSHZ = 200; % Hz
fSamplingPeriod = 1/fSHZ;

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

%% Discretize the system
csys = ss(A,B,C,D);
dsys = c2d(csys,fSamplingPeriod);
[Ad,Bd,Cd,Dd] = ssdata(dsys);

%% Calculate control law using LQR
C1 = [15 5 15 6]; % Best performance probably
C1 = [15 4 15 4]; % Maybe use this one for the speed?
% C1 = [15 7 15 7]; % Better balancing, but less resistant to disturbance
rho = 30;
R = 1;
Q = C1;
Q = rho*Q'*Q;
[Kd,S,e] = dlqr(Ad,Bd,Q,R,0);

clearvars -except Kd Ad Bd Cd Dd fSamplingPeriod

%% Calculate observer gains
Cd = [1 0 0 0;
     0 0 1 0];

% Find the poles of the closed loop system with controller
pole_d = eig(Ad-Bd*Kd);
% Select the multiplication ratio for the observer poles
Xf = 6; % e.g. 'X' times faster than the poles of the closed loop controller
Xf = 12;
Xr = 12; % For reduced order observer

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
% Reduced order stuff
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
pole_r = exp(Xr*log(pole_r(2:end)));

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

clearvars -except Kd Ld Md1 Md2 Md3 Md4 Md5 Md6 Md7 Ad Bd Cd Dd fSamplingPeriod

%% Calculate the reference input stuff
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

%% Load simulator stuff
% Do not modify these variables
iNumberOfEncoderSteps	= 720;
fGyroConversionFactor	= -1/131;
fWheelRadius			= 0.0216; % [m]
load('GyroBias.mat');

%% Build reference signal
r_max = 0.05; % base trial
r_max = 0.205; % Worked several times
r_max = 0.185; % Worked every time, but sometimes scary
r_max = 0.16; % Conservative maximum
             

tv = [0,10,20,30];
r = [0,0,10*r_max,10*r_max];
refsignal = [tv;r];