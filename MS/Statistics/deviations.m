clear all;
close all;
clc;
r0=input('Enter r0 value');
r1=input('Enter r1 value');
m=100;
a=arithCongruence(r0,r1,m);
s(1:2)=size(a);
freq=zeros(1,10);
b=0;
for i=1:s(2)
    if a(i)<=18;
        freq(1)=freq(1)+1;
    elseif a(i)<=27
        freq(2) = freq(2)+1;
    elseif a(i) <=36
        freq(3)=freq(3)+1;
    elseif a(i) <= 45
        freq(4)=freq(4)+1;
    elseif a(i) <= 54
        freq(5)=freq(5)+1;
    elseif a(i) <= 63
        freq(6)=freq(6)+1;
    elseif a(i) <= 72
        freq(7)=freq(7)+1;
    elseif a(i) <= 81
        freq(8)=freq(8)+1;
    elseif a(i) <= 90
        freq(9)=freq(9)+1;
    else
        freq(10)=freq(10)+1;
    end
end
cumm_freq=zeros(1,9);
cumm_freq(1)=freq(1);
for i=2:10
    cumm_freq(i)=cumm_freq(i-1)+freq(i);
end
summ=zeros(1,10);
for i=1:10
    summ(i)=(5+(9*i))*freq(i);
end
i=1;
for i=1:10
    fprintf('%d-%d\t%d\t%d\t%d\n',1+9*i,9+9*i,freq(i),cumm_freq(i),summ(i));
end
mean1=sum(summ)/s(2);
med_term=ceil(s(2)/2);
for i=1:10
    if cumm_freq(i)>=med_term
        break;
    end
end
median1=(1+9*i)+(9/freq(i))*(((sum(freq)/2))-cumm_freq(i-1));
lar_freq=max(freq);
for i=1:9
    if freq(i)==lar_freq
        break
    end
end
mode1=5+9*i;
sd=0;
fprintf('The mean is %f and median is %f and mode is %d\n',mean1,median1,mode1);
for i=1:s(2)
    sd=sd+((a(i)-mean1)*(a(i)-mean1));
end
fprintf('Standard deviation is %f and variance is %f\n',sqrt(sd/s(2)),sd/s(2));
