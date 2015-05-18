function angle = limit_angle(angle)
% LIMIT_ANGLE Adds or substracts 2*pi*n to the input angle in order for
% the output angle to be in ]-pi, pi].
%
% angle = limit_angle(angle)
%
% Input:    - angle = angle [rad]
%
% Outut:    - angle = angle in ]-pi, pi] [rad]
%
% Stephanie Amati, May 2015

while((angle <= -pi) || (angle > pi))
    if(angle <= -pi)
        angle = angle + 2*pi;
    else
        angle = angle - 2*pi;
    end
end

end

