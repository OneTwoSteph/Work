function dynamic_system()
% DYNAMIC_SYSTEM Computes the state space model of a differential wheeled
% robot and a controller based on defined poles.

% Define variables
syms m;                 % mass of the robot
syms I;                 % inertia
syms c;                 % cos(theta)
syms s;                 % sin(theta)
syms R;                 % wheels radius
syms L;                 % distance between wheel
syms der_theta;         % theta'

% Dynamics matrices
M = [m 0 0; 0 m 0; 0 0 I];
B_ini = (1/R) * [c c; s s; L -L];
S = [c 0; s 0; 0 1];
der_S = [-der_theta*s 0; der_theta*c 0; 0 0];

M_ = transpose(S)*M*S;
V_ = transpose(S)*M*der_S;
B_ = transpose(S)*B_ini;

% State space matrices with x = [v, w, a, alpha] 
A = [0 0 1 0; 0 0 0 1; 0 0 0 0; 0 0 0 0]
B = [0 0; 0 0; M_\B_]
C = eye(4)

% Substitute variables by their parametric value to start computations
B = double(subs(B, [m, I, R, L], [1.5, 0.6, 0.05, 0.1]));
% subs(M_, [m, c, s], [2, 1, 1])

% Check if system is contrallable
Co = ctrb(A, B);
unco = length(A)-rank(Co);

% Construct state space model of the system x' = Ax + Bu and y = Cx + Du
sys = ss(A,B,C,0);

% Check open loop system response to 0 command starting from non zero
% initial state (v = 2, w = pi/2 and no acceleration)
% The system should stay at this state/output since there is no feedback !
figure()
box;

t = 0:0.01:5;
u = zeros(length(t), length(B(1,:)));
x0 = [2 pi/2 0 0];

[y,t,x] = lsim(sys,u,t,x0);

f(1) = subplot(2,1,1);
hold on;
plot(t,u(:,1), 'g');
plot(t,u(:,2), 'b');
legend('right torque', 'left torque');
xlabel('time [s]');
ylabel('input values');

f(2) = subplot(2,1,2);
plot(t,y)
legend('v', 'w', 'a', 'alpha');
xlabel('time [s]');
ylabel('output values');

linkaxes(f, 'x');

% Find controller by placing predefined poles in close loop
p1 = -2 + 2i;
p2 = -2 - 2i;
p3 = -5;
p4 = -10;

K = place(A,B,[p1 p2 p3 p4]);

% Construct state space model of the system with controller (reference is
% now considered as the input of the augmented system (robot + controller)
sys_cl = ss(A-B*K,B,C,0);

% Check controlled system's response to reference 0 starting from non zero
% initial state (v = 2, w = pi/2 and no acceleration)
% The system should reach zero state since there is a feedback loop !
figure()
box

t = 0:0.01:5;
r = zeros(length(t), length(B(1,:)));
x0 = [2 pi/2 0 0];

[y,t,x] = lsim(sys_cl, r, t, x0);

g(1) = subplot(2,1,1);
hold on;
plot(t,r(:,1), 'g');
plot(t,r(:,2), 'b')
legend('rigth torque ref', 'left torque ref');
xlabel('time [s]');
ylabel('reference values');

g(2) = subplot(2,1,2);
plot(t,y)
legend('v', 'w', 'a', 'alpha');
xlabel('time [s]');
ylabel('output values');

linkaxes(g, 'x');

% Check controlled system's response to a step reference starting from
% zero state
figure()
box

t1 = 0:0.01:5;
t2 = 5.01:0.01:10;
t = [t1, t2];
xr1 = zeros(length(t1), length(A(1,:)));
xr2 = [ones(length(t2), length(A(1,:))/2), zeros(length(t2), length(A(1,:))/2)];
xr = [xr1; xr2]';
r = K*xr;
x0 = [0 0 0 0];

[y,t,x] = lsim(sys_cl, r, t, x0);

k(1) = subplot(2,1,1);
hold on
plot(t, xr(1,:), 'g');
plot(t, xr(2,:), 'b');
plot(t, r(1,:), 'r');
plot(t, r(2,:), 'k');
legend('v ref', 'w ref', 'right torque ref', 'left torque ref');
xlabel('time [s]');
ylabel('values');

k(2) = subplot(2,1,2);
plot(t,y);
legend('v', 'w', 'a', 'alpha');
xlabel('time [s]');
ylabel('outputs values');

linkaxes(k, 'x');
end