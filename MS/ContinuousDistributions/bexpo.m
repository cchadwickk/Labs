close all;
clear all;
clc;
mean = input('Enter mean');
x = [.513, .297, .728];
y = zeros(1,3);
for i=1:3
    y(i) = -mean*reallog(x(i));
    z(i) = -mean*reallog(1-x(i));
end
fprintf('Values for ln(r)');
y
fprintf('Values for ln(1-r)');
z