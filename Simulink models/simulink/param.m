% PARAM Contains all the paramaters of the robot used in the simulink
% models

% Goal position
xr = 1;                % x coordinate [m]
yr = 1;                % y coordinate [m]
thetar = pi/2;         % theta angle [rad]

% Geometry
l = 0.021;             % distance between wheels [m]
r = 0.0885;            % wheel radius [m]

% Controller
K1 = 4;
K2 = 1;

% Tolerances
eps = 1e-6;            % tolerance on small position [m]
eps1 = 0.05;           % position tolerance [m]
eps2 = 2*pi*5/360;     % angle tolerance [rad]
