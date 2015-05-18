% DYNAMICS_MODEL2 Implementation of a differential wheeled robot's dynamics
% model.
%
% Stephanie Amati, April 2015

%% Clear
clear all;
close all;
clc;

%% Parametric variables
mb = sym('mb', 'real');                 % mass of the robots body
mw = sym('mw', 'real');                 % mass of a wheel
m = sym('m', 'real');
%m = 2*mw + mb;                          % total mass of the robot
                        
R = sym('R', 'real');                   % wheel radius
L = sym('L', 'real');                   % half of inter wheel length
d = sym('d', 'real');                   % gravity center distance

Iy = sym('Iy', 'real');                 % wheel's inertia on y axis
Iz = sym('Iz', 'real');                 % wheel's inertia on z axis
Ib = sym('Ib', 'real');                 % robot's inertia on z axis
I = sym('I', 'real');
%I = mb*d^2 + Ib + 2*Iz + 2*mw*L^2;      % simplificative inertia

%% Variables
x = sym('x', 'real');                   % x position of the robot
y = sym('y', 'real');                   % y position of the robot
theta = sym('theta', 'real');           % robots orientation
phiR = sym('phiR', 'real');             % right wheel angle
phiL = sym('phiL', 'real');             % left wheel angle

omega = sym('omega', 'real');           % angular velocity (diff(theta))

tR = sym('tR', 'real');                 % right wheel torque
tL = sym('tL', 'real');                 % left wheel torque

%% Matrices and vectors from the original dynamis model obtained with Lagrange
q = [x; y; theta; phiR; phiL];

M = [m, 0, -mb*d*sin(theta), 0, 0;...
     0, m, mb*d*cos(theta), 0, 0;...
     -mb*d*sin(theta), mb*d*cos(theta), I, 0, 0;...
     0, 0, 0, Iy, 0;...
     0, 0, 0, 0, Iy];
 
B = -mb*omega*d*[0, 0, cos(theta), 0, 0;...
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
     
Sp = 1/2*[-omega*R*sin(theta), -omega*R*sin(theta);...
          omega*R*cos(theta), omega*R*cos(theta);...
          0, 0;...
          0, 0;...
          0, 0];
     
%% Modified matrices to get rid of the Lagrange's multipliers
n = [phiR; phiL];

M_c = transpose(S)*M*S;      
B_c = transpose(S)*M*Sp + transpose(S)*B*S;

M_ = [Iy+(R^2)*(m*L^2+I)/(4*L^2), (R^2)*(m*L^2-I)/(4*L^2);...
      (R^2)*(m*L^2-I)/(4*L^2), Iy+(R^2)*(m*L^2+I)/(4*L^2)];
B_ = [0, omega*(R^2)*mb*d/(2*L);...
      -omega*(R^2)*mb*d/(2*L), 0];
  
% to check if ok
simplify(M_c)
M_
simplify(B_c)
B_
  
%% Modified matrices to get the same model as in paper (u = [v, w] instead of n)  
Tr = 1/R*[1, L; 1, -L];                 % n = Tr*u
  
M__c = M_*Tr;                           % aren't used because not simplified
B__c = B_*Tr;

M__ = 1/R*[Iy+R^2*m/2, Iy*L+R^2*I/(2*L);...
           Iy+R^2*m/2, -Iy*L-R^2*I/(2*L)];
B__ = omega*R*mb*d/2*[1/L, -1; -1/L, -1];

% to check if ok
simplify(M__c)
M__
simplify(B__c)
B__
