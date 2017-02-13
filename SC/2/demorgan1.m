close all;
clear all;
clc;
x=(0:0.1:10);
A=gaussmf(x, [1 4]);
B=trimf(x, [3 6.5 9]);
ANot=1-A;
BNot=1-B;
AIntB=min(A,B);
subplot(3,1,1);
hold on
plot(x,A,'r');
plot(x,B,'g');
axis([0 10 0 1.05]);
legend('A','B');
subplot(3,1,2);
plot(x,(1-AIntB),'r');
axis([0 10 0 1.05]);
legend('not(A int B)')
subplot(3,1,3);
plot(x,max(ANot,BNot),'r');
axis([0 10 0 1.05]);
legend('not(A) U not(B)')
