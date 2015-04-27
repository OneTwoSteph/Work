function [ang] = angle(p1, p2, option)
% ANGLE Calculate the angle between the origin's x axis and a vector or
% or the origin's axis and the vector p2-p1 (the vector joining the two
% points).

%% Compute angle in function of option
if option == 1
    % Angle
    ang = acos(p1(1)/sqrt(p1(1)^2 + p1(2)^2));
    
    % Check that angle represents counterclockwise angle
    if sign(p1(2)) < 0 
        ang = 2*pi - ang; 
    end
elseif option == 2
    % Angle
    ang = acos((p2(1)-p1(1)) / sqrt((p2(1)-p1(1))^2 + (p2(2)-p1(2))^2));
    
    % Check that angle represents counterclockwise angle 
    if sign(p2(2)-p1(2)) < 0 ang = 2*pi - ang; end
end

%% Plot
% figure
% plot([p1(1) p2(1)],[p1(2) p2(2)]);
% hold
% plot(p1(1),p1(2),'rv');
% plot(p2(1),p2(2),'rv');

end