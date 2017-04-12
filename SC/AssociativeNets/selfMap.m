clear all;
close all;
clc;
x=[0 0 1 1;1 0 0 0;0 1 1 0;0 0 0 1];
lRate=input('Enter learning rate ');
wt = [.2 .9;.4 .7;.6 .5;.8 .3];
c=1;
for j=1:4
    w1=0;w2=0;
    for i=1:4
        w1 = w1+((x(j,i)-wt(i,1))*(x(j,i)-wt(i,1)));
        w2 = w2+((x(j,i)-wt(i,2))*(x(j,i)-wt(i,2)));
    end
    wnew=0;
    if w1 < w2
        cluster(c)=1;
        n=1;
    else
        cluster(c)=2;
        n=2;
    end
    for i=1:4
        wnew = [wnew wt(i,n)+lRate*(x(j,i)-wt(i,n))];
    end
    wt(:,n)=wnew(2:end);
    c=c+1;
end
disp(cluster);
