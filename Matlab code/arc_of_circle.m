function arc_of_circle(q, qe, r, color, fig, subinfo)
% ARC_OF_CIRCLE Drows the arc of circle defined by Canudas

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

