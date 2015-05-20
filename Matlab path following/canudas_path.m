% CANUDAS_PATH Simulation of control law developped by Canudas to follow
% paths given by a sequence of points.
%
% Stephanie Amati, May 2015

%% Cleaning
clear all;
close all;
clc

%% Paramaters
K1 = 1.35;
K2 = 4.6;

dt = 0.05;              % sample time [s]

q0 = [0; 0; 0];         % initial state [x, y, theta]

goal_color = [1,0,0; 0,0,0];
robot_color = [0,0,1; 0,0,0];

eps = 1e-6;             % tolerance for very small positions [m] 
eps1 = 0.05;            % position error [m]
eps2 = 2*pi*5/360;      % angle error [rad]

start = true;

%% Variables
q = q0;
qe = [inf; inf; inf];
v = 0;
w = 0;

%% Function matrices
T = @(x) [cos(x), sin(x), 0;...
          -sin(x), cos(x), 0;...
          0, 0, 1];
G = @(x) [cos(x), 0;...
          sin(x), 0;...
          0, 1];
      
J = @(x, y, z) [z*x/y - 1, z*(1-x^2/y^2)/2 + x/y, 0;...
                2*y/(1+y^2/x^2)/x^2, -2/(1+y^2/x^2)/x, 1];

%% Path parameters
% Parameters to choose
p = [1, 4, 0; 4, 4, 0; 5, 3, -pi/2; 5, 1, -pi/2]';
vel = [0.2; 0.3; 0.3];

% Distance arcs between point
d = zeros(size(p, 2)-1, 1);
for i=1:(size(p, 2)-1)
    [d(i), prout] = compute_a_alpha(T, p(:,i), p(:,i+1), eps);
end

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

% One loop represents one dt
while((abs(qe(1))>eps1) || (abs(qe(2))>eps1) || (abs(qe(3))>eps2))
    % Take loop starting time
    tic;
    
    % Draw robot's pose/state
    state_arrow(q, 1, fig, robot_color);

    % Compute a and alpha (z vector)
    [a, alpha] = compute_a_alpha(T, q, qr, eps);
    
    % Compute commands
    B = J(qe(1), qe(2), thetad)*T(qr(3))*G(q(3));
    
    if((r==0) && (thetad==0) && (start))
        v = 1;
    else
        v = -K1*B(1,1)*a;
    end
    w = -B(2,1)*v - K2*alpha;
    
    % Compute next position
    q(1) = q(1) + dt*cos(q(3))*v;
    q(2) = q(2) + dt*sin(q(3))*v;
    q(3) = q(3) + dt*w;
    
    % Wait to create more "real" simulation
    time = toc;
    if(time < dt)
        pause(dt-toc);
        %display('oui')
    end
    
    if(start)
        start = false;
    end
end