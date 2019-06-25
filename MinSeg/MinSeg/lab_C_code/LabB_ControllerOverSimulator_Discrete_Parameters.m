close all;
clear all;
clc;
LabB_ControllerOverSimulator_Continuous_Parameters;
clearvars -except A B C D p_loc C1 p
close all

% load the sampling frequency
setSampFreq
load sampFreq.mat
fSamplingPeriod = 1/sampFreq;

%% Define whether simulation and figures should be done
simfig = 0; % 1 = yes, 0 = no


%% Define C as the vector for x_w
% C = [1 0 0 0];

%% Compute transfer function
[num,den] = ss2tf(A,B,C,D,1);
num = [num(1:3) 0 0]; % truncated due to numerical issue
[Z,P,K] = tf2zp(num,den);
sys = tf(num,den);

%% Discretize the system
csys = ss(A,B,C,D);
dsys = c2d(csys,fSamplingPeriod);
[Ad,Bd,Cd,Dd] = ssdata(dsys);
% A = Ad;
% B = Bd;
% C = Cd;
% D = Dd;

%% Redefine Cd for the x_w output
% Cd = [1 0 0 0];
% 
% [r c] = size(Ad);
% 
% M = [(Ad - eye(size(Ad))) Bd;...
%       Cd                  Dd];
%   
% N = [zeros(r,1);
%         1];
%     
% Nvec = inv(M)*N;
% 
% Nxd = Nvec(1:r);
% Nud = Nvec(end);

%% Calculate control law using LQR
C1 = [10 0 20 0]; % More oscillatory but better for disturbances
C1 = [5 2 5 2];
% C1 = [15 5 15 6]; % Best performance probably
C1 = [15 4 15 4]; % Maybe use this one for the speed?
C1 = [15 7 15 7]; % Better balancing, but less resistant to disturbance
% C1 = [5 0 20 0];
% C1 = [5  0 10 0];
% C1 = [15 0 18 0];
% C1 = [10 3 20 4]; % Adding some weight to the derivative terms provides some damping but less robust to disturbances
rho = 20; 
rho = 35;
rho = 1; % Slower return to x position 
rho = 0.1;
rho = 25;
rho = 30;
% rho = 35;
% rho = 10;
% rho = 0.5;
% rho = 3; % Slightly faster but maybe a little more oscillation
% rho = 4;
% rho = 10; %not working well
% rho = 30;

R = 1;
Q = C1;
% Q = [6 0 0 0;...
%      0  4 0 0;...
%      0  0 6 0;...
%      0  0 0  5];
Q = rho*Q'*Q;
% Q = rho*Q;
[Kd,S,e] = dlqr(Ad,Bd,Q,R,0);

% For taking it from continuous time 
% Load the continuous time controller poles from Lab B and use those to
% take the poles here
% C1 = [15 5 15 6];
% rho = 25;
% R = 1;
% Q = C1;
% Q = rho*Q'*Q;
% K2 = lqr(A,B,Q,1); 
% Pole placement
% Ko = eig(Ad);
% Ko = sort(Ko);
% Ko = Ko(1:2);
% p_pp = [Ko; 0.95; 0.98];
% Kd = acker(Ad,Bd,p_pp);

eig(Ad-Bd*Kd);


if simfig
    %%
    open_system('./LabB_ControllerOverSimulator_Discrete');
    sim('LabB_ControllerOverSimulator_Discrete');
    save_system('LabB_ControllerOverSimulator_Discrete');
    close_system('LabB_ControllerOverSimulator_Discrete');
    
    %% plot the results
    figure;
    plot(x.time,x.signals.values(:,[1 3]));
    title('state space variables');
    xlabel('time (s)');
    % [hleg1, hobj1] = legend('$x_{w}$','$\dot{x_{w}}$','$\theta_{b}$','$\dot{\theta_{b}}$');
    [hleg1, hobj1] = legend('$x_{w} (m)$','$\theta_{b} (rad)$');
    textobj = findobj(hobj1, 'type', 'text');
    set(textobj, 'Interpreter', 'latex', 'fontsize', 15);
    print('-depsc2', '-r300', 'SS_Controller_discrete_states.eps');
    % set(h1,'Interpreter','latex');
    figure;
    plot(u.time,u.signals.values)
    title('controller effort');
    xlabel('time (s)');
    ylabel('potential (V)');
    print('-depsc2', '-r300', 'SS_Controller_discrete_vm.eps');
end

