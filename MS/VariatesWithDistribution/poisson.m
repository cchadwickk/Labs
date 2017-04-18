clear all;
close all;
clc;
r_var=0;
n=input('Enter the number of variates you want to generate ');
for j=1:n
    lam=rand(1);
    p=zeros(1,20);
    f=1;
    for i=1:20
        p(i)=(power(lam,i-1)*exp(-lam))/factorial(i-1);
    end
    cum_p=zeros(1,20);
    cum_p(1)=p(1);
    for i=2:20
        cum_p(i)=cum_p(i-1)+p(i);
    end
    r=rand(1,1);
    for i=1:20
        if (cum_p(i) >=r)
            break
        end
    end
    r_var=[r_var i-1];
end
r_var(2:end)