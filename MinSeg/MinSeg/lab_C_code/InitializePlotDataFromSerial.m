figure(MAIN_FIGURE_INDEX);
hold on;
set(gcf,'unit','normalized','position',[0,0.35,1,0.65]); % xmin ymin xmax ymax
set(gcf, 'menubar', 'none')
for iSignal = 1:iNumberOfSignals;
	subplot(710 + iSignal);
	xlim([afTimes(1) afTimes(end)]);
	drawnow;
end;%
hold off;


figure(MEASURED_X_W_INDEX * 10)
hold on;
set(gcf,'unit','normalized','position',[0,0.05,0.5,0.3]); % xmin ymin xmax ymax
set(gcf, 'menubar', 'none')
legend('full', 'reduced');
title('errors on the observation of x_w');
xlabel('time [sec]');
ylabel('position [m]');
drawnow;
hold off;
fLimitForXw = 0;


% plot the errors on theta_b
figure(MEASURED_THETA_B_INDEX * 10)
hold on;
set(gcf,'unit','normalized','position',[0.5,0.05,0.5,0.3]); % xmin ymin xmax ymax
set(gcf, 'menubar', 'none')
legend('full', 'reduced');
title('errors on the observation of \theta_b');
xlabel('time [sec]');
ylabel('angle [rad]');
drawnow;
hold off;
fLimitForTb = 0;

