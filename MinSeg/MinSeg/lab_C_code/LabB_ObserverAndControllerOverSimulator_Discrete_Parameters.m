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

%% Define whether simulation and figures should be done
simfig = 0; % 1 = yes, 0 = no

if simfig
    %%
    open_system('./LabB_ObserverAndControllerOverSimulator_Discrete');
    sim('LabB_ObserverAndControllerOverSimulator_Discrete');
    save_system('LabB_ObserverAndControllerOverSimulator_Discrete');
    close_system('LabB_ObserverAndControllerOverSimulator_Discrete');
    
    %% plot the results
    figure;
    plot(x_w.time,x_w.signals.values);
    title('x_w - measured vs. observed');
    xlabel('time (s)');
    ylabel('distance (m)');
    % [hleg1, hobj1] = legend('$x_{w}$','$\dot{x_{w}}$','$\theta_{b}$','$\dot{\theta_{b}}$');
    [hleg1, hobj1] = legend('$x_{w}$','$\hat{{x_{w}}^{p}}$');
    textobj = findobj(hobj1, 'type', 'text');
    set(textobj, 'Interpreter', 'latex', 'fontsize', 15);
    print('-depsc2', '-r300', 'SS_ObserverAndController_Discrete_xw.eps');
    figure;
    plot(theta_b.time,theta_b.signals.values);
    title('\theta_b - measured vs. observed');
    xlabel('time (s)');
    ylabel('angle (rad)');
    % [hleg1, hobj1] = legend('$x_{w}$','$\dot{x_{w}}$','$\theta_{b}$','$\dot{\theta_{b}}$');
    [hleg1, hobj1] = legend('$\theta_{b}$','$\hat{{\theta_{b}}^{p}}$');
    textobj = findobj(hobj1, 'type', 'text');
    set(textobj, 'Interpreter', 'latex', 'fontsize', 15);
    print('-depsc2', '-r300', 'SS_ObserverAndController_Discrete_tb.eps');
    % set(h1,'Interpreter','latex');
    figure;
    plot(u.time,u.signals.values)
    title('controller effort');
    xlabel('time (s)');
    ylabel('potential (V)');
    print('-depsc2', '-r300', 'SS_ObserverAndController_Discrete_vm.eps');
end