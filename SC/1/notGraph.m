close all;
x=(0:0.1:10);
m1=gaussmf(x,[1 4]);
m_not=1-m1;
hold on
subplot(2,1,1)
plot(x,m1,'r')
hold off
axis([0 10 0 1.05]);
legend('A');
title('Fuzzy set A')
subplot(2,1,2);
plot(x, m_not,'m')
axis([0 10 0 1.05]);
legend('!A');
