close all;
clear all;
clc;
lower = input('Enter lower limit');
upper = input('Enter upper limit');
r(1:10)=[.396,.582,.556, .468, .940, .382, .011, .525, .117, .579];
x=zeros(1,10);
for i=1:10
    x(i) = lower + ((upper-lower) * r(i));
end
x