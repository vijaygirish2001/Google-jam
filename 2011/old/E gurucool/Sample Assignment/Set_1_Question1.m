%x is the intial value of the function and x1, x2...x5 are the respective
%derivatives, ta is the initial point and and tb is the value at which
%solution is sought, x_val and exact is the final value using Taylor series
clear all
x =exp(1)/(16-exp(1));       %Initial value of x at t=1
x1=x+x^2;              % Value of first derivative of x at t=1
x2=x1+2*x*x1;                 % Value of second derivative of x at t=1
x3=x2+2*x*x2+2*x1^2;          % Value of third derivative of x at t=1
x4=x3+6*x2*x1+2*x*x3;           % Value of fourth derivative of x at t=1
x5=x4+6*x2^2+8*x3*x1+2*x*x4;    % Value of fifth derivative of x at t=1
ta=1;
tb=input('Enter the value t at which solution is required:');
h=input('Enter the step size, h:');
k=(tb-ta)/h;           %No of samples

x_val=x+x1*k*h+x2*((k*h)^2)/2+x3*(k*h)^3/factorial(3)+x4*(k*h)^4/factorial(4)+x5*(k*h)^5/factorial(5);
   

 exact=exp(tb)/(16-exp(tb));
 
 disp(['The final value of x using Taylor series method is ' num2str(x_val)]);
 disp(['The final value of x exact solution is ' num2str(exact)]);
 
 