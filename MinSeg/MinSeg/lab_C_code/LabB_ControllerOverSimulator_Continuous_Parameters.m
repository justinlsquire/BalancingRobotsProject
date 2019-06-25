close all;
clear all;
clc;

%% Define whether simulation and figures should be done
simfig = 0; % 1 = yes, 0 = no

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
sys = minreal(tf(num,den));

%% Calculate control law using dominant second order method
% Desired poles of the system
p1 = -2+1i*2;
p2 = -2-1i*2;
% p1 = -5+1i*2;
% p2 = -5-1i*2;
% p1 = -2;
% p2 = -3;
p_loc = [P(2) P(4) p1 p2];
% denk = poly(p_loc);
K = acker(A,B,p_loc);

%% Calculate control law using LQR method

% Define relative importance of the different state variables
% This is for xw,xw_dot,theta_b,theta_b_dot
C1 = [9 5 15 9];
C1 = [15 5 15 6]; % Worked well with robot for balancing
C1 = [6 0 11 0]; 
% C1 = [4 0 25 0];
% C1 = [1 10 1 9];
% C1 = [3 2 15 8]; % Worked well in simulation but not in practice
% C1 = [15 8 5 5];
% 
% % Calculate the transfer function using this output relationship
% s = tf('s');
% I = eye(size(A));
% sys = C1*inv(s*I-A)*B;
% sys = minreal(sys);
% [num,den]=tfdata(sys);
% num = num{1};
% den = den{1};
% Z = roots(num);
% P = roots(den);
% % num(end)=0; % make sure this is necessary - due to roundoff error
% [Z,P,K] = tf2zp(num,den);
% 
% % symmetric system (-s) for SRL
% nums = tf(1);
% s = tf('s');
% for i = 1:length(Z)
%     eval(sprintf('numtemp = (-s-(%f+1i*%f));',real(Z(i)),imag(Z(i))));
%     nums = nums*numtemp;
% end
% dens = tf(1);
% for i = 1:length(P)
%     eval(sprintf('dentemp = (-s-(%f+1i*%f));',real(P(i)),imag(P(i))));
%     dens = dens*dentemp;
% end
% 
% tfs = K*(nums/dens);
% 
% % This added in due to a numerical issue and adding a small imaginary part
% [num_s,den_s]=tfdata(tfs);
% num1 = real(num_s{1});
% den1 = real(den_s{1});
% tfs = tf(num1,den1);
% 
% 
% % Symmetric Root Locus calculation
rho = 2; % expensive control - doesn't use much controller effort
rho = 100;
rho = 40;
rho = 20; % Good results on robot stationary
rho = 35;
% srl = tfs*sys;
% 
% if(simfig)
%     figure(10);
%     rlocus(srl);
% end
% % Create the closed loop system
% srl = 1+rho*srl;
% 
% % Obtain the numerator and find the roots in the LHP
% % These are the roots that satisfy the SRL equation
% [num,den]=tfdata(srl);
% p = roots(num{1});
% p = p(p<0);
% 
% 
% K = acker(A,B,p);

% Verify with the lqr function
R = 1;
Q = C1;
Q = rho*Q'*Q;
% Q = [15 0  0   0;...
%      0  8  0   0;...
%      0  0  5   0;...
%      0  0  0  .5];
% Used to verify the K calculated above
K2 = lqr(A,B,Q,1); 

if simfig
    %%
    open_system('./LabB_ControllerOverSimulator_Continuous');
    sim('LabB_ControllerOverSimulator_Continuous');
    save_system('LabB_ControllerOverSimulator_Continuous');
    close_system('LabB_ControllerOverSimulator_Continuous');
    
    %% plot the results
    figure;
    plot(x.time,x.signals.values(:,[1 3]));
    title('state space variables');
    xlabel('time (s)');
    % [hleg1, hobj1] = legend('$x_{w}$','$\dot{x_{w}}$','$\theta_{b}$','$\dot{\theta_{b}}$');
    [hleg1, hobj1] = legend('$x_{w} (m)$','$\theta_{b} (rad)$');
    textobj = findobj(hobj1, 'type', 'text');
    set(textobj, 'Interpreter', 'latex', 'fontsize', 15);
    print('-depsc2', '-r300', 'SS_Controller_state_vars2.eps');
    % set(h1,'Interpreter','latex');
    figure;
    plot(u.time,u.signals.values)
    title('controller effort');
    xlabel('time (s)');
    ylabel('potential (V)');
    print('-depsc2', '-r300', 'SS_Controller_vm2.eps');
end




