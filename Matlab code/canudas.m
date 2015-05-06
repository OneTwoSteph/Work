% CANUDAS Simulation of control law developped by Canudas

%% Cleaning
clear all;
close all;
clc

%% Paramaters
K1 = 4.6;
K2 = 1.35;

dt = 0.001;             % sample time [s]

q0 = [0, 0, 0];         % initial state [x, y, theta]
qr = [10, 10, pi/4];    % goal state [x, y, theta]

goal_color = [1,0,0; 0,0,0];
robot_color = [0,0,1; 0,0,0];

%% Variables
q = q0;

%% Function matrices
T = @(x) [cos(x), sin(x), 0;...
          -sin(x), cos(x), 0;...
          0, 0, 1];
G = @(x) [cos(x), 0;...
          sin(x), 0;...
          0, 1];
      
J = @(x, y, z) [z*x/y - 1, z*(1-x^2/y^2)/2 + x/y, 0;...
                2*y/(1+y^2/x^2)/x^2, -2/(1+y^2/x^2)/x, 1];

%% Simulation loop
% Initialize figure
fig = figure();
hold on;
box;
axis equal;
xlabel('x position [m]');
ylabel('y position [m]');

% Draw goal pose
state_arrow(qr, 1, fig, goal_color);

% Draw robot's initial pose
state_arrow(q, 1, fig, robot_color);

% Compute initial error state
qe = T(qr(3))+(q-qr);

% Compute initial z state
% atan2 certifiates that the angle stazs in [-pi, pi]
thetad = 2*atan2(qe(2)/qe(1));
thetad = limit_angle(thetad);

r = (qe(1)^2 + qe(2)^2)/(2*qe(2));

a = r * thetad;
alpha = qe(3)-thetad;
alpha = limit_angle(alpha);

% One loop represents one dt
while 1
    % Compute next position
    
    
    % Draw robot position
    
end