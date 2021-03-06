% SERIAL_COMMANDS Contains the main serial functions to communicate
% with a device by serial communicaton.

%% See list of connected devices
devices = instrhwinfo('Serial');

%% Create serial object
% have to check port number
s = serial('COM18', 'Terminator', 'CR/LF');

%% Open port
fopen(s);

%% Write to device
fprintf(s,'Ol� ?')

%% Receive from device
out = fscanf(s);

%% Close port
fclose(s);
delete(s);
clear s;