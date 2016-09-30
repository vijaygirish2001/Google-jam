%x is the value of the function, which initially is equal to 2 at t=ta=1,t is the variable, h is the step size, k1 is the slope at the beginning
%of the interval,
% f(t,x) is a function defining the first derivative of x
%k2 is the slope at the midpoint of the interval, using slope k1 to determine the value of y at the point t+ h / 2 using Euler's method;
% k3 is again the slope at the midpoint, but now using the slope k2 to determine the y-value;
% k4 is the slope at the end of the interval, with its y-value determined using k3

x=2;               %Initial value of function x
ta=1;
t=ta;
tb=input('Enter the value t at which solution is required:');
n=input('Enter the no of steps:');
h=(tb-t)/n;    %Step size for calculation
    for j=1:n       %Implementing Runga Kutta Method
    k1=h*f(t,x);
    k2=h*f(t+h/2,x+k1/2);
    k3=h*f(t+h/2,x+k2/2);
    k4=h*f(t+h,x+k3/2);
    x=x+1/6*(k1+2*k2+2*k3+k4);
    t=ta+j*h;
    end
disp(['The final step value is ' num2str(j)]);
disp(['The final value of t is ' num2str(t)]);
disp(['The final value of x is ' num2str(x)]);