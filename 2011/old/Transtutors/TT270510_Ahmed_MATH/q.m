%Question 3

x=-1:.01:1;
y=x.^2;
z=ones(1,length(x));
plot(x,y);
grid;
axis([-1 1 0 1.2])
hold
plot(x,z,'r')

figure
x=0:.01:4;
y=x.^2+2.*x-4;
z=2.*x;
plot(x,y);
grid;
%axis([-1.1 1.1 0 1.2])
hold
plot(x,z,'r')
