% CANUDAS_ADVANCED Simulation of control law developped by Canudas to follow
% paths given by a sequence of points.
%
% This version alows to plot several variables of the controller.
%
% Stephanie Amati, May 201

%% Cleaning
clear all;
close all;
clc

%% Paramaters
plotvar = yes;

K1 = 1.35;
K2 = 4.6;

dt = 0.05;              % sample time [s]

q0 = [0; 0; 0 ];        % initial state [x, y, theta], theta in ]-pi, pi]
qr = [1; 1; 0];       % goal state [x, y, theta]

goal_color = [1,0,0; 0,0,0];
robot_color = [0,0,1; 0,0,0];

eps = 1e-6;             % tolerance for very small positions [m] 
eps1 = 0.05;            % position error [m]
eps2 = 2*pi*5/360;      % angle error [rad]

%% Variables
q = q0;
qe = [inf; inf; inf];
v = 0;
w = 0;
timer = 0;

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
% Initialize robot figure
fig = figure();
hold on;
box;
axis equal;
xlabel('x position [m]');
ylabel('y position [m]');

% Draw goal pose
state_arrow(qr, 1, fig, goal_color);

% Plotting
if(plotvar)
    % Initialize z plot figure
    zplotfig = figure();

    subplot(4,1,1);
    hold on;
    box;
    grid on;
    xlabel('time [s]');
    ylabel('a [m]');

    subplot(4,1,2);
    hold on;
    box;
    grid on;
    xlabel('time [s]');
    ylabel('alpha [rad]');

    subplot(4,1,3);
    hold on;
    box;
    grid on;
    xlabel('time [s]');
    ylabel('b1 [m^-1]');

    subplot(4,1,4);
    hold on;
    box;
    grid on;
    xlabel('time [s]');
    ylabel('b2 [-]');

    % Initialize commands plot figure
    cplotfig = figure();

    subplot(2,1,1);
    hold on;
    box;
    grid on;
    xlabel('time [s]');
    ylabel('v [m/s]');

    subplot(2,1,2);
    hold on;
    box;
    grid on;
    xlabel('time [s]');
    ylabel('w [rad/s]');
end

% One loop represents one dt
while((abs(qe(1))>eps1) || (abs(qe(2))>eps1) || (abs(qe(3))>eps2))
    % Take loop starting time
    tic;
    
    % Draw robot's pose/state
    state_arrow(q, 1, fig, robot_color);

    % Compute error state
    qe = T(qr(3))*(q-qr);

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
    
    B = J(qe(1), qe(2), thetad)*T(qr(3))*G(q(3));
    
    % Compute commands
%     if((r==0) && (thetad==0) && (timer==0))
%         v = 1;
%     else
        v = -K1*B(1,1)*a;
%     end
    w = -B(2,1)*v - K2*alpha;
    
    % Compute next position
    q(1) = q(1) + dt*cos(q(3))*v;
    q(2) = q(2) + dt*sin(q(3))*v;
    q(3) = q(3) + dt*w;
    
    % Plotting
    if(plotvar)
        % Plot z state
        set(0,'CurrentFigure', zplotfig);
        subplot(4,1,1);
        plot(timer*dt, a, '.r');
        subplot(4,1,2);
        plot(timer*dt, alpha, '.r');
        subplot(4,1,3);
        plot(timer*dt, B(1,1), '.r');
        subplot(4,1,4);
        plot(timer*dt, B(2,1), '.r');
        drawnow;
        
        % Plot commands
        set(0,'CurrentFigure', cplotfig);
        subplot(2,1,1);
        plot(timer*dt, v, '.r');
        subplot(2,1,2);
        plot(timer*dt, w, '.r');
        drawnow;
    end
    
    % Update timer
    timer = timer + 1;
    
    % Wait to create more "real" simulation
    time = toc;
    if(time < dt)
        pause(dt-toc);
        %display('oui')
    end
end