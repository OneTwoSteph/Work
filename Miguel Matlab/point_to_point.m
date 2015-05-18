% POINT_TO_POINT Comparison of spline and pchip interpolation techniques
%
% Miguel Ruiz, commented by Stephanie Amati, April 2015

% Figure
figure
hold on
box

% Points
x = [0 1 2 3 4 5 6 7 8 9 10];
y = [0 2 2 2 4 3 1 1 6 6 6];
plot(x,y,'og')

% Plot Pchip curve
xx = 0:0.1:10;
yy = pchip(x,y,xx);
plot(xx,yy,'vb')

yy = spline(x,y,xx);
plot(xx,yy,'xr')