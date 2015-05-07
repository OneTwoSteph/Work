function angle = limit_angle(angle)
% LIMIT_ANGLE Changes input angle to an angle in ]-pi, pi]
%
% angle = limit_angle(angle)
%
% OneTwoSteph, May 2015

while((angle <= -pi) || (angle > pi))
    if(angle <= -pi)
        angle = angle + 2*pi;
    else
        angle = angle - 2*pi;
    end
end

end

