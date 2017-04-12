close all;
clear all;
clc;
s = [1 -1 -1 -1 ; 1 1 -1 -1 ; -1 -1 -1 1 ; -1 -1 1 1];
t = [-1 1 ; -1 1 ; 1 -1 ; 1 -1];
s = s';
weight = s*t
input = input('Enter input : ');
res = input * weight;
for i = 1:2
    if res(i) > 1
        res(i) = 1;
    elseif res(i) < -1
        res(i) = -1;
    end
end
flag = 0;
for i = 1:4
    if res(1) == t(i , 1) && res(2) == t(i , 2)
        flag = 1;
        break;
    end
end    
if flag == 1
    disp('Match found');
else 
    disp('No match found');
end
