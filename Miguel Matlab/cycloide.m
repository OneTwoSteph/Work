% CICLOIDE ???
%
% Miguel Ruiz

clear all
close all
clc

R = 5;
w = 2;

theta = linspace(0,2*pi, 100);

x = R*(theta-sin(theta));
y = R*(1-cos(theta));

t = linspace(0,2*pi/w, 100);

vx = R*w*(1-cos(theta));
vy = w*sin(theta);

nul = y == 0;

figure()
box

f(1) = subplot(2,1,1);
box
hold on
axis equal
plot(x,y);
xlabel('x');
ylabel('y');

f(2) = subplot(2,1,2);
hold on
box
plot(x, vx, 'b');
plot(x, vy, 'r');
plot(x(nul), y(nul), '*g');
xlabel('x');
ylabel('speed');
legend('x speed', 'y speed');

linkaxes(f, 'x');