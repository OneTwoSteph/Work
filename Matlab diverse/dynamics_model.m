% DYNAMICS_MODEL Implementation of a differential wheeled robot's dynamics
% model.
%
% The model was based on "Dynamic Modelling of Differential-Drive
% Mobile Robots using Lagrange and Newton-Euler Methodologies: A Unified
% Framework" by R Hatab and "Analysis of a Differential Drive Vehicle" by
% M. Selgelid and J. Oakley.
%
% Stephanie Amati, April 2015

%% Clear
clear all;
close all;
clc;

%% Parameters
nb_coord = 5;

%% Parametric variables
mb = sym('mb', 'real');                 % mass of the robots body
mw = sym('mw', 'real');                 % mass of a wheel
m = 2*mw + mb;                          % total mass of the robot
                        
R = sym('R', 'real');                   % wheel radius
L = sym('L', 'real');                   % half of inter wheel length
d = sym('d', 'real');                   % gravity center distance

Iy = sym('Iy', 'real');                 % wheel's inertia on y axis
Iz = sym('Iz', 'real');                 % wheel's inertia on z axis
Ib = sym('Ib', 'real');                 % robot's inertia on z axis
I = mb*d^2 + Ib + 2*Iz + 2*mw*L^2;      % simplificative inertia

%% Variables
t = sym('t', 'real');                   % time

x(t) = sym('x(t)');                     % x position of the robot
y(t) = sym('y(t)');                     % y position of the robot
theta(t) = sym('theta(t)');             % robots orientation
phiR(t) = sym('phiR(t)');               % right wheel angle
phiL(t) = sym('phiL(t)');               % left wheel angle

tR(t) = sym('tR(t)');                   % right wheel torque
tL(t) = sym('tL(t)');                   % left wheel torque

%% Matrices and vectors from the original dynamis model obtained with Lagrange
q = [x; y; theta; phiR; phiL];

M = [m, 0, -mb*d*sin(theta), 0, 0;...
     0, m, mb*d*cos(theta), 0, 0;...
     -mb*d*sin(theta), mb*d*cos(theta), I, 0, 0;...
     0, 0, 0, Iy, 0;...
     0, 0, 0, 0, Iy];
 
B = -mb*diff(theta)*d*[0, 0, cos(theta), 0, 0;...
                       0, 0, sin(theta), 0, 0;...
                       0, 0, 0, 0, 0;...
                       0, 0, 0, 0, 0;...
                       0, 0, 0, 0, 0];
         
C = [cos(theta), sin(theta), 0, -R/2, -R/2;...
     -sin(theta), -cos(theta), 0, 0, 0;...
     0, 0, 1, -R/(2*L), R/(2*L)];
 
T = [0; 0; 0; tR; tL];

S = 1/2*[R*cos(theta), R*cos(theta);...
         R*sin(theta), R*sin(theta);...
         R/L, -R/L;...
         2, 0;...
         0, 2];
     
%% Modified matrices to get rid of the Lagrange's multipliers
n = [phiR; phiL];

M_ = transpose(S)*M*S;      
B_ = transpose(S)*M*diff(S) + transpose(S)*B*S;

M_2 = [Iy+(R^2)*(m*L^2+I)/(4*L^2), (R^2)*(m*L^2-I)/(4*L^2);...
      (R^2)*(m*L^2-I)/(4*L^2), Iy+(R^2)*(m*L^2+I)/(4*L^2)];
B_2 = [0, diff(theta)*(R^2)*mb*d/(2*L);...
      -diff(theta)*(R^2)*mb*d/(2*L), 0];

equ1 = eq((M_*diff(n) + B_*n), (transpose(S)*T));
  
%% Modified matrices to get the same model as in paper (u = [v, w] instead of n)  
u = [sqrt(diff(x)^2 + diff(y)^2); diff(theta)];

Tr = 1/R*[1, L; 1, -L];                 % n = Tr*u
  
M__ = M_*Tr;                            % aren't used because not simplified
B__ = M_*Tr;

%M__2 =

equ2 = eq((M__*diff(u) + B__*u), (transpose(S)*T));

