% ccc
% load SS_Controller_num_obs__12_3_16.mat
load sim_fig_ind.mat
fig_ind = fig_ind+1;

%Load all the important parameters (namely observer pole multiplicity)
%
load obs_poles.mat

% basic parameters
% fSamplingPeriod		= 0.005;	% [sec]
% iCommunicationTime	= 10;		% [sec]
% iCOMPort			= 'Com6';
% fPlotsUpdatesPeriod	= .25;		% [sec]
% %
% % advanced parameters
% iNumberOfSignals	= 7;
% strByteOrder		= 'bigEndian';
% iBaudRate			= 115200;
% strDataType			= 'uint8';
% 
time = fSamplingPeriod:fSamplingPeriod:iCommunicationTime;
time = [0 time];

% Modify information to add the first sample twice
aafProcessedInformation = [aafProcessedInformation(:,1) aafProcessedInformation];



% placeholders
% U_INDEX						= 1;
% MEASURED_X_W_INDEX			= 2;
% MEASURED_THETA_B_INDEX		= 3;
% X_W_HAT_FULL_INDEX			= 4;
% THETA_B_HAT_FULL_INDEX		= 5;
% X_W_HAT_REDUCED_INDEX		= 6;
% THETA_B_HAT_REDUCED_INDEX	= 7;
% MAIN_FIGURE_INDEX			= 8;


close all

% Compute estimation errors
afXwErrorFull =		aafProcessedInformation(MEASURED_X_W_INDEX,:)...
				-	aafProcessedInformation(X_W_HAT_FULL_INDEX,:);
afXwErrorRed =		aafProcessedInformation(MEASURED_X_W_INDEX,:)...
				-	aafProcessedInformation(X_W_HAT_REDUCED_INDEX,:);
afTbErrorFull =		aafProcessedInformation(MEASURED_THETA_B_INDEX,:)...
				-	aafProcessedInformation(THETA_B_HAT_FULL_INDEX,:);
afTbErrorRed =		aafProcessedInformation(MEASURED_THETA_B_INDEX,:)...
				-	aafProcessedInformation(THETA_B_HAT_REDUCED_INDEX,:);


titlestr = [{'motor voltage'},{'x_w'},{'\theta_b'}];            
groupz{1} = [U_INDEX];
groupz{2} = [MEASURED_X_W_INDEX,X_W_HAT_FULL_INDEX,X_W_HAT_REDUCED_INDEX];
groupz{3} = [MEASURED_THETA_B_INDEX,THETA_B_HAT_FULL_INDEX,THETA_B_HAT_REDUCED_INDEX];

% Save data
save(sprintf('FinalRun%d_Robot_Data_Sampling_rt_%.0f.mat',fig_ind,1/fSamplingPeriod));

% iSignal = 1;
% figure;
% plot(time, aafProcessedInformation(groupz{iSignal},:));
% title(titlestr{iSignal});
% print('-depsc2', '-r300', sprintf('Run_%d_Robot_data_voltage_fp=%.0f_pp=%.0f.eps',fig_ind,fp,pp));
% for iSignal = 2:3 %iNumberOfSignals;
% 	figure
% 	plot(time, aafProcessedInformation(groupz{iSignal},:));
%     title(titlestr{iSignal});
%     legend('measured','full obs','partial obs');
%     print('-depsc2', '-r300', sprintf('Run_%d_Robot_data_x-th_%d_fp=%.0f_pp=%.0f.eps',fig_ind,iSignal,fp,pp));
% end;
% 
% figure;            
% plot(time,afXwErrorFull,time,afXwErrorRed);
% title('x_w estimation errors');
% xlabel('time (s)');
% ylabel('distance (m)');
% legend('full estimator','reduced estimator');
% print('-depsc2', '-r300', sprintf('Run_%d_Robot_data_x_w_error_fp=%.0f_pp=%.0f.eps',fig_ind,fp,pp));
% figure
% plot(time,afTbErrorFull,time,afTbErrorRed);
% title('\theta_b estimation errors');
% xlabel('time (s)');
% ylabel('angle (rad)');
% legend('full estimator','reduced estimator');
% print('-depsc2', '-r300', sprintf('Run_%d_Robot_data_theta_b_error_fp=%.0f_pp=%.0f.eps',fig_ind,fp,pp));

save('sim_fig_ind.mat','fig_ind');