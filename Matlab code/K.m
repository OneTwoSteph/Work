function K

e = -10:0.1:10;

% % a
% figure
% hold
% for i = 1:0.5:5
% u_max = 1;
% a = 0.001*10^i;
% 
% k = (u_max * (1-exp(-a.*e.^2))) ./ abs(e);
% plot(e, k.*e)
% end
% k = (u_max * (1-exp(-0.01.*e.^2))) ./ abs(e);
% plot(e, k.*e,'r')
% 
% % u_max
% figure
% hold
% for i = 1:1:10
% u_max = i;
% a = 1;
% 
% k = (u_max * (1-exp(-a.*e.^2))) ./ abs(e);
% plot(e, u_min + k.*e)
% end
% k = (1 * (1-exp(-a.*e.^2))) ./ abs(e);
% plot(e, k.*e,'g')

% Final
figure
k = 1./exp(abs(e)) + (10 * (1-exp(-0.1.*e.^2))) ./ abs(e);
plot(e, k, 'k')
hold
plot(e, k.*e)