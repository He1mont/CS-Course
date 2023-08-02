
x=linspace(-2,2);
y=exp(x.^3-1);
z=2*x.*y;
w=x.*sin(x)+1;

figure(1)
plot(x,y,'.b',x,z,'--g',x,w,'-k','linewidth',2)
grid on
ylim([0,5])
xlabel('x-axis')
ylabel('y-axis')
title('three curves')