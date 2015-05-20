function arc_of_circle(q, qe, r, color, fig, subinfo)
% ARC_OF_CIRCLE Drows the arc of circle defined by Canudas between the
% robot and the goal pose.
%
% arc_of_circle(q, qe, r, color, fig, subinfo)
%
% Inputs: - q = robot's pose in [m] and [rad]
%         - qr = goal pose in [m] and [rad]
%         - r = radius of the arc of circle [m]
%         - color = color of the circle indicating if a is positive or
%         negative (a is a variable of the Canudas algorithm)
%         - fig = handle of the figure on which to plot
%         - subinfo = vector with subplot info if there is one
%
% Stephanie Amati, May 201

% Find center of circle
ey = [0;1] + atan(q(3));
ey = ey/norm(ey);
c = q(1:2) - ey*r;

% Construct a circle
angle = linspace(0, 2*pi, 50);
x = c(1)*ones(length(angle), 1) + abs(r)*cos(angle)';
y = c(2)*ones(length(angle), 1) + abs(r)*sin(angle)';

% Draw circle
set(0,'CurrentFigure', fig);
if (nargin > 4)
    subplot(subinfo(1), subinfo(2), subinfo(3));
    hold on;
    box;
    axis equal;
end

k = plot(x, y);
set(k, 'Color', color);

end

