% auxiliary variable indicating what to print
aiDataIndexes = (iPacketIndex-iNumberOfPacketsToPlotPerTime+1):iPacketIndex;


% plot the received information
figure(MAIN_FIGURE_INDEX);
for iSignal = 1:iNumberOfSignals;
	subplot(710 + iSignal);
	hold on;
	plot(afTimes(aiDataIndexes), aafProcessedInformation(iSignal, aiDataIndexes), '-k');
	hold off;
	xlim([afTimes(1) afTimes(end)]); % keep the x-axis always the same length
end;%
drawnow;


% compute the estimation errors
afXwErrorFull =		aafProcessedInformation(MEASURED_X_W_INDEX,			aiDataIndexes)...
				-	aafProcessedInformation(X_W_HAT_FULL_INDEX,			aiDataIndexes);
afXwErrorRed =		aafProcessedInformation(MEASURED_X_W_INDEX,			aiDataIndexes)...
				-	aafProcessedInformation(X_W_HAT_REDUCED_INDEX,		aiDataIndexes);
afTbErrorFull =		aafProcessedInformation(MEASURED_THETA_B_INDEX,		aiDataIndexes)...
				-	aafProcessedInformation(THETA_B_HAT_FULL_INDEX,		aiDataIndexes);
afTbErrorRed =		aafProcessedInformation(MEASURED_THETA_B_INDEX,		aiDataIndexes)...
				-	aafProcessedInformation(THETA_B_HAT_REDUCED_INDEX,	aiDataIndexes);


% compute the limits
fLimitForXw = max( fLimitForXw, max(abs([afXwErrorFull, afXwErrorRed])) );
fLimitForTb = max( fLimitForTb, max(abs([afTbErrorFull, afTbErrorRed])) );


% plot the errors on x_w
figure(MEASURED_X_W_INDEX * 10)
plot(afTimes(aiDataIndexes), afXwErrorFull, '-r');
hold on;
plot(afTimes(aiDataIndexes), afXwErrorRed, '-b');
hold off;
% ylim([-fLimitForXw, fLimitForXw]);
xlabel('time [sec]');
ylabel('position [m]');
drawnow;


% plot the errors on theta_b
figure(MEASURED_THETA_B_INDEX * 10)
plot(afTimes(aiDataIndexes), afTbErrorFull, '-r');
hold on;
plot(afTimes(aiDataIndexes), afTbErrorRed, '-b');
hold off;
% ylim([-fLimitForTb, fLimitForTb]);
xlabel('time [sec]');
ylabel('angle [rad]');
drawnow;


