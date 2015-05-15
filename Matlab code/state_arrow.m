function state_arrow(q, l, fig, color, subinfo)
% STATE_ARROW Computes the start and end point of the state's arrow (to
% give position and orientation) and plots it on given figure.
%
% qa = state_arrow(q, l)
%
% Inputs: - q = state [x, y, theta] in [m] and [rad], theta is the angle
%         with the horizontal axis (x) and is counterclockwise
%         - l = length of the arrow [m]
%         - fig = handle of the figure on which to plot
%         - color = matrix with first line arrow color and second line
%         position color
%         - subinfo = vector with subplot info if there is one
%
% OneTwoSteph, May 2015

% Compute points
qa = [q(1), q(2); q(1)+cos(q(3)), q(2)+sin(q(3))];

% Plot points
set(0,'CurrentFigure', fig);
if (nargin > 4)
    subplot(subinfo(1), subinfo(2), subinfo(3));
    hold on;
    box;
    axis equal;
end
k = plot(qa(:,1), qa(:,2), '-', 'linewidth', 2);
set(k, 'Color', color(1,:));
k = plot(qa(1,1), qa(1,2), 'o', 'linewidth', 2);
set(k, 'Color', color(2,:));

drawnow;

end

