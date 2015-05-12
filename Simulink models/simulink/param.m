% PARAM Contains all the paramaters of the robot used in the simulink
% models
% !!! The robot's parameters must correspond to those defined in the
% Sim.I.Am robot initialization otherwise it makes no sense.

% Clear
clear all;
close all;
clc;

% Robots initial position
xinit = 0;                          % x coordinate [m]
yinit = 0;                          % y coordinate [m]
thetainit = 0;                      % theta angle [rad]

% Goal position
xr = 0;                             % x coordinate [m]
yr = 0;                             % y coordinate [m]
thetar = pi;                        % theta angle [rad]

% Geometry
l = 0.08841;                        % distance between wheels [m]
r = 0.0205;                         % wheel radius [m]
ticks = 2764;                       % number of ticks per wheel revolution [-]

% Controller
K1 = 1.35;
K2 = 4.6;

% Tolerances
eps = 1e-6;                         % tolerance on small position [m]
eps1 = 0.05;                        % position tolerance [m]
eps2 = 2*pi*5/360;                  % angle tolerance [rad]

% Other informations
max_phi = 48000*6.9440e-06/r;       % max wheel speed [rad/s]
max_v = r * max_phi;                % max linear speed at w = 0 [m/s]
max_w = max_phi*2*r/l;              % max angular speed at v = 0 [rad/s]

dt = 0.033;                         % sample time [s]