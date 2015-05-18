function [o, a1, b3] = arc(x,y,r)
% ARC Calculates the starting and ending points of an arc tangent to two
% lines (defined by three points) with radius r.
%
% Miguel Ruiz, commented by Stephanie Amati, April 2015

% Define de points
p1 = [x(1); y(1)];
p2 = [x(2); y(2)];
p3 = [x(3); y(3)];

% Compute the unit vectors defining the lines
A = p1 - p2;
B = p3 - p2;
An = A / norm(A);
Bn = B / norm(B);

% Compute the angle between the lines
theta = acos(An(1)*Bn(1) + An(2)*Bn(2));

% Compute line going through the points of contact of the circle on the
% givent line and the center of the circle
% This is done by finding the points of contact of the circles on the two
% lines, by finding two other points lying on the lines going through the
% center of the cercle, constructing two new lines with it
l = r/tan(theta/2);
Al = l*An; 
Bl = l*Bn;
rotc = [0 1; -1 0];
rotcc = [0 -1; 1 0];

a1 = Al + p2; 
x1 = a1(1); 
y1 = a1(2);

a2 = rotc*Al + Al + p2; 
x2 = a2(1); 
y2 = a2(2);

b3 = Bl + p2; 
x3 = b3(1); 
y3 = b3(2);

b4 = rotcc*Bl + Bl + p2; 
x4 = b4(1); 
y4 = b4(2);

% Compute center of the circle (intersection of the two new lines)
o = [((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4)) / ((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));
    ((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4)) / ((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4))];

% Plot
figure
hold on
axis equal
box

plot([p2(1), x1], [p2(2), y1], 'b');
plot([p2(1), x3], [p2(2), y3], 'b');
plot(a1(1),a1(2),'ro')
plot(a2(1),a2(2),'ko')
plot(b3(1),b3(2),'ro')
plot(b4(1),b4(2),'ko')
plot(o(1),o(2),'go')

xx = -r:0.01:r;
yy = sqrt(r^2-xx.^2);
plot(xx + o(1),yy + o(2),'c')
plot(xx + o(1),-yy + o(2),'c')

end