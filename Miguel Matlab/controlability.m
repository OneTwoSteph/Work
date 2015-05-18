function unco = controlability()
% CONTROLABILITY Computes the controllability matrix of an LTI system and
% returns if the system is contrallable or not (0 = contrallable).
%
% Miguel Ruiz, commented by Stephanie Amati, April 2015

% Parameters
m_total = 1.25;
R = 0.05;
L = 0.05;
d = 0.02;
I_total = 0.55;
I_wheel_axis = 0.055;

% Computed parameters
alpha = (m_total + 2*I_wheel_axis) / R^2;
beta = I_total + (2*L^2*I_wheel_axis) / R^2;

% LTI system's state space matrices
A = [0 0 1 0; 0 0 0 1; 0 0 0 0; 0 0 0 0];
B = [0 0; 0 0; 1/(R*alpha) 1/(R*alpha); L/(R*beta) -L/(R*beta)];

% Controllability matrix
Co = ctrb(A,B)

% Check if system controllable (unco = 0 = contrallable)
% A system is controllable if the rank of the controllability matrix is
% equal to the row/column number of elements of its state space matrix A
unco = length(A)-rank(Co);

end