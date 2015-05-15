% CANUDAS Simulation of control law developped by Canudas

%% Cleaning
clear all;
close all;
clc

%% Paramaters
K1 = 1.35;
K2 = 4.6;

dt = 0.05;              % sample time [s]

q0 = [0, 0, 0;...
      0, 0, 0;...
      0, 0, 0;...
      0, 0, 0]';        % initial states [x, y, theta]
qr = [1, 1, 0;...
      -1, 1, 0;...
      -1, -1, 0;...
      1, -1, 0]';        % goal states [x, y, theta]

goal_color = [1,0,0; 0,0,0];
robot_color = [0,0,1; 0,0,0];
plus_color = [0,1,0];
minus_color = [0,0,0];

%% Variables
q = q0;
qe = [inf; inf; inf];
v = 0;
w = 0;

%% Function matrices
T = @(x) [cos(x), sin(x), 0;...
          -sin(x), cos(x), 0;...
          0, 0, 1];

%% Simulation loop
% Initialize figure
fig = figure();

% One loop represents one dt
for i=1:4
    % Subplot
    subinfo = [1, 4, i];

    % Draw goal pose
    state_arrow(qr(:,i), 1, fig, goal_color, subinfo);

    % Draw robot's pose/state
    state_arrow(q(:,i), 1, fig, robot_color, subinfo);

    % Compute error state
    qe = T(qr(3, i))*(q(:,i)-qr(:,i));

    % Compute initial z state
    % there are some tests to ensure continuity (inf points)
    % atan2 certifiates that the angle stazs in [-pi, pi]
    if((abs(qe(1))<eps) && (abs(qe(2))==eps))
        thetad = 0;
    else
        thetad = 2*atan2(qe(2),qe(1));
        thetad = limit_angle(thetad);
    end

    r = (qe(1)^2 + qe(2)^2)/(2*qe(2));

    if(abs(qe(2))<eps)
        a = qe(3);
    else
        a = r * thetad;
    end
    alpha = qe(3)-thetad;
    alpha = limit_angle(alpha);

    % Plot arc of circle
    if(a>=0)
        color = plus_color;
    else
        color = minus_color;
    end

    arc_of_circle(q(:,i), qe, r, color, fig, subinfo);
end