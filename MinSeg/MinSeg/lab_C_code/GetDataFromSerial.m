% cleaning
clear all;
clc;
close all;


% load the sampling frequency
setSampFreq
load sampFreq.mat
fSamplingPeriod = 1/sampFreq;

iCommunicationTime	= 30;		% [sec]
iCOMPort			= 'Com6';
fPlotsUpdatesPeriod	= .25;		% [sec]
%
% advanced parameters
iNumberOfSignals	= 7;
strByteOrder		= 'bigEndian';
iBaudRate			= 115200;
strDataType			= 'uint8';


% placeholders
U_INDEX						= 1;
MEASURED_X_W_INDEX			= 2;
MEASURED_THETA_B_INDEX		= 3;
X_W_HAT_FULL_INDEX			= 4;
THETA_B_HAT_FULL_INDEX		= 5;
X_W_HAT_REDUCED_INDEX		= 6;
THETA_B_HAT_REDUCED_INDEX	= 7;
MAIN_FIGURE_INDEX			= 8;


% allocate the memory for receiving the information
% and some auxiliary variables
iNumberOfPackets				= ceil(iCommunicationTime / fSamplingPeriod);
iNumberOfBytesPerPacket			= 1 + 2 * iNumberOfSignals;	% the first byte is a "1" useful for understanding where the packet starts
aafReceivedInformation			= zeros(iNumberOfBytesPerPacket, iNumberOfPackets);
aafProcessedInformation			= zeros(iNumberOfSignals, iNumberOfPackets);
iPacketIndexForStartingPlotting	= 20;
iInitialValidPacket				= 5;
afTimes							= (1:iNumberOfPackets) * fSamplingPeriod;
iNumberOfPacketsToPlotPerTime	= ceil( fPlotsUpdatesPeriod / fSamplingPeriod );


% allocate the structure for the serial communication 
if( ~exist('tSerialCommunication') )
	%
	fprintf('Opening the serial communications...');
	%
	tSerialCommunication = serial(iCOMPort);
	set(tSerialCommunication, 'ByteOrder', strByteOrder);
	set(tSerialCommunication, 'BaudRate', iBaudRate); 
% 	tSerialCommunication.ReadAsyncMode = 'continuous';
% 	fprintf(tSerialCommunication,'*IDN?')
% 	tSerialCommunication.BytesAvailable
	fopen(tSerialCommunication);
	pause(1); % ???
	%
	fprintf('...done\n');
	%
end;%


% initialize the data plotting
InitializePlotDataFromSerial;
 

% cycle on receiving the information
fprintf('Receiving the serial packets:\n');
for iPacketIndex = 1:iNumberOfPackets;
	%
	% read the current packet
	afCurrentPacket = fread(tSerialCommunication, iNumberOfBytesPerPacket, strDataType);
	%
	if(length(afCurrentPacket) == iNumberOfBytesPerPacket)
		%
		aafReceivedInformation(:, iPacketIndex) = afCurrentPacket';
		%
	end;%
	%
	% when one has received a sufficient number of packets then
	% find where the "1" is inside the aafInformation matrix
	% (truncate also the received information by eliminating
	% the first initial packets, that may be corrupted)
	if( iPacketIndex == iPacketIndexForStartingPlotting )
		%
		[~, iIndexOf1] = min( sum(aafReceivedInformation(:, iInitialValidPacket:iPacketIndexForStartingPlotting)' - 1).^2 );
		%
	end;% if find the index of 1
	%
	% if we have received enough packets then reconstruct the signals
	if( iPacketIndex > iPacketIndexForStartingPlotting )
		%
		% do the reconstruction one signal per time
		for iSignal = 1:iNumberOfSignals;
			%
			% indexes of the signal starting from iIndexOf1
			iHighByteIndex	= iIndexOf1 + (iSignal - 1) * 2 + 1;
			iLowByteIndex	= iIndexOf1 + (iSignal - 1) * 2 + 2;
			%
			% re-map the indexes so to point inside the aafInformation matrix
			if( iHighByteIndex > iNumberOfBytesPerPacket);
				%
				iHighByteIndex = iHighByteIndex - iNumberOfBytesPerPacket;
				%
			end;%
			if( iLowByteIndex > iNumberOfBytesPerPacket );
				%
				iLowByteIndex = iLowByteIndex - iNumberOfBytesPerPacket;
				%
			end;%
			%
			% do some magic tricks
			aafProcessedInformation(iSignal, iPacketIndex)	=							...
				(																		...
					(																	...
							aafReceivedInformation(iLowByteIndex, iPacketIndex)			...
						+	256 * aafReceivedInformation(iHighByteIndex, iPacketIndex)	...
					) / 3276.8															...
				) - 10;
			%
		end;% for on the individual signals
		%
	end;% if we have received enough packets
	%
	% print some useful information on the shell
	if( ~mod(iPacketIndex, iNumberOfPacketsToPlotPerTime) )
		%
		fprintf('%3d out of %3d\n', iPacketIndex, iNumberOfPackets);
		%
		% plot also the current estimation errors
		PlotDataFromSerial;
		%
	end;% print on the shell
	%
end;% cycle on the packets
 
 
% close the serial communications
fprintf('Closing the serial communications...');
fclose(tSerialCommunication);
delete(tSerialCommunication);
clear tSerialCommunication;
fprintf('...done\n');

%Ask if the data is good and should be plotted
yn = input('Save and display data? (0 = no, 1 = yes)');



if (yn)
% Call the plotting function to display everything in a good way
plot_robot_data_log
end



