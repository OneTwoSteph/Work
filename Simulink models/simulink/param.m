% PARAM Contains all the paramaters of the robot used in the simulink
% models

% Clear
clear all;
close all;
clc;

% Goal position
xr = 0;                % x coordinate [m]
yr = 0;                % y coordinate [m]
thetar = pi;         % theta angle [rad]

% Geometry
l = 0.021;             % distance between wheels [m]
r = 0.0885;            % wheel radius [m]

% Controller
K1 = 1.35;
K2 = 4.6;

% Tolerances
eps = 1e-6;            % tolerance on small position [m]
eps1 = 0.05;           % position tolerance [m]
eps2 = 2*pi*5/360;     % angle tolerance [rad]
