close all
clc

xbar = [mean(x(7:11)) mean(x(17:21)) mean(x(26:30)) mean(x(37:42)) mean(x(47:51)) mean(x(57:62))]; %modify for appropriate cells with recordings above zero
ybar = [mean(y(7:11)) mean(y(17:21)) mean(y(26:30)) mean(y(37:42)) mean(y(47:51)) mean(y(57:62))];
zbar = [mean(z(7:11)) mean(z(17:21)) mean(z(26:30)) mean(z(37:42)) mean(z(47:51)) mean(z(57:62))];

Vxyz = [xbar; ybar; zbar];

Vplus = [Vxyz.^2' Vxyz'];

u = Vplus\[1;1;1;1;1;1];

w = [u(4); u(5); u(6)];

bm = -w./(2*u(1:3)); 

one = w(1)^2 / 4*u(1);
two = w(2)^2 / 4*u(2);
three = w(3)^2 / 4*u(3);

M = [one; two; three];

s = sum(M);

gm = abs(sqrt((1+s)./(4*u(1:3))));
%the bias values are right on par with the nominal value
%from the lab, however the gain values are about double that
%of the nominal values.
%Using more than 6 data points will focus the average Vxyz
%values and make the resulting gain and bias moe accurate. 











