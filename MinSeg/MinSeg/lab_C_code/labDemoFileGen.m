% Script to generate .mat file needed for lab final demo

% The 0.5 trial
load FinalRun26_Robot_Data_Sampling_rt_200.mat
% Add time value to end of the experiment 
% Shift the time vector
time = time - fSamplingPeriod;
time = [time 30];
% Add extra sample to end of the data 
temp = aafProcessedInformation(:,end);
aafProcessedInformation = [aafProcessedInformation temp];
% Create the variables needed 
group_03_experiment_1_times = time';
group_03_experiment_1_encoder = aafProcessedInformation(MEASURED_X_W_INDEX,:)';
group_03_experiment_1_angle = aafProcessedInformation(MEASURED_THETA_B_INDEX,:)';
group_03_experiment_1_actuation = aafProcessedInformation(U_INDEX,:)';

% The rmax trial
% 27 - 2.05
% 28 - 1.85
% 29 - 1.6
load FinalRun29_Robot_Data_Sampling_rt_200.mat
% % Add time value to end of the experiment 
% % Shift the time vector
% time = time - fSamplingPeriod;
% time = [time 30];
% % Add extra sample to end of the data 
% temp = aafProcessedInformation(:,end);
% aafProcessedInformation = [aafProcessedInformation temp];
% Create the variables needed 
group_03_experiment_2_times = time';
group_03_experiment_2_encoder = aafProcessedInformation(MEASURED_X_W_INDEX,:)';
group_03_experiment_2_angle = aafProcessedInformation(MEASURED_THETA_B_INDEX,:)';
group_03_experiment_2_actuation = aafProcessedInformation(U_INDEX,:)';


group_03_r_max = 0.16;

group_03_r_IRB = .205;

save('group_03_results.mat','group_03_experiment_1_times',...
    'group_03_experiment_1_encoder','group_03_experiment_1_angle',...
    'group_03_experiment_1_actuation','group_03_experiment_2_times',...
    'group_03_experiment_2_encoder','group_03_experiment_2_angle',...
    'group_03_experiment_2_actuation','group_03_r_max',...
    'group_03_r_IRB');

ccc

load group_03_results.mat