close all;
clear all;
clc;
r0=input('Enter r0 value');
r1=input('Enter r1 value');
m=100;
random_n=arithCongruence(r0,r1,m);
len(1:2) = size(random_n);
freq = zeros(1 , 10);
for i = 1:len(1 , 2);
    if random_n(i) > 0 && random_n(i) <= 10
        freq(1 , 1) = freq(1 , 1) + 1;
    elseif random_n(i) > 10 && random_n(i) <= 20
        freq(1 , 2) = freq(1 , 2) + 1;
    elseif random_n(i) > 20 && random_n(i) <= 30
        freq(1 , 3) = freq(1 , 3) + 1;
    elseif random_n(i) > 30 && random_n(i) <= 40
        freq(1 , 4) = freq(1 , 4) + 1;
    elseif random_n(i) > 40 && random_n(i) <= 50
        freq(1 , 5) = freq(1 , 5) + 1;
    elseif random_n(i) > 50 && random_n(i) <= 60
        freq(1 , 6) = freq(1 , 6) + 1;
    elseif random_n(i) > 60 && random_n(i) <= 70
        freq(1 , 7) = freq(1 , 7) + 1;
    elseif random_n(i) > 70 && random_n(i) <= 80
        freq(1 , 8) = freq(1 , 8) + 1;
    elseif random_n(i) > 80 && random_n(i) <= 90
        freq(1 , 9) = freq(1 , 9) + 1;
    elseif random_n(i) > 90 && random_n(i) <= 100
        freq(1 , 10) = freq(1 , 10) + 1;
    end
end

cf = zeros(1 , 10);
cf(1 , 1) = freq(1 , 1);
for i = 2:10
    cf(1 , i) = cf(1 , i-1) + freq(1 , i); 
end

toDisp = zeros(4,10);
toDisp(1,:) = [0 10 20 30 40 50 60 70 80 90]';
toDisp(2,:) = [10 20 30 40 50 60 70 80 90 100]';
toDisp(3,:) = freq';
toDisp(4,:) = cf';

toDisp'

nHalf=cf(1,10)/2;
for i =1:10
    if(cf(1,i)>=nHalf)
        break;
    end
end

middle=[5 15 25 35 45 55 65 75 85 95]';

for i=1:10
    sum=sum+freq(1,i)*middle(i);
end
mean=sum/cf(1,10);

fprintf('Mean: %d\n',mean);%mean ends here

low=(i-1)*10;
width=10;
frequency=freq(1,i);
cumFrequency=cf(1,i);

md=low + (width/frequency)*(nHalf-cumFrequency); 
fprintf('Median: %d\n',median);%median ends here


disp(md);

