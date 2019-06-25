% This sets the sampling frequency for all the simulations and scripts
sampFreq = 4.6; % Hz 
sampFreq = 4.9; % Hz 
% sampFreq = 40; % Hz
% sampFreq = 60;
% sampFreq = 80;
% sampFreq = 100;
% sampFreq = 120;
% sampFreq = 140;
% sampFreq = 160;
% sampFreq = 180;
sampFreq = 200;
% sampFreq = 100;
% sampFreq = 50;
save('sampFreq.mat','sampFreq');


% Notes 
% Discrete time controller fails at 4.5 Hz, but works at 4.6 Hz
% Discrete time controller and observer system fails at 4.9 Hz
