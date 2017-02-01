close all;
clear all;
clc;
x=(0:0.1:10);
paramg=[1 4];
paramt=[3 6.5 9]
A=gaussmf(x, paramg);
B=trimf(x, paramt);
ANot=1-A;
BNot=1-B;
AUniB=max(A,B);
subplot(3,1,1);
hold on
plot(x,A,'r');
plot(x,B,'g');
axis([0 10 0 1.05]);
legend('A','B');
subplot(3,1,2);
plot(x,(1-AUniB),'r');
axis([0 10 0 1.05]);
legend('not(AUB)')
subplot(3,1,3);
plot(x,min(ANot,BNot),'r');
axis([0 10 0 1.05]);
legend('not(A)? not(B)')