ccc


rates = [40:20:200];
% f_start = 40;
% f_end = 200;
% f_inc = 20;

num_vec = length(rates);

% initialize vector for the vector norms
l2_x = zeros(1,num_vec);
l2_t = zeros(1,num_vec);



for f_ind = 1:num_vec
    % Find the data set
%     fdir = ls(sprintf('bR*%d.mat',rates(f_ind)));
    fdir = ls(sprintf('R*%d.mat',rates(f_ind)));
    % Load the current data set
    load(char(fdir(1,:)));
    data_start_pos = length(aafProcessedInformation)/8*4;
    % Calculate the norms for each
    % If the mean for the signal is not already around zero (abs > 0.02?)
    % then subtract the mean of that range
    thresh = 0.01;
    
    
%     figure
%     plot(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end));
    hold on
    mean(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end))
    if (abs(mean(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end)))>= thresh)
        temp = norm(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end)-mean(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end)))
        temp = temp/length(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end));
        l2_x(f_ind) = temp;
%         plot(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end)-mean(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end)));
    else
        temp = norm(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end));
        temp = temp/(length(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end)));
        l2_x(f_ind) = temp;
    end
    
%     figure
%     plot(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end));
    hold on
    mean(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end))
    if (abs(mean(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end)))>= thresh)
        temp = norm(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end)-mean(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end)));
        temp = temp/length(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end));
        l2_t(f_ind) = temp;
%         plot(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end)-mean(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end)));
    else
        temp = norm(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end));
        temp = temp/length(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end));
        l2_t(f_ind) = temp;
    end
%     figure
%     plot(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end));
%     hold on
%     plot(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end)-mean(aafProcessedInformation(MEASURED_X_W_INDEX,data_start_pos:end)));
%     figure
%     plot(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end));
%     hold on
%     plot(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end)-mean(aafProcessedInformation(MEASURED_THETA_B_INDEX,data_start_pos:end)))
    clearvars -except rates num_vec l2_x l2_t % necessary?
end

figure
plot(rates,l2_x,'-x');
hold on
plot(rates,l2_t,'-o');
title('L_2 Norms for the Signals');
xlabel('Sample rate (Hz)');
legend('x_w','\theta_b');
print('-depsc2', '-r300', 'L2_norms.eps');
    
