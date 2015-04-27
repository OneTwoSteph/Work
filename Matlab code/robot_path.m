% ROBOT_PATH Calculates a series of points in order to define a path that 
% goes through a series of pre-stablished points.
% The output is in the variable fpath.

%% Cleaning
clear all;
close all;
clc;

%% User's selected points:
x = [1 -1 -1 1 1];
y = [-1 -1 1 1 -1];

%% Parameters and variables
mypath = [0 0];
v = [0 0; x(1) y(1)];       % path
r = 0.2;                    % radius of the arc
dl = 0.1;                   % distance between points

%% Plot the points
figure
hold on
box
axis([min(min(x,y)),max(max(x,y)),min(min(x,y)),max(max(x,y))], 'square')

plot(x,y,'v')

%% Compute path points
% for each point
for i=1:(length(x)-2)
    % compute arc between 3 consecutive points
    [o, p1, p2] = arc(x(i:i+2),y(i:i+2),r);

    % compute angles between center of arc and points
    a = angle(o,p1,2);
    b = angle(o,p2,2);

    % compute points of the new part of path
    da = dl/r;
    if sign(pi-(a-b))<0
        g = a:-sign(b-a)*da:(b+2*pi);
    else
        g = a:sign(b-a)*da:b;
    end
    xx = r*cos(g) + o(1);
    yy = r*sin(g) + o(2);

    % plot
    plot(o(1),o(2),'go')
    plot(p1(1),p1(2),'ro')
    plot(p2(1),p2(2),'ko')
    plot(xx,yy,'c')
    
    v(i*2+1,:) = p1';
    v(i*2+2,:) = p2';

    lp = v(i*2,:);
    d = sqrt((p1(1)-lp(1))^2 + (p1(2)-lp(2))^2);
    ang = angle(lp,p1,2);
    rs = 0:dl:d;
    lin(:,1) = rs*cos(ang);
    lin(:,2) = rs*sin(ang);

    lin(:,1) = lin(:,1) + lp(1);
    lin(:,2) = lin(:,2) + lp(2);
    
    cur = [xx' yy'];
    mypath = [mypath; lin; cur];
    clearvars lin;
end

% Last straight line
    lp = v((i+1)*2,:);
    pf = [x(length(x)) y(length(y))];    
    d = sqrt((pf(1)-lp(1))^2 + (pf(2)-lp(2))^2);
    ang = angle(lp,pf,2);
    rs = 0:dl:d;
    lin(:,1) = rs*cos(ang);
    lin(:,2) = rs*sin(ang);
    lin(:,1) = lin(:,1) + lp(1);
    lin(:,2) = lin(:,2) + lp(2);

% Final path and plotting
fpath = [mypath(2:length(mypath),:); lin; pf];
figure
plot(fpath(:,1),fpath(:,2),'v')
axis([min(min(x,y)),max(max(x,y)),min(min(x,y)),max(max(x,y))], 'square')