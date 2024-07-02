
clc
f=@(x) (sin(x)+cos(x)).*(cos(x)-2);
g=@(x) exp(2*sin(x));

x=linspace(-pi,pi);

figure(1)
plot(x,f(x),'--g','LineWidth',2)
hold on
plot(x,g(x),'.k','LineWidth',2)
grid on
title('Student ID')                                                        