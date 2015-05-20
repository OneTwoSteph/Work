% BLUETOOTH_COMMANDS Contains the main bluetooth functions to communicate
% with a device by bluetooth.

%% See list of connected devices
bdevices = instrhwinfo('Bluetooth');

%% Connect to device with its address
bobj = Bluetooth('MacBook Pro de Artur', 0); 

%% Connect to device with its name
bobj = Bluetooth('ALCATEL 2010G', 1); 

%% Open bluetooth connection
fopen(bobj);

%% Send a message
fwrite(bobj, 'coucou');