clear all;
close all;
clc;

p=input('Enter probability ');
ran_var=input('Enter the number of random number per variate ');
n_var=input('Enter the number of variates ');
x=rand(1,ran_var*n_var);
xi=zeros(1,n_var);
j=1;n=1;

for i=1:ran_var*n_var
    if x(i)<=p
        xi(j)=xi(j)+1;
    end
    n=n+1;
    if n>ran_var        %change counter to next row
        j=j+1;
        n=1;
    end
end

var=0;
mean1=sum(xi)/n_var;    %calculate mean

for i=1:n_var           
    var=var+((xi(i)-mean1)*(xi(i)-mean1));
end

fprintf('The mean is %f and variance is %f\n',mean1,var);