close all;
x=(0:0.1:10);
m1=gaussmf(x,[1 4]);
m2=trimf(x,[3 6.5 9]);
m_union=min(m1,m2);
hold on
subplot(2,1,1)
plot(x,m1,'r')
hold on
plot(x,m2,'m')
hold off
axis([0 10 0 1.05]);
legend('A','B');
title('Fuzzy set A & B')
subplot(2,1,2);
plot(x, m_union)
