% PARAM Contains all the paramaters of the robot used in the simulink
% models

% Goal position
XG = 1;                % x coordinate [m]
YG = 1;                % y coordinate [m]

% Geometry
length = 0.021;        % distance between wheels [m]
radius = 0.0885;       % wheel radius [m]

% Controller
A = 0.1;               % constant in controller expression
UMAX = 10;             % maximum ?

% Connection parameters
baudrate = 9600;

% Other
inc = 0.05;             % minimum distance to goal to be ok [m]

