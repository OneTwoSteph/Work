function [a, alpha] = compute_a_alpha(T, q, qr, eps)
% COMPUTE_A_ALPHA Computes the values a and alpha from the Canudas
% algorithm.
% 
% [a, alpha] = compute_a_alpha(T, q, qr, eps)
%
% Inputs: - T = T matrix of the algorithm
%         - q = robot's pose in [m] and [rad]
%         - qr = goal pose in [m] and [rad]
%         - esp = sjmallest distance error [m]
%
% Outputs:  - a = arc of circle from robot to goal point [m]
%           - alpha = angle between world x axis and tangent line to arc of
%           circle from robot to goal point, going through the goal point
%           [rad]
%
% Stephanie Amati, May 2015

% Compute error state
qe = T(qr(3))*(q-qr);

% Compute initial z state
% there are some tests to ensure continuity (inf points)
% atan2 certifiates that the angle stazs in [-pi, pi]
if((abs(qe(1))<eps) && (abs(qe(2))<eps))
    thetad = 0;
else
    thetad = 2*atan2(qe(2),qe(1));
    thetad = limit_angle(thetad);
end

r = (qe(1)^2 + qe(2)^2)/(2*qe(2));

if(abs(qe(2))<eps)
    a = qe(1);
else
    a = r * thetad;
end
alpha = qe(3)-thetad;
alpha = limit_angle(alpha);

end

