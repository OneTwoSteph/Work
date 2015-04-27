function [A B C] = state_model()
% STATE_MODEL Computes the state model of a diffential wheeled robot and
% and returns the matrices.

% Parameters
m = 1.5;            % mass
I = 0.6;            % inertia
R = 0.05;           % wheel radius
L = 0.1;            % inter-wheel distance

% State mdoel
A = [0 0 1 0; 0 0 0 1; 0 0 0 0; 0 0 0 0]
B = [0 0; 0 0; 1/(m*R) 1/(m*R); L/(I*R) -L/(I*R)]
C = eye(4)