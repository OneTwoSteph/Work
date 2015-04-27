% KVAR Allows to see the shape of the variable K, the gain of the robot's
% controller for go-to-goal and obstacle avoidance.

%% Clean
clear all
close all
clc

%% Paramaters
% initial error xg-x, yg-y
e0 = 1;

% alpha
alpha = 1;

% error tolerance
epsilon = 0.01;

% dt
dt = 0.01;

%% Computations (dt = 1)
% go-to-goal
e = e0;
k = e0*(1-exp(-alpha*abs(e)^2))/abs(e);

error = e;
gain = k;

while e > epsilon
   % next error
   e = e*(1-k*dt);
   
   % next gain
   k = e0*(1-exp(-alpha*abs(e)^2))/abs(e);
   
   % save vectors
   error = [error; e];
   gain = [gain; k];
end

%% Plot
t = 0:dt:(length(error)-1)*dt;

figure()
box;

f(1) = subplot(2,1,1);
plot(t, error, 'r');
xlabel('time');
ylabel('error');

f(2) = subplot(2,1,2);
plot(t, gain, 'b');
xlabel('time');
ylabel('gain');

linkaxes(f, 'x');

figure()
e = 0:0.01:5;
plot(e, 5.*(1-exp(-alpha.*abs(e).^2))./abs(e));
xlabel('error');
ylabel('gain');
